#define ll long long int
#define pb push_back
#include<bits/stdc++.h>
const int N = 400000;
using namespace std;
ll popu[N], locateCity[N], locateCloud[N], range[N], comp[N];
int n, m, k = 0, cc = 1;
map<int,int> mp;
ll rev[N];
ll _bit[2 * N];
unordered_map<ll, ll> mp1;
ll query(int idx){
	ll sum = 0;
	while(idx > 0){
		if(_bit[idx] > 0) sum += mp1[rev[idx]], _bit[idx] = 0;
		idx -= idx & -idx;
	}
	return sum;
}
void update(int idx, int val = 1){
	while(idx < cc){
		_bit[idx] += val;
		idx += idx & -idx;
	}
}
void solve(){
	cin >> n;
	ll total = 0;
	for(int i = 1; i <= n; i++) cin >> popu[i], total += popu[i];
	for(int i = 1; i <= n; i++){
		cin >> locateCity[i]; 
		mp[locateCity[i]];
		mp1[locateCity[i]] += popu[i];
	}
	cin >> m;
	for(int i = 1; i <= m; i++) cin >> locateCloud[i];
	for(int i = 1; i <= m; i++){
		cin >> range[i];
		comp[k++] = range[i] - locateCloud[i];
		mp[comp[k-1]];
		comp[k++] =  range[i] + locateCloud[i];
		mp[comp[k-1]];
	}
	for(auto it = mp.begin(); it != mp.end(); it++){
		mp[it->first] = cc;
		rev[cc] = it->first;
		cc++;
	} 
	for(int i = 1; i <= n; i++){
		update(mp[locateCity[i]]);
	}
	ll maxSum = 0;
	for(int i = 1; i <= m; i++){
		ll rs = query(mp[locateCloud[i] + range[i]]) - query(mp[locateCloud[i] - range[i]] - 1);
		total -= rs;
		maxSum = max(rs, maxSum);
	}
	cout << total + maxSum << endl;
	
}
int main(){
	solve();
	return 0;
}
