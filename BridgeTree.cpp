#define vi vector<int>
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define mp(a,b) make_pair(a,b)
const int N = 150000;
const int LOGN = 20;
#include<bits/stdc++.h>
using namespace std;
int n, m, q, a, b, c, d;
int pa[LOGN][N];
vector<pi> adj[N];
vi tree[N];
queue<int> Q[N];
int comp[N], start[N], finish[N];
bool isBridge[N];
int dtime[N], low[N], _time = 0, parent[N], cmpno = 0, depth[N];
bool used[N];
void findBridge(int u){
	used[u] = 1;
	dtime[u] = low[u] = ++_time;
	for(auto p : adj[u]){
		int id = p.first;
		int v = p.second;
		if(parent[u] == v) continue;
		if(!used[v]){
			parent[v] = u;
			findBridge(v);
			low[u] = min(low[u], low[v]);
			if(low[v] > dtime[u]){
				isBridge[id] = true;
			}
		}else low[u] = min(low[u], dtime[v]);
	}
}
void treeBridge(int v){
	int cur = cmpno;
//	comp[v] = cur;
	used[v] = 1;
	Q[cur].push(v);
	while(Q[cur].size()){
		int u = Q[cur].front(); Q[cur].pop();
		comp[u] = cur;
		for(auto p : adj[u]){
			int id = p.first, w = p.second;
			if(used[w]) continue;
			if(isBridge[id]){
				cmpno++;
				tree[cur].pb(cmpno);
				tree[cmpno].pb(cur);
				treeBridge(w);
			}else{
				Q[cur].push(w);
				used[w] = 1;
			}
		}
	}
}
bool isAncestor(int u, int a){
	if(u == a) return true;
	if(start[u] < start[a] && finish[a] < finish[u]) return true;
	return false;
}
void dfs(int u, int prev = -1, int depth_ = 0){
	start[u] = ++_time;
	depth[u] = depth_; pa[0][u] = prev;
	for(int v : tree[u]) if(v != prev){
		dfs(v, u, depth_ + 1);
	}
	finish[u] = ++_time;
}
int LCA(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	for(int i = 0; i < LOGN; i++) if((diff >> i) & 1){
		u = pa[i][u];
	}
	if(u == v) return u;
	for(int i = LOGN - 1; i >= 0; i--) if(pa[i][u] != pa[i][v]){
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}
int getDist(int a, int b){
	return depth[a] + depth[b] - 2 * depth[LCA(a, b)];
}
pi getIntersection(int u, int a, int v, int b){
	if(!isAncestor(v, a)) return mp(0,0);
	int x = LCA(a, b);
	if(depth[v] < depth[u]){
		if(isAncestor(u, x)) return mp(u,x);
	}else{
		if(isAncestor(v, x)) return mp(v, x);
	}
	return mp(0,0);
}
void answer(int a, int b, int c, int d){
	int u = LCA(a, b), v = LCA(c, d);
	int ret = getDist(a, b);
	pi X;
	X = getIntersection(u,a,v,c); ret -= getDist(X.first, X.second);
	X = getIntersection(u,a,v,d); ret -= getDist(X.first, X.second);
	X = getIntersection(u,b,v,c); ret -= getDist(X.first, X.second);
	X = getIntersection(u,b,v,d); ret -= getDist(X.first, X.second);
	cout << ret << endl;
}
void checkBridge(){
	cout << "Cac id la bridge: " << endl;
	for(int i = 1; i <= m; i++){
		if(isBridge[i]) cout << i << " ";
	}
	cout << endl;
	for(int i = 1; i <= n; i++){
		cout << "canh " << i << " nam trong tap: " << comp[i] << endl;
	}
	cout << "so tap: " << cmpno << endl;
}
void solve(){
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++){
		used[i] = isBridge[i] = false;
		adj[i].clear(); tree[i].clear();
		parent[i] = -1; 
		comp[i] = dtime[i] = low[i] = start[i] = finish[i] = depth[i] = 0;
		for(int j = 0; j < LOGN; j++) pa[j][i] = -1;
	}
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		adj[a].pb(mp(i, b)); adj[b].pb(mp(i, a));
	}
	findBridge(1);
	for(int i = 1; i <= n; i++) used[i] = false;
	treeBridge(1);
	//checkBridge();
	_time = 0;
	dfs(0);
	for(int i = 1; i < LOGN; i++){
		for(int j = 0; j <= cmpno; j++){
			if(pa[i - 1][j] != -1) pa[i][j] = pa[i - 1][pa[i - 1][j]];
		}
	}
	while(q--){
		cin >> a >> b >> c >> d;
		answer(comp[c], comp[d], comp[a], comp[b]);
	}
}
int main(void){
	solve();
	return 0;
}
