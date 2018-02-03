#define ll long long
#include<bits/stdc++.h>
using namespace std;
int n, m, k;
string s;
void solve(){
	cin >> n >> k;
	cin >> s;
	string res = "";
	int x = 0;
	for(int i = 0; i < n; i++){
		if(i >= k){
			x ^= res[i - k] - '0';
		}
		res += ('0' + (s[i] - '0') ^ x);
		x ^= res.back() - '0';
	}
	cout << res;
}
int main(void){
	solve();
	return 0;
}
