#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
const int N = 1000000;
ll a[N], b, sum[N];
int n, k;
void solve(){
	cin >> n >> k;
	sum[0] = 0ll;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	ll slide = 0ll, ans = 1e18;
	for(int i = 1; i <= k; i++){
		slide +=(1ll * i * a[i] - (sum[i] - sum[0]));
	}
	ans = min(ans, slide);
	for(int i = k + 1; i <= n; i++){
		slide += 1ll * k * a[i] - 1ll * (sum[i] - sum[i - k]);
		slide -= (sum[i - 1] - sum[i - k - 1]);
		slide += 1ll * k * a[i - k];
		ans = min(slide, ans);
	}
	cout << ans << endl;
}
int main(void){
	solve();
	
	return 0;
}
