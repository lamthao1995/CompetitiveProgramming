#define ll long long
#define pb push_back
#define N 300000
#define mp(a,b) make_pair(a,b)
#define pi pair<int,int>
#include<bits/stdc++.h>
using namespace std;
int n, m,a ,b, tt, cc=0;
set<pi> ss;
set<int> used;
void dfs(int u){
	if(u > n) return;
	used.erase(u);
	cc++;
	int y = 0;
	while(y < n){
		auto it = used.upper_bound(y);
		y = *it;
		if(!ss.count(mp(u, y))) dfs(y);
	}
}
void solve(){
	cin >> n >> m;
	tt = n * (n - 1) / 2;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		ss.insert(mp(a,b)); ss.insert(mp(b,a));
	}
	vector<int> v;
	for(int i = 1; i <= n + 1; i++) used.insert(i);
	for(int i = 1; i <= n; i++){
		if(used.count(i)){
			cc = 0;
			dfs(i);
			v.pb(cc);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for(auto ii : v) cout << ii << " ";
	
}
int main(void){
	solve();
	return 0;
}
