#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
#define mod 1000000007
#define mm 5005
using namespace std;

ll arr[mm], ncr[mm][mm];
ll gr[mm][mm], ans[mm][mm];
ll Ncr(int n, int r){
	if(r == 1) return n;
	if(n == r) return 1;
	if(ncr[n][r] != -1) return ncr[n][r];
	ncr[n][r] = Ncr(n - 1, r) % mod + Ncr(n - 1, r - 1) % mod;
	ncr[n][r] % mod;
	return ncr[n][r];
}
void init(){
	for(int i = 1; i <= 5000; i++){
		for(int j = 2 * i; j <= 5000; j += i){
			arr[j]++;
		}
	}
	for(int i = 1; i <= 5000; i++){
		for(int j = 1; j <= 5000; j++){
			if(arr[j] >= i ) gr[i][j] = (gr[i][j - 1] + 1ll * i) % mod;
			else gr[i][j] = (gr[i][j - 1] + arr[j]) % mod;
		}
	}
	memset(ncr, -1, sizeof(ncr));
	for(int i = 1; i <= 5000; i++){
		ans[i][0] = 1;
		for(int j = 1; j <= 5000; j++){
			if(arr[j] <= i) ans[i][j] = (ans[i][j - 1] * 1) % mod;
			else {
				ll tmp = Ncr(arr[j], i) % mod;
				ans[i][j] = (ans[i][j - 1] * tmp) % mod;
			}
		}
	}
}
int main(void){
	init();
	int x;
	cin >> x;
	while(x--){
		int n, k;
		cin >> n >> k;
		printf("%lld %lld\n", gr[k][n], ans[k][n]);
	}
	return 0;
}
