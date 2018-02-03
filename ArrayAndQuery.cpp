#define ll long long
#include<bits/stdc++.h>
#define MOD (int)(1e9 + 7)
#define N 1000000
using namespace std;
int n, arr[N], q, id, val;
unordered_map<int, int> mp1, mp2;
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i], mp1[arr[i]]++, mp2[arr[i]]++;
	int num = 0;
	for(int i = 1; i <= n; i++){
		if(mp1[arr[i]] <= 0) continue;
		int start = arr[i] + 1;
		mp1[arr[i]]--;
		while(mp1[start] > 0) mp1[start++]--;
		start = arr[i] - 1;
		while(mp1[start] > 0) mp1[start--]--;
		num++;
	}
	cin >> q;
	int i = 1;
	ll ans = 0;
	while(q--){
		cin >> id >> val;
		int old = arr[id];
		if(mp2[old] <= mp2[old + 1] && mp2[old] <= mp2[old - 1]) num++;
		else if(mp2[old] > mp2[old - 1] && mp2[old] > mp2[old + 1]) num--;
		mp2[old]--;
		arr[id] = val;
		mp2[val]++;
		if(mp2[val] <= mp2[val + 1] && mp2[val] <= mp2[val - 1]) num--;
		else if(mp2[val] > mp2[val - 1] && mp2[val] > mp2[val + 1]) num++;
		ans = (1ll * i * num + ans) % MOD;
		i++;
	}
	cout << ans << endl;
}
int main(){
	solve();
}
