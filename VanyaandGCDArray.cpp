#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
const int MOD = (int)(1e9+7), N = 600;
ll dp[N][N];
int arr[N], n;
int gcd(int a, int b){
	return a == 0 ? b : gcd(b % a, a);
}
// increasing consequence
ll go(ll i, ll g){
	if(dp[i][g] != -1) return dp[i][g];
	ll res = 0;
	if(g == 1) res = 1;
	for(int j = i + 1; j < n; j++){
		if(arr[i] < arr[j]){
			res += go(1ll * j,1ll *  __gcd(g, 1ll * arr[j])) % MOD;
			res %= MOD;
		}
	}
	return dp[i][g] = res;
}
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	memset(dp, -1, sizeof dp);
	ll ans = 0ll;
	for(int i = 0; i < n; i++){
		ans += go(1ll * i, 1ll *arr[i]);
		ans %= MOD;
	}
	cout << ans % MOD << endl;
}
int main(void){
//	cout << gcd(15, 20) << endl;
	solve();
}
