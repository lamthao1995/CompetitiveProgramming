#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
char s[100100];
int dp[100100];
map<int, int> mp;
int max(int x, int y){
	return x > y ? x : y;
}
int main(){
	int n;
	mp.clear();
	cin >> n;
	cin >> s;
	int maxOne = 0;
	for(int i = 0; i <= n; i++) dp[i] = 0;
	for(int i = 1; i <= n; i++){
		if(s[i - 1] == '1'){
			dp[i] = dp[i - 1] + 1;
		}else{
			dp[i] = dp[i - 1] - 1;
		}
		if(!mp[dp[i]]){
			mp[dp[i]] = i;
		}
		//cout << dp[i] << " ";
	}
	int ans = 0;
	mp[0] = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, i - mp[dp[i]]);
	}
	cout << ans << endl;
	return 0;
}
