#define ll long long
#define pb push_back
#define N 400000
#define ms(a,b) memset(a, b, sizeof a)
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[N];
ll a[N], p[N], par[N];
bool used[N];
int n, m;
bool kuhn(int x){
	used[x] = 1;
	for(auto v : adj[x]){
		if(!par[v]){
			par[v] = x;
			return 1;
		}
		if(used[par[v]]) continue;
		if(kuhn(par[v])){
			par[v] = x;
			return 1;
		}
	}
	return 0;
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> p[i];
	}
	for(int j = 1; j <= m; j++){
		ll x, y; cin >> x >> y;
		for(int i = 1; i <= n; i++){
			if(x > a[i] && y <= p[i]){
				adj[i].pb(n + 1 + j);
				adj[n + 1 + j].pb(i);
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ms(used, 0);
		if(kuhn(i)) ans++;
	}
	cout << ans;
}
int main(){
	solve();
	return 0;
}
