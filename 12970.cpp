#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll x, ll y){
	return x == 0 ? y : gcd(y %x, x);
}

int main(void){
	ll d1, v1, d2, v2;
	int t = 1;
	while(1){
		cin >> v1 >> d1 >> v2 >> d2;
		if(v1 == 0 && v2 == 0 && d1 == 0 && d2 == 0) break;
		cout << "Case #" << (t++) << ": ";
		if(v1 * d2 > v2 * d1){
			cout << "You owe me a beer!" << endl;
		}else{
			cout << "No beer for the captain." << endl;
		}
		cout << "Avg. arrival time: ";
		ll num = d1 * v2 + v1 * d2;
		ll den = 2 * v1 * v2;
		ll divD = gcd(num, den);
		num /= divD;
		den /= divD;
		if(den == 1){
			cout << num << endl;
		}else{
			cout << num << "/" << den << endl; 
		}
	}
	return 0;
}
