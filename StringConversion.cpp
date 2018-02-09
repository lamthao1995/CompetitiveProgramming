#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
int n, m, q, dp[1000][1000];
string a, b;
void solve(){
	cin >> n >> m;
	cin >> a >> b;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= m; j++){
			if(dp[i][j] == 0) continue;
			if(j < m && toupper(a[i]) == b[j]){
				dp[i + 1][j + 1] = 1;
			}
			if(!isupper(a[i])){
				dp[i + 1][j] = 1;
			}
		}
	}	
	if(dp[n][m] == 1){
		cout << "YES" << endl;
	}else cout << "NO" << endl;
}
int main(void){
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
