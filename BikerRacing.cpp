#define ll long long int
#include<bits/stdc++.h>
using namespace std;
ll N, L, M;
ll a[1000000];
ll h[1000000];
bool check(ll mid){
	ll sum = 0;
	for(int i = 1; i <= N; i++){
		ll tmp = (h[i] + mid * a[i]);
		if(tmp < L) continue;
		sum += tmp;
	}
	return sum >= M;
}
void solve(){
	cin >> N >> M >> L;
	for(int i = 1; i <= N; i++) cin >> h[i] >> a[i];
	ll ans = 0, l = 0, r = 1e9;
	while(l <= r){
		ll mid = (r - l) / 2 + l;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	cout << ans << endl;
}
int main(void){
	int t; cin >> t;
	while(t--) solve();
}

