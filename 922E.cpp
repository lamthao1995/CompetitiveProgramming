#define ll long long
#define pb push_back
#define N 1000000
#include<bits/stdc++.h>
#define M 10005
using namespace std;
ll dp[1005][10005], cost[1005];
int c[1005];
int n;
ll W, B, X;
void relax(ll &u, ll v){
	u = max(u, v);
}
void solve(){
	cin >> n;
	cin >> W >> B >> X;
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < n; i++) cin >> cost[i];
	fill_n(&dp[0][0], 1005 * 10005, -1);
	dp[0][0] = W;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < M && dp[i][j] != -1; j++){
			for(int k = 0; k <= c[i] && dp[i][j] - k * cost[i] >= 0; k++){
				relax(dp[i + 1][k + j], min(W + (k + j) * B, dp[i][j] - k * cost[i] + X));
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < M; i++){
		if(dp[n][i] != -1){
			ans = max(ans, i);
		}
	}
	cout << ans;
}
int main(void){
	solve();
	return 0;
}
