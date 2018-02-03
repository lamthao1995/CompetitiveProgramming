#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, p[100000 + 100];
int rs[100000 + 100];
int dfs(int u){
	if(p[u] == -1) return 0;
	int v = p[u];
	p[u] = -1;
	return 1 + dfs(v);
}
int main(void){
	cin >> n;
	memset(p, -1, sizeof(p));
	memset(rs, 0, sizeof(rs));
	int k = 0;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for(int i = 1; i <= n; i++){
		if(p[i] != -1){
			rs[k] = dfs(p[i]);
			k++;
		}
	};
	sort(rs, rs + k);
	ll tmp = rs[k - 1] + rs[k - 2];
	ll ans = tmp * tmp;
	for(int i = 0; i <= k - 3; i++){
		ans += rs[i] * rs[i];
	}
	cout << ans << endl;
	return 0;
}
