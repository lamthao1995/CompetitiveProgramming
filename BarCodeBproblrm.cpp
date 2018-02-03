#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXX 1000007
ll memo[MAXX];
int C[MAXX];
int n, m;
ll fib(int n){
	if(n == 1 || n == 2) return 1 % m;
	if(n == 3) return 2 % m;
	if(memo[n] != -1) return memo[n] % m;
	int k = n / 2;
	if(n % 2 == 0){
		memo[n] = fib(k) * (fib(k - 1) + fib(k + 1)) % m;
	}else{
		memo[n] = (fib(k - 1) * fib(k + 1)) % m + (fib(k) * fib(k + 2)) % m;
	}
	memo[n] %= m;
	return memo[n];
}
int modDP(int n, int r, int p){
	memset(C, 0, sizeof C);
	C[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = min(i, r); j > 0; j--){
			C[j] = (C[j] + C[j - 1]) % p;
		}
	}
	return C[r];
}
int modLucas(int n, int r, int p){
	if(r == 0) return 1;
	int ni = n % p, ri = r % p;
	int ans = modLucas(n / p, r / p, p) % p;
	ans*= modDP(ni, ri, p); ans %= p;
	return ans;
}
ll power(ll a, ll b, ll mod){
	if(b == 1) return a % mod;
	if(b == 0) return 1;
	ll hh = power(a, b / 2, mod) % mod;
	hh = (hh * hh) % mod;
	if(b % 2 == 1){
		hh = (hh * a) % mod;
	}
	return hh;
}
ll modInverse(ll a){
	return power(a, m - 2, m);
}
int main(void){
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		memset(memo, -1, sizeof memo);
		cin >> n >> m;
		ll res = fib(n + 2);
		if(n % 2 == 0){
			ll av = 1, bv = 1, s = 0, x = 0;
			for(int i = n / 2 + 1; i <= n; i++){
				for(x = i; x % m == 0; x /= m) s++;
				av = 1ll * av * x % m;
			}
			for(int i = 1; i <= n / 2; i++){
				for(x = i; x % m == 0; x /= m) s--;
				bv = (1ll * bv * x) % m;
			}
			if(!s) res = (res + 1ll * av * modInverse(bv) % m) % m;
			res -= (n / 2 + 1);
			res %= m;
			if(res < 0) res += m;
		}
		cout << res << endl;
	}
	return 0;
}
