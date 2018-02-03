#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
const int N = 400000;
int st[N], n;
int mul(int x, int res_size){
	int carry = 0;
	for(int i = 0; i < res_size; i++){
		int prod = st[i] * x + carry;
		st[i] = prod % 10;
		carry = prod / 10;
	}
	while(carry){
		st[res_size] = carry % 10;
		carry /= 10;
		res_size++;
	}
	int ans = 0;
	for(int i = res_size - 1; i >= 0; i--) ans += st[i];
	mp[x] = ans;
	return res_size;
}
void solve(){
	int n = 1001;
	int res_size = 1;
	st[0] = 1;
	for(int x = 2; x <= n; x++){
		res_size = mul(x, res_size);
	}
}
int main(){
	int t, x; scanf("%d", &t);
	mp[0] = 1; mp[1] = 1;
	solve();
	while(t--) cin >> x, cout << mp[x] << endl;
	return 0;
}
