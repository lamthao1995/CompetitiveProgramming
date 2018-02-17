#define ll long long
#define pb push_back
#define INF 1000000000
#include<bits/stdc++.h>
#define vi vector<int>
#define N 500000
using namespace std;
ll tree[4 * N], qt[4 * N], lazy[4 * N];
vi adj[N];
int tout[N], tin[N], t;
int c[N],x,y ,m, n;
ll val;
void dfs(int u, int prev = -1){
	tin[u] = t++;
	for(int v : adj[u]) if(v != prev){
		dfs(v, u);
	}
	tout[u] = t;
}
void buildTree(int l, int r, int cur){
	if(l >= r) return;
	if(l == r - 1){
		tree[cur] = (1ll << c[l]);
		return;
	}
	int c1 = cur << 1, c2 = c1 | 1, mid = (l + r) / 2;
	buildTree(l, mid, c1); buildTree(mid, r, c2);
	tree[cur] = (tree[c1] | tree[c2]);
}
void push(int node){
	if(lazy[node] != 0ll){
		for(int i = 1; i <= 2; i++){
			lazy[node * 2 + i] = tree[node * 2 + i] = lazy[node];
		}
		lazy[node] = 0ll;
	}
}
void update(int l, int r, int s, int e, int cur, int idx){
	if(r <= s || l >= e) return;
	if(l <= s && e <= r){
		tree[cur] = lazy[cur] = 1ll << c[idx];
		return;
	}
	push(cur);
	int c1 = cur << 1, c2 = c1 | 1, mid = (s + e) >> 1;
	update(l, r, s, mid, c1, idx);
	update(l, r, mid, e, c2, idx);
	tree[cur] = tree[c1] | tree[c2];
}
void query(int l, int r, int s, int e, int cur){
	if(r <= s || l >= e) return;
	if(l <= s && e <= r) return void(val |= tree[cur]);
	push(cur);
	int c1 = cur << 1, c2 = c1 | 1, mid = (s + e) >> 1;
	query(l, r, s, mid, c1), query(l, r, mid, e, cur);
}
void solve(){
	t = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	for(int i = 1; i < n; i++){
		cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
	}
	dfs(1);
	assert(t == n + 1);
	n++;
	for(int i = 1; i <= n; i++) update(tin[i], tin[i] + 1, 1, n, 1, i);
	int type;
	while(m--){
		cin >> type;
		if(type == 1){
			cin >> x >> y;
			c[x] = y;
			update(tin[x], tout[x],1, n, 1, x);
		}else{
			cin >> x;
			val = 0ll;
			query(tin[x], tout[x],1, n, 1);
			
			int ans = 0;
			//cout << val << " ";
			while(val != 0ll){
				ans += (val & 1); 
				val >>= 1;
			}
			cout << ans << endl;
		}
	}
}
int main(void){
	solve();
	return 0;
}

