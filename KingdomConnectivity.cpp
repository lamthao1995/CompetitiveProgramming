#define ll long long int
#define pb push_back
#define MOD (int)(1e9)
#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
#define N 100000
int m, n;
int src, dest, vis[N], dp[N];
bool reachable[N];
vi edge[N], re[N];
void dfs(int u, vi g[]){
	vis[u] = 1;
	for(int v : g[u]){
		if(vis[v] == 0){
			dfs(v, g);
		}else if(vis[v] == 1){
			reachable[v] = true;//contains circle
		}
	}
	vis[u] = 2;
}
void dfs1(int u, vi g[]){
	vis[u] = 1;
	for(int v : g[u]){
		if(vis[v] == 0) dfs1(v, g);
	}
	vis[u] = 2;
}
bool checkCycle(){
	dfs(src, edge);
	memset(vis, 0, sizeof vis);
	dfs1(dest, re);
	for(int i = 1; i <= n; i++){
		if(reachable[i] && vis[i] == 2) return 1;
	}
	return 0;
}
ll cal(int u){
	if(reachable[u]) return 0;
	if(u == dest) return 1ll;
	if(dp[u] != -1) return dp[u];
	ll ret = 0;
	for(int v : edge[u]){
		ret = (ret + cal(v)) % MOD;
	}
	return dp[u] = ret;
}
void solve(){
	int i,j,u,v;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		edge[u].pb(v); re[v].pb(u);
	}
	src = 1; dest = n;
	memset(dp, -1, sizeof dp);
	if(checkCycle()) cout << "INFINITE PATHS\n" << endl;
	else cout << cal(src) << endl;
}
int main(void){
	solve();
	return 0;
}
