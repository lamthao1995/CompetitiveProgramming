#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define vpi vector<pair<int,int>>
using namespace std;
const int N = 1000000;
int n, x;
int a[N];
map< int, vector< pair< int, int> > > mp;
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n - 1; i++){
		int diff = a[i + 1] - a[i];
		if(mp.find(diff) == mp.end()){
			vpi v;
			mp[diff] = v;
		}
		mp[diff].push_back(mp(a[i], a[i + 1]));
	}
	int minKey = mp.begin()->first;
	vpi& v = mp[minKey];
	vector<int> rs;
	for(int i = 0; i < v.size(); i++){
		rs.push_back(v[i].first);
		rs.push_back(v[i].second);
	}
	sort(rs.begin(), rs.end());
	for(int i = 0; i < rs.size(); i++){
		cout << rs[i] << " ";
	}
}
int main(){
	solve();
	return 0;
}
