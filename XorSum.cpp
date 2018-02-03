#define ll long long int
#include<bits/stdc++.h>
#define MOD (int)(1e9+7)
using namespace std;
ll power(ll a, int pow_){
	if(pow_ == 0) return 1ll;
	if(pow_ == 1) return a % MOD;
	ll half = power(a, pow_ / 2);
	half = (half * half) % MOD;
	if(pow_ & 1) half = (half * a) % MOD;
	return half;
}
void solve(){
//	cout << "Ket qua" << endl;
	int n; cin >> n;
	ll ans = 0, x;
	for(int i = 0; i < n; i++) cin >> x, ans |= x;
	ans *= power(2ll, n - 1);
//	cout << "Ket qua" << endl;
	ans %= MOD;
	cout << ans << endl;
}
int main(void){
	int i; cin >> i;
	while(i--) solve();
	return 0;
}
