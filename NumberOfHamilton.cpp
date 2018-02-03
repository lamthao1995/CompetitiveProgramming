#define ll long long
#include<bits/stdc++.h>
using namespace std;
int n, m, a, b;
int dp[1 << 20][20];
int mt[200][200];
int countBit1(int x){
	int sum = 0;
	while(x != 0){
		if(x & 1) sum++;
		x >>= 1;
	}
	return sum;
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			mt[i][j] = 0;
		}
	}
	//for(int i = 0; i < n; i++) mt[i][i] = 1;
	for(int i = 0; i < m; i++){
		cin >> a >> b; a--; b--;
		mt[a][b] = mt[b][a] = 1;
	}
	for(int mask = 0; mask < 1 << n; mask++){
		for(int i = 0; i < n; i++){
			dp[mask][i] = 0;
			if(countBit1(mask) == 1 && ((1 << i) & mask)){
				dp[mask][i] = 1;
			}else if(((1 << i) & mask) && countBit1(mask) > 1){
				for(int j = 0; j < n; j++){
					if(mt[i][j] == 0) continue;
					if(((1 << j) & mask)) dp[mask][i] += dp[mask ^ (1 << i)][j];
				}
			}else{
				dp[mask][i] = 0;
			}
			//cout << dp[mask][i] << " ";
		}
	}
	ll ans = 0;
	int idx = (1 << n) - 1;
	for(int i = 0; i < n; i++) ans += dp[idx][i];
	cout << ans << endl;
}
int main(void){
	solve();
	return 0;
}
