#define ll long long
#define pb push_back
#define N 300000
#include<bits/stdc++.h>
using namespace std;
ll arr[N],  td[N];
int n, m, j;
void solve(){
	cin >> n;
	int res = 0;
	for(int i = 0; i < n; i++) cin >> arr[i];
	int u[n + 1];
	for(ll mask = 0; mask < (1 << n); mask++){
		memset(u, 0, sizeof u);
		for(int i = 0; i < n; i++) td[i] = arr[i];
		for(int i = 0; i < n; i++) if(td[i] != 0 && ((1 << i) & mask)){
			for(j = i + 1; j < n; j++) if(td[j] != 0 && ((1 << j) & mask)){
				if((td[i] & td[j]) > 0){
					td[j] |= td[i];
					break;
				}
			}
			if(j == n) u[i] = 1;
		}
		res += 64;
		for(int i = 0; i < n; i++) if(u[i]){
			res -= __builtin_popcountll(td[i]) - 1;
		}
	}
	cout << res << endl;
}
int main(void){
	solve();
	
	return 0;
}
