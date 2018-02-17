#define ll long long
#define N 100000
#define M 500
#define root 1
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
int cost[M][M], res[N];
bool link[M][M];
int n,m, r, c, w, time_ = 0;
vector<int> adj[N];
void dfs(int u, int prev_ = 0){
	res[++time_] = u;
	for(int v : adj[u])if(v != prev_){
		dfs(v, u);
	}
	res[time_] = u;
}
bool ok(int start){
	if(time_ != m + 1) return false;
	int sum = 0;
	for(int i = 2; i < start; i++) sum += 
}
void solve(){
	memset(link, -1, sizeof link);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> r >> c >> w;
		cost[r][c] = w;
		adj[r].pb(c); adj[c].pb(r);
	}
	dfs(root);
}
