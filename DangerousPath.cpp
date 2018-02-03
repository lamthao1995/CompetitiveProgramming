#define ll long long
#define N 150000
#define pb push_back
#include<bits/stdc++.h>
#define vi vector<int>
#define root 0
#define LOGN 20
#define MOD (int)(1e9+7)
using namespace std;
vi adj[N];
int chainNo, chainHead[N], chainId[N];
int ptr, posBase[N], pa[LOGN][N], arr[N];
int subsize[N], depth[N], st[8 * N], qt[8 * N], cost[N];
int n, m, a, b, x, y, q;
void build(int cur, int s, int e){
	if(s == e) return void(st[cur] = arr[s]);
	int c1 = cur << 1, c2 = c1 | 1, mid = (s + e) >> 1;
	build(c1, s, mid); build(c2, mid + 1, e);
	st[cur] = st[c1] + st[c2];
}
void queryTree(int s, int e, int S, int E, int cur){
	if(s > E || e < S) return void(qt[cur] = 0);
	if(s >= S && e <= E) return void(qt[cur] = st[cur]);
	int c1 = cur << 1, c2 = c1 | 1, mid = (s + e) >> 1;
	queryTree(s, mid, S, E, c1); queryTree(mid + 1, e, S, E, c2);
	qt[cur] = qt[c1] + qt[c2]; 
}
int queryUp(int u, int v){
	int uchain, vchain = chainId[v];
	int ans = 0;
	while(1){
		uchain = chainId[u];
		if(uchain == vchain){
			queryTree(1, ptr, posBase[vchain], posBase[uchain], 1);
			ans += qt[1];
			break;
		} 
		queryTree(1, ptr, posBase[chainHead[uchain]], posBase[uchain], 1);
		ans += qt[1];
		u = chainHead[uchain];
		u = pa[0][u];
	}
	return ans;
}
int LCA(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	for(int i = 0; i < LOGN; i++) if((diff >> i) & 1){
		u = pa[i][u];
	}
	if(u == v) return u;
	for(int i = LOGN - 1; i >= 0; i--) if(pa[i][u] != pa[i][v]){
		u = pa[i][u]; v = pa[i][v];
	}
	return pa[0][u];
}
void HLD(int cur, int prev = -1){
	if(chainHead[chainNo] == -1) chainHead[chainNo] = cur;
	chainId[cur] = chainNo;
	posBase[ptr] = cur;
	arr[ptr++] = cost[cur];
	int spe = -1;
	for(int v : adj[cur]) if(v != prev){
		if(spe == -1 || subsize[spe] < subsize[v]){
			spe = cur;
		}
	}
	if(spe != -1) HLD(spe, cur);
	for(int v : adj[cur]) if(v != prev && v != spe){
		chainNo++;
		HLD(v, cur);
	}
}
void dfs(int cur, int depth_ = 0, int prev = -1){
	subsize[cur] = 1; depth[cur] = depth_; pa[0][cur] = prev;
	for(int v : adj[cur]) if(v != prev){
		dfs(v, depth_ + 1, cur);
		subsize[cur] += subsize[v];
	}
}
void init(){
	ptr = chainNo = 0;
	for(int i = 0; i < n; i++){
		chainHead[i] = -1;
		adj[i].clear();
		for(int j = 0; j < LOGN; j++) pa[j][i] = -1;
	}
	for(int i = 1; i < LOGN; i++){
		for(int j = 0; j < n; j++){
			if(pa[i - 1][j] != -1) pa[i][j] = pa[pa[i - 1][j]][j - 1];
		}
	}
}
void answer(int a, int b){
	int lca = LCA(a, b);
	int numGang = queryUp(a, lca) + queryTree(b, lca);
	int numCity = depth[a] + depth[b] - 2 * depth[lca] + 1;
	if(a == lca || b == lca) numCity--;
	if(numCity / 2 < numGang){
		cout << ""
	}
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> cost[i];
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b; a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	init();
	dfs(root);
	HLD(root);
	build(1, 0, ptr - 1);
	while(m--){
		cin >> a >> b; 
		answer(a - 1, b - 1);
	}
}
int main(void){
	
	
	return 0;
}
