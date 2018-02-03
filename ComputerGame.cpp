#define ll long long
#define pb push_back
#define N 100100
#include<bits/stdc++.h>
using namespace std;
int m, n, match[N], A[N], re[N], B[N];
bool seen[N];
int gcd(int a, int b){
	return a == 0 ? b : gcd(b % a, a);
}
bool bpm(int u){
	for(int i = 1; i <= n; i++){
		if(!seen[i] && gcd(A[u], B[i]) != 1){
			seen[i] = true;
			if(match[i] < 0 || bpm(match[i])){
				match[i] = u;
				re[u] = i;
				return true;
			}
		}
	}
	return false;
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> A[i], match[i] = re[i] = -1;
	for(int i = 1; i <= n; i++) cin >> B[i];
	int rs = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) seen[j] = false;
		if(bpm(i)) rs++;
	}
	//set<int> ss;
//	for(int i = 1; i <= n; i++) if(re[match[i]] > 0) ss.insert(re[match[i]]);
	cout << rs << endl;
}
int main(){
	solve();
}
