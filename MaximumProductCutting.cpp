#define ll long long int
#define MOD (int)(1e9+7)
#include<bits/stdc++.h>
using namespace std;
ll power(ll a, ll b){
	if(b == 0) return 1ll;
	if(b == 1) return a % MOD;
	ll h = power(a, b / 2) % MOD;
	h = (h * h) % MOD;
	if(b & 1) h = (a * h) % MOD;
	return h;
}
int n;
void solve(){
	cin >> n;
	if(n == 2){
		cout << 1 << endl; 
		return;
	}
	if(n == 3){
		cout << 2 << endl;
		return;
	}
	ll ans = 0;
	if(n % 3 == 2){
		ans = power(3ll, 1ll * (n - 2) / 3) % MOD;
		ans = (ans * 2ll) % MOD;
	}else if(n % 3 == 1){
		ans = power(3ll, 1ll * (n - 4) / 3) % MOD;
		ans = (ans * 4ll) % MOD;
	}else{
		ans = power(3ll, 1ll * n / 3) % MOD;
	}
	cout << ans << endl;
}
int main(){
	int t; cin >> t;
	while(t--) solve();
}
