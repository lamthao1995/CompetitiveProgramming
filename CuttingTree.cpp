#define ll long long
#define pb push_back
#define INF (int)(1e9)
#include<bits/stdc++.h>
using namespace std;
#define N 200000
vector<int> adj[N];
int m, n, val[N], x,y, sum, ans;
int dfs2(int u, int prev = 0){
	int sumOfSubtree = val[u];
	for(int v : adj[u]) if(prev != v){
		sumOfSubtree += dfs2(v, u);
	}
	ans = min(ans, abs(sum - 2 * sumOfSubtree));
	return sumOfSubtree;
}
void dfs1(int u, int prev = 0){
	sum += val[u];
	for(int v : adj[u]) if(v != prev){
		dfs1(v, u);
	}
}
void solve(){
	cin >> n;
	sum = 0;
	ans = INF;
	for(int i = 1; i <= n; i++){
		cin >> val[i];
	}
	for(int i = 1; i < n; i++){
		cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
	}
	dfs1(1);
	dfs2(1);
	cout << ans << endl;
}
int main(){
	solve();
}
