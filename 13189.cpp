#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
#define mod 1000000007
#define mm 5005
using namespace std;

int main(void){
	int t;
	cin >> t;
	while(t--){
		ll m; cin >> m;
		m--;
		if(m == 0){
			cout << "0 0" << endl;
			continue;
		}
		ll n = sqrt(m) / 2;
		ll totalSf = 4 * n * n;
		ll dif = m - totalSf;
		ll nn = n + 1;
		ll a = 4 * nn - 3;
		ll b = 2 * nn - 1, c = b + 1;
		if(dif == 0){
			cout << 2 * n << " " << -1 * (n) << endl;
		}else if(dif <= a){
			ll x = 2 * n - dif;
			ll y = -n;
			cout << x << " " << y << endl;
		}
		else if(dif <= (a + b)){
			totalSf += a;
			ll x = 2 * n - a;
			ll y = -n;
			dif = m - totalSf;
			x += dif; y += dif;
			cout << x << " " << y << endl;
		}else if(dif <= a + b + c){
			totalSf += (a + b);
			ll x = 2 * n - a;
			ll y = -n;
			dif =m - totalSf;
			x += b; y += b;
			x += dif;
			y -= dif;
			cout << x << " " << y << endl;
		}
	}
	return 0;
}
