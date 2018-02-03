#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mp(a,b) make_pair(a,b)
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
const int INF = 1e9;
const int LOGN = 23;
set<int> G[N];
int dp[LOGN][N], par[N], sub[N], level[N], ans[N];
int n, m;
void dfs0(int u){
	for(auto it = G[u].begin(); it != G[u].end(); it++){
		if(*it != dp[0][u]){
			dp[0][*it] = u;
			level[*it] = level[u] + 1;
			dfs0(*it);
		}
	}
}
void preprocess(){
	level[0] = 0;
	dp[0][0] = 0;
	dfs0(0);
	for(int i = 1; i < LOGN; i++){
		for(int j = 0; j < n; j++){
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
}
int LCA(int u, int v){
	if(level[u] < level[v]) swap(u, v);
	int diff = level[u] - level[v];
	for(int i = 0; i < LOGN; i++) if((diff >> i) & 1){
		u = dp[i][u];
	}
	if(u == v) return v;
	for(int i = LOGN - 1; i >= 0; i--) if(dp[i][u] != dp[i][v]){
		v = dp[i][v]; u = dp[i][u];
	}
	return dp[0][u];
}
int dist(int u, int v){
	return level[u] + level[v] - level[LCA(u,v)] * 2;
}
//decomposition part
int nn;
void dfs1(int u, int p){
	sub[u] = 1;
	nn++;
	for(auto it = G[u].begin(); it != G[u].end(); it++){
		if(*it != p) dfs1(*it, u), sub[u] += sub[*it];  
	}
}
int dfs2(int u, int p){
	for(auto it = G[u].begin(); it != G[u].end(); it++){
		if(*it != p && sub[*it] > nn/2) return dfs2(*it, u);
	}
	return u;
}
void decompose(int root, int p){
	nn = 0;
	dfs1(root, root);
	int centroid = dfs2(root, root);
	if(p == -1) p = centroid;
	par[centroid] = p;
	for(auto it = G[centroid].begin(); it != G[centroid].end(); it++){
		G[*it].erase(centroid);
		decompose(*it, centroid);
	}
	G[centroid].clear();
}
// query
void update(int u){
	int x = u;
	while(1){
		ans[x] = min(ans[x], dist(x, u));
		if(x == par[x]) break;
		x = par[x];
	}
}
int query(int u){
	int x = u;
	int ret = INF;
	while(1){
		ret = min(ret, dist(u,x) + ans[x]);
		if(x == par[x]) break;
		x = par[x];
	}
	return ret;
}
int main(){
	int u,v,t;
	cin >> n >> m;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v;
		G[u - 1].insert(v - 1); G[v - 1].insert(u - 1); 
	}
	preprocess();
	decompose(0,-1);
	for(int i = 0; i < n; i++) ans[i] = INF;
	update(0);
	while(m--){
		cin >> t >> v; v--;
		if(t==1){
			update(v);
		}else cout << query(v) << endl;
	}
	return 0;
}
