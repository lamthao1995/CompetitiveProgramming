#define ll long long
#include<bits/stdc++.h>
using namespace std;
string s;
const int N = 60;
bool dp[N][N];
void solve(){
	memset(dp, 0, sizeof dp);
	cin >> s;
	int n = s.size();
	int ans = 0;
	for(int i = n - 1; i >= 0; i--){
		for(int j = i; j < n; j++){
			if(s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])){
				dp[i][j] = 1;
				ans++;
			}
		}
	}
	cout << ans;
}
int main(){
	solve();
}
