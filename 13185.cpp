#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
#define mod 1000000007
#define mm 5005
using namespace std;
int fact(int n){
	int ans = 0;
	for(int i = 1; i < n; i++){
		if(n % i == 0) ans += i; 
	}
	return ans;
}
int main(void){
	int n;
	cin >> n;
	while(n--){
		int x = 0;
		cin >> x;
		int aa = fact(x);
		if(aa > x){
			cout << "abundant" << endl;
		}else if(aa < x){
			cout << "deficient" << endl;
		}else{
			cout << "perfect" << endl;
		}
	}
	
	return 0;
}
