#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(void){
	ll n;
	cin >> n;
	if(n % 10 == 0){
		cout << n << endl;
	}else{
		int r1 = n % 10; int r2 = 10 - r1;
		if(r1 > r2) n += r2;
		else n -= r1;
		cout << n << endl;
	}
	return 0;
}
