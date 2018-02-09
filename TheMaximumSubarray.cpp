#define ll long long
#define N 1000000
#include<bits/stdc++.h>
using namespace std;
ll a[N], n;
void solve(){
	cin >> n;
	ll ans1 = 0;
	ll max_ = 1e15;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] > 0) ans1 += a[i];
		max_ = max(max_, a[i]);
	}
	if(max_ < 0ll){
		ans1 = max_;
	}
	ll maxLo = 1ll * a[0], maxGlo = 1ll * a[0];
	for(int i = 1; i < n; i++){
		maxLo = max(maxLo + a[i], a[i]);
		maxGlo = max(maxGlo, maxLo);
	}
	cout << maxGlo << " " << ans1 << endl;
	
}
int main(void){
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
