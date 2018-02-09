#define pb push_back
#define ll long long
#include<bits/stdc++.h>
#define N 130
#define INF 1000000000
using namespace std;
string s;
int a[N];
int n, cs, dp[3][N], vs[N][N][3], canRe[N][N][3];
bool canDp(int s, int e, int ch){
	if(s == e) return a[s] == ch;
	if(vs[s][e][ch] == cs) return canRe[s][e][ch];
	vs[s][e][ch] = cs;
	int u, v, k;
	if(ch == 0) u = 1, v = 2;
	if(ch == 1) u = 0, v = 2;
	if(ch == 2) u = 0, v = 1;
	bool ok = false;
	for(k = s; k < e; k++){
		if(canDp(s, k, u) && canDp(k + 1, e, v)){
			ok = true;
			break;
		}
		if(canDp(s, k, v) && canDp(k + 1, e, u)){
			ok = true;
			break;
		}
	}
	return canRe[s][e][ch] = ok;
}
void solve(){
	cin >> s;
	n = s.size();
	for(int i = 0; i < n; i++) a[i + 1] = s[i] - 'a';
	for(int ch = 0; ch < 3; ch++){
		for(int i = 1; i <= n; i++){
			dp[ch][i] = INF;
			for(int j = 1; j <= i; j++){
				if(canDp(j, i, ch)){
					dp[ch][i] = min(dp[ch][i], dp[ch][j - 1] + 1);
				}
			}
		}
	}
	cout << min(dp[0][n], min(dp[1][n], dp[2][n])) << endl;
}
int main(void){
	int t; cin >> t; while(t--) cs ++, solve();
	return 0;
}
