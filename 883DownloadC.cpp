#include<bits/stdc++.h>
#define ll long long
#define max 1e18
using namespace std;
ll ans, f, T, t0;
ll a[2], t[2], p[2];
void solve(){
	ans = max;
	cin >> f >> T >> t0;
	for(ll i = 0; i < 2; i++) cin >> a[i] >> t[i] >> p[i];
	for(ll x = 0, y = 0; y * a[1] * t[1] <= T; y++){
		int b = f - a[1] * y, c = T - a[1] * t[1] * y;
		if(c < b * t0){
			if(t[0] >= t0) continue;
			x = (b * t0 - c + t0 - t[0] - 1) / (t0 - t[0]);
			if(x > b) continue;
		}else{
			x = 0;
		}
		ans = min(ans, (x + a[0] - 1) / a[0] * p[0] + y * p[1]);
	}
	swap(a[0], a[1]); swap(t[0], t[1]); swap(p[0], p[1]);
	for(ll x = 0, y = 0; y * a[1] * t[1] <= T; y++){
		ll b = f - a[1] * y, c = T - a[1] * t[1] * y;
		if(c < b * t0){
			if(t[0] >= t0) continue;
			x = (b * t0 - c + t0 - t[0] - 1) / (t0 - t[0]);
			if(x > b) continue;
		}else{
			x = 0;
		}
		ans = min(ans, (x + a[0] - 1) / a[0] * p[0] + y * p[1]);
	}
	if(ans == max){
		cout << -1 << endl;
	}else{
		cout << ans << endl;
	}	
}
int main(){
	solve();
	return 0;
}
