#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
set<int> mp;
int n, k;
string s;
void solve(){
	mp.clear();
	cin >> k >> s;
	n = s.size();
	mp.insert(0);
	int sum = 0, ans = 0;
	for(int i = 0; i < n; i++){
		sum += s[i] - 'a' + 1;
		int val = sum - k;
		if(mp.count(val)){
			ans++;
		}
		mp.insert(sum);
	}
	cout << ans << endl;
}
int main(void){
	int t; cin >> t;
	while(t--) solve();
}
