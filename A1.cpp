#include<bits/stdc++.h>
#define MAX 1e18
#define ll long long
using namespace std;
int min(int x, int y){
	return x < y ? x : y;
}
int main(void){
	int n, k;
	cin >> n >> k;
	int prices[n];
	int days[k];
	int totalDay = 0;
	for(int i = 0; i < n; i++) cin >> prices[i];
	for(int i = 0; i < k; i++) {
		cin >> days[i];
		totalDay += days[i];
	}
	if(totalDay > n){
		cout << -1 << endl;
		return 0;
	}
	ll dp[n + 1][k + 1];
	ll sum[n + 1];
	for(int i = 0; i <= n; i++) sum[i] = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= k; j++){
			if(j != 0) dp[i][j] = MAX;
			else dp[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + prices[i - 1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			dp[i][j] = dp[i - 1][j];
			if(i < days[j - 1]) continue;
			int ss = i - days[j - 1], ee = i;
			ll price = sum[ee] - sum[ss];
			dp[i][j] = min(dp[i - days[j - 1]][j - 1] + price, dp[i][j]);
		}
	}
//	for(int i = 0; i <= n; i++){
//		for(int j = 0; j <= k; j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	cout << dp[n][k] << endl;
	
	return 0;
}
