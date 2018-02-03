#define ll long long
#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
int mt[1001][1001], n, m;
string s, prev_;
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		if(i == 0) prev_ = s;
		mp[s] = i;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> m; mt[i][j] = m;
		}
	}
	ll ans = 0;
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> s;
		ans += mt[mp[prev_]][mp[s]];
		prev_ = s;
	}
	cout << ans << endl;
}
int main(){
	solve();
	return 0;
}
