#define ll long long
#define pb push_back
#include<bits/stdc++.h>
#define N 400000
using namespace std;
int a[N];
int n,s,w,q;
ll sum[N];
void generate(){
	int g = s;
	for(int i = 0; i < n; i++){
		a[i] = (g/7) % 10;
		if(g%2 == 0) g >>= 1;
		else g = (g>>1) ^ w;
	}
}
void solve(){
	cin >> n >> s >> w >> q;
	generate();
	if(n == 0) return;
	if(q == 2 || q == 5){
		int ans = 0, cnt = 0;
		for(int i = n - 1; i >= 0; i--){
			if(a[i] % q == 0) ans += i + 1, cnt++;
			if(a[i]==0) ans -= cnt;
		}
		cout << ans << endl;
		//solve();
		//return;
	}else{
		sum[n] = 0;
		ll base = 1ll;
		for(int i = n - 1; i >= 0; i--){
			sum[i] = a[i] * base + sum[i + 1];
			base *= 10;
			sum[i] %= q;
			base %= q;
		}
		map<ll, int> rec;
		rec.insert({0,1});
		int ans = 0;
		for(int i = n - 1; i >= 0; i--){
			auto &val = rec[sum[i]];
			if(a[i]) ans += val;
			val++;
		}
		cout << ans << endl;
	}
	solve();
}
int main(){
	solve();
}
