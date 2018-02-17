#define ll long long
const int N = 2000;
#include<bits/stdc++.h>
using namespace std;
ll dp[N][N];
int n, m, k, a[N][N];
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			dp[i + 1][j + 1] = a[i][j] + dp[i + 1][j] + dp[i][j + 1] - dp[i][j];
		}
	}
	cin >> k;
	int r1, r2, c1, c2;
	while(k--){
		cin >> r1 >> c1 >> r2 >> c2;
		ll ans = dp[r2][c2] + dp[r1 - 1][c1 - 1] - dp[r2][c1 - 1] - dp[r1 - 1][c2];
		cout << ans << endl;
	}
}
int main(){
	solve();
}
