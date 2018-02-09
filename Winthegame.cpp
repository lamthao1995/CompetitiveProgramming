#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
double r, g;
void solve(){
	cin >> r >> g;
	if(r + g == 0.0 || r == 0.0 || g == 0.0){
		printf("1.00000\n");
		return;
	}
	double ans = r / (g + r);
	double i = g;
	double tmp = g / (g + r);
	while(i > 1.0){
		tmp *= (i - 1) / (r + i - 1);
		ans += tmp * (r / (r + i - 2));
		tmp *= (i - 2) / (r + i - 2);
		i -= 2;
	}
	//ans;
	printf("%0.6f\n", ans);
}
int main(void){
	int t; cin >> t;
	while(t--) solve();
}
