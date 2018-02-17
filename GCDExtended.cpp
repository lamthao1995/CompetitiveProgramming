#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
int gcdExtended(int a, int b, int *x, int *y){
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
	int a = 50, b = 30, c = 10;
	if(c % __gcd(a, b) != 0){
		cout << "Vo nghiem" << endl;
		return;
	}
	int k1, k2;
	int v = gcdExtended(a, b, &k1, &k2);
	cout << k1 << " " << k2 << endl;
	int x = (k1 * c) % b;
	if(x < 0) x = (x % b + b) % b;
	cout << x << endl;
	
	
}
int main(void){
//	solve();
	for(int i = 0; i < 30; i++){
		if((50 * i - 10) % 30 == 0){
			cout << i << endl;
		}
	}
	return 0;
}
