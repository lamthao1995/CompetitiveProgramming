#include<bits/stdc++.h>
using namespace std;
#define PR1 43
#define PR2 37
#define MOD1 1000000007
#define MOD2 1000000009
#define mp(a, b) make_pair(a, b)
map<pair<int, int>, int> m;
char a[4005], b[4005];
int pw1[30], pw2[30];
int modPlus(int a, int b, int mod){
	return (a + b) % mod;	
}
int modMul(long long a, long long b, int mod){
	return (a * b) % mod;
}
void solve(void){
	int lenA = strlen(a), lenB = strlen(b), i, j;
	m.clear();
	for( i = 0; i < lenA; i++){
		int h1 = 0, h2 = 0;
		for(j = i; j < lenA; j++){
			int index = a[j] - 'a';
			h1 = modPlus(h1, pw1[index], MOD1);
			h2 = modPlus(h2, pw2[index], MOD2);
			m[mp(h1, h2)] = 1;
		}
	}
	int ans = 0;
	for(i = 0; i < lenB; i++){
		int h1 = 0, h2 = 0;
		for(j = i; j < lenB; j++){
			int index = b[j] - 'a';
			h1 = modPlus(h1, pw1[index], MOD1);
			h2 = modPlus(h2, pw2[index], MOD2);
			if(j - i + 1 <= ans) continue;
			if(m.find(mp(h1, h2)) != m.end()){
				ans = max(ans, j - i + 1);
			}
		}
	}
	cout << ans << endl;
	return;
}
int main(){
	pw1[0] = pw2[0] = 1;
	for(int i = 1; i < 30; i++){
		pw1[i] = modMul(pw1[i - 1], PR1, MOD1);
		pw2[i] = modMul(pw2[i - 1], PR2, MOD2);
	}
	while(scanf("%s%s", a, b) != EOF){
		solve();
	}
	return 0;
}
