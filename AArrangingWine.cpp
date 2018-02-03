#include<bits/stdc++.h>
#define MOD (int)(1e9 + 7)
#define ll long long int
#define MAXN 1000007
using namespace std;
ll fact[MAXN], inFact[MAXN];
ll fact2[MAXN];
ll pow(ll a, ll b, ll mod){
	if(b == 1) return a % mod;
	if(b == 0) return 1ll;
	ll h = pow(a, b / 2, mod) % mod;
	h = (h * h) % mod;
	if(b % 2 == 1) h = (h * a) % mod;
	return h;
}
ll modIn(ll x){
	return pow(x, MOD - 2, MOD);
}
void init(int limit){
	fact[0] = 1; inFact[0] = modIn(fact[0]);
	for(int i = 1; i < MAXN; i++){
		fact[i] = (fact[i - 1] * i) % MOD;
		inFact[i] = modIn(fact[i]);
	}
	fact2[0] = (fact[MAXN - 1] )* MAXN % MOD;
	for(int i = 1; i < MAXN; i++){
		fact2[i] = (i + MAXN) * fact2[i - 1] % MOD;
	}
}
int sign(int n){
	return n % 2 == 0 ? 1 : -1;
}
ll r, w, d;
int main(void){
	cin >> r >> w >> d;
	int limit = max(r, w) + 10;
	init(limit);
	ll ans = 0;
	for(int i = 0; i <= w + 1; i++){
		if(r - d * i - i < 0) break;
		ll t1 = fact[w + 1]* inFact[i] * inFact[w + 1 - i];
		int pi = w + r - d * i - i;
		ll t = 1;
		if(pi >= MAXN){
			t = fact2[pi - MAXN];
		}else{
			t = fact[pi];
		}
		ll t2 = t * inFact[r - d * i - i] * inFact[w];
		t1 %= MOD; t2 %= MOD;
		ans += sign(i) * t1 * t2;
		ans %= MOD;
		if(ans < 0) ans += MOD;
	}
	ans %= MOD;
	cout << ans << endl;
	return 0;
}
