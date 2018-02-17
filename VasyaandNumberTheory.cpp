#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
const int N = 300000;
int n, a[N], dp[2000][2000];
int go(int idx, int prev){
	if(idx == n + 1) return 0;
	if(dp[idx][prev] != -1) return dp[idx][prev];
	int ret = 0;
	ret = max(ret, go(idx + 1, prev));
	if(prev == 0 or a[idx] % a[prev] == 0){
		ret = max(ret, 1 + go(idx + 1, idx));
	}
	return dp[idx][prev] = ret;
}
void solve(){
	memset(dp, -1, sizeof dp);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int ans = go(1, 0);
	if(ans < 2) ans = -1;
	cout << ans << endl;
	
}
int main(void){
	solve();
	return 0;	
}
