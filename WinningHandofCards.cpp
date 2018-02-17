#define ll long long
#include<bits/stdc++.h>
#define N 300000
#define pb push_back
#define ms(a,b) memset(a, b, sizeof b)
#define M 300
using namespace std;
int n, m, x, k;
unordered_map<int,int> mp1, mp2;
vector<int> v1, v2, s1, s2;
int a[N], dp[M][M];
int gcdExtended(int a, int b, int* x, int *y){
	if(a == 0){
		*x = 0; *y = 1;
		return b;
	}
	int x1, y1;
	int gcd = gcdExtended(b % a, a, &x1, &y1);
	*x = y1 - b/a * x1;
	*y = x1;
	return gcd;
}
void solve(){
	mp1.clear(); mp2.clear();
	v1.clear(); v2.clear(); s1.clear(); s2.clear();
	ms(dp, -1);
	cin >> n >> m >> x;
	ll ans = 0;
//	int ans = 0;
	k = n / 2;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] %= m;
		if(i < k) v1.pb(a[i]);
		else v2.pb(a[i]);
	}
	for(int mask = 1; mask < (1 << v1.size()); mask++){
		int mul = 1;
		for(int i = 0; i < v1.size(); i++){
			if((1 << i) & mask){
				mul = (mul * v1[i]) % m;
			}
		}
	//	s1.pb(mul);
		mul %= m;
		mp1[mul]++;
		if(mul == x) ans++;
	}
	for(int mask = 1; mask < (1 << v2.size()); mask++){
		int mul = 1;
		for(int i = 0; i < v2.size(); i++){
			if((1 << i) & mask){
				mul = (mul * v2[i]) % m;
			}
		}
	//	s2.pb(mul);
		mul %= m;
		mp2[mul]++;
		if(mul == x) ans++;
	}
//	cout << "Pre: " << ans << endl;
	for(auto it = mp1.begin(); it != mp1.end(); it++){
		int a = it->first;
		int b = m, c = x; int k1, k2;
		int gcd = __gcd(a, b);
		if(c % gcd != 0) continue;
		gcdExtended(a, b, &k1, &k2);
		int x2 = (c * k1) % m;
		if(x2 < 0) x2 = (x2 % m + m) % m;
		int inc = c / gcd;
		for(int i = x2 + inc; i < m; i += inc){
			ans += mp2[i] * mp1[a];
		}
		for(int i = x2; i >= 0; i -= inc){
			ans += mp2[i] * mp1[a];
		}
	}
	cout << ans << endl;
}
int main(void){
	int t= 1;
	while(t--) solve();
	return 0;
}
