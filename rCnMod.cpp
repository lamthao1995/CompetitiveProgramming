#define ll long long int
#define MOD (int)(1e9+7)
#include<bits/stdc++.h>
using namespace std;
const int N = 400000;
ll fact[N];
ll inver[N];
ll power(ll a, ll b, ll mod){
	if(b == 1) return a % mod;
	if(b == 0) return 1ll;
	ll h = power(a, b / 2, mod);
	h = (h * h) % mod;
	if(b & 1) h = (a * h) % mod;
	return h;
}
void init(){
	fact[0] = inver[0] = 1ll;
	for(int i = 1; i < 2000; i++){
		fact[i] = (fact[i - 1] * i) % MOD;
		inver[i] = power(fact[i], MOD - 2, MOD);
	}
}
void solve(){
	int n, r;
	cin >> n >> r;
	ll ans = fact[n] * inver[n - r];
	ans = (ans % MOD) * inver[r];
	cout << ans % MOD << endl;
}
int main(){
	init();
	int t; cin >> t;
	while(t--) solve();
}
