#include<bits/stdc++.h>
#define pb push_back
#define MOD (int)(1e9 + 7)
#define N 200000
#define pi pair<int,int>
using namespace std;
#define ll long long
ll arr[N], tree[N], c, a, b, x0, cof[N];
int n, m, type, q;
ll power(ll a, ll b){
	if(b == 0) return 1ll;
	if(b == 1) return a % MOD;
	ll half = power(a, b / 2);
	half = (half * half) % MOD;
	if(b & 1) half *= a;
	return half % MOD;
}
ll modinv(ll a){
	return power(a, MOD - 2);
}
ll query(int idx){
	ll sum = 0ll;
	while(idx > 0){
		sum = (tree[idx] + sum) % MOD;
		idx -= idx & -idx;
	}
	return sum;
}
void update(ll val, int idx){
	while(idx <= n){
		tree[idx] = (tree[idx] + val) % MOD;
		idx += idx & -idx;
	}
}
void solve(){
	cin >> n >> a >> b >> q;
	x0 = (1ll * MOD - b) * modinv(a);
	x0 = (x0 % MOD + MOD) % MOD;
	ll tmp = 1ll;
	for(int i = 1; i <= n; i++){
		cin >> c;
		cof[i] = c % MOD;
		arr[i] = (tmp * c) % MOD;
		tmp = (tmp * x0) % MOD;
	}
	for(int i = 1; i <= n; i++){
		update(arr[i], i);
	}
	while(q--){
		cin >> type;
		if(type == 1){
			int i; ll x; cin >> i >> x; i++;
			update(-arr[i], i);
			x %= MOD;
			arr[i] = (x * power(x0, i - 1)) % MOD;
			update(arr[i], i);
			cof[i] = x % MOD;
		}else if(type == 2){
			int l, r; cin >> l >> r; l++; r++;
			ll sum = query(r) - query(l - 1);
			if(x0 == 0 && cof[l] == 0){
				cout << "Yes" << endl;
			}else if(x0 != 0 && sum == 0){
				cout << "Yes" << endl;
			}else cout << "No" << endl;
		}else{
			assert(1 == 2);
		}
	}
}
int main(){
	solve();
	return 0;
}
