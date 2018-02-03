#define ll long long
#define N 100000
#include<bits/stdc++.h>
using namespace std;
int n, m, k,arr[N];
int g[350][350];
bool seen[N];
int match[N];
bool bpm(int u){
	for(int v = 1; v <= n; v++){
		if(g[u][v] && !seen[v]){
			seen[v] = 1;
			if(match[v] < 0 || bpm(match[v])){
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}
void solve(){
	cin >> n >> k;
	memset(g, 0, sizeof g);
	for(int i = 1; i <= n; i++) cin >> arr[i], seen[i] = 0, match[i] = -1;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(abs(arr[i] - arr[j]) >= k) g[i][j] = 1;
		}
	}
	int rs = 0;
	for(int i = 1; i <= n; i++){
		for(int i = 1; i <= n; i++) seen[i] = false;
		if(bpm(i)) rs++;
	}
	cout << "SO cpa ghep cuc dai: " <<rs << endl;
	cout << n - rs << endl;
}
int main(void){
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
