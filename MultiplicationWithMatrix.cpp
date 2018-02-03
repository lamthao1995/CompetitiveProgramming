#include<bits/stdc++.h>
#define ll long long
using namespace std;
void multi(ll f[3][3], ll m[3][3], ll x);
void power(ll f[3][3], ll n, ll a, ll b, ll c, ll m);
ll fib(ll n, ll a, ll b, ll c, ll m){
	ll f[3][3] = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
	if(n == 0) return 0;
	if(n <= 2) return 1;
	power(f, n - 2, a, b, c, m);
	ll res = (f[0][0] + f[0][1] + f[0][2] * c) % m;
	return res;
	
}
void power(ll f[3][3], ll n, ll a, ll b, ll c, ll m){
	if(n == 0 || n == 1) return;
	ll M[3][3] = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
	power(f, n / 2, a, b, c, m);
	multi(f, f, m);
	if(n % 2 != 0){
		multi(f, M, m);
	}
}
void multi(ll f[3][3], ll m[3][3], ll x){
	ll res[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			res[i][j] = 0 ;
			for(int k = 0; k < 3; k++){
				res[i][j] += f[i][k] * m[k][j];
				res[i][j] %= x;
			}
		}
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			f[i][j] = res[i][j];
		}
	}
	
}
int main(void){
	int t;
	cin >> t;
	ll a,b,c,n,m;
	while(t--){
		cin >> a >> b >> c >> n>> m;
		cout << fib(n, a, b, c, m) % m << endl;
	}
	return 0;
}
