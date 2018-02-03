#define ll long long int
#include<bits/stdc++.h>
#define MOD (int)(1e9 + 7)
using namespace std;
ll a, b, k;
ll kArr[2000000], sum[2000000];
ll answer(ll pp, ll x){
	if(x >= 2000000) return 0;
	return sum[x];
}
void solve(){
	cin >> k >> a >> b; if(a > b) swap(a, b);
	kArr[0] = 0, kArr[1] = 1ll; sum[1] = 1ll;
	for(int i = 2; i < 1000; i++){
		kArr[i] = (kArr[i - 1] * k + 1);
		sum[i] = (kArr[i] + sum[i - 1]) % MOD;
	}
    ll ans = 0, pv = b - (b % k), tmp;
	int i = 0;
	while(kArr[i] <= a) i++;
	if(b < kArr[i]){
		ans = (b - a + 1) % MOD;
		ans = (ans * sum[i - 1]) % MOD;
		cout << ans << endl;
		return;
	}
	tmp = ((kArr[i] - a) % MOD) * sum[i - 1];
	ans = (ans + tmp) % MOD;
	for(; kArr[i] <= (b - 1) / k; i++){
		tmp = ((kArr[i + 1] - kArr[i]) % MOD) * sum[i]; 
		tmp %= MOD;
		ans = (tmp + ans) % MOD;
	}
	tmp = (b + 1 - kArr[i]) % MOD; tmp = (tmp * sum[i]) % MOD;
	ans = (tmp + ans) % MOD;
	cout << ans << endl;
    
}
int main(void){
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
