#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = (int)(1e9+7);
ll a[N][N], ans;
int A,b,c,d;
ll power(ll a, ll b){
	if(b == 0) return 1ll;
	if(b == 1) return a % MOD;
	ll h = power(a, b / 2) % MOD;
	h = (h * h) % MOD;
	if(b & 1) h = (h * a) % MOD;
	return h;
}
void preprcess(){
	a[0][0] = 1ll;
	for(int i = 1; i <= 1001; i++){
		for(int j = 0; j <= i; j++){
			if(!j){
				a[i][j] = 1;
			}else{
				a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % MOD;
			}
		}
	}
	for(int i = 1; i <= 1001; i++){
		for(int j = i + 1; j <= 1001; j++){
			a[i][j] = (1ll * i * j) % MOD;
		}
	}
	for(int i = 0; i <= 1001; i++){
		for(int j = 1; j <= 1001; j++){
			a[i][j] = (a[i][j] * a[i][j - 1]) % MOD;
		}
	}
}
void solve(){
	ans = 0;
	cin >> A >> b >> c >> d;
	for(int j = A; j <= b; j++){
		ll tmp = a[j][d];
		if(c > 0){
			tmp = (tmp * power(a[j][c - 1], MOD - 2)) % MOD;
		}
		ans = (ans + tmp) % MOD;
	}
	cout << ans << endl;
}
int main(void){
	preprcess();
	int t; cin >> t;
	 while(t--) solve();
	return 0;
}
