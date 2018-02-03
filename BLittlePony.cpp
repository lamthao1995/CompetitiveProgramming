#include<bits/stdc++.h>
const int m = 65536;
const int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int n, a, t, s[60];
int f[109][m], g[109][m];
int c, b[109];
using namespace std;
int main(){
	cin >> n;
	for(int i = 1; i < 59; i++) for(int j = 0; j < 16; j++)
		if(i % p[j] == 0) s[i] |= 1 << j;
	for (int j=1;j<m;++j) f[0][j]= 0X40000000;
	for(int i = 1; i <= n; i++){
		cin >> a;
		for(int j = 0; j < m; j++){
			f[i][j] = 0X40000000;
		}
		for(int j = 0; j < m; j++){
			for(int k = 1; k < 59; k++) if(!(j & s[k])){
				t = j | s[k];
				if(f[i][t] > f[i - 1][j] + abs(k - a)){
					f[i][t] = f[i - 1][j] + abs(k - a);
					g[i][t] = k;
				}
			}
		}
	}
	for(int i = 0; i < m; ++i) if(f[n][t] > f[n][i]) t = i;
	for(int i = n; i > 0; i--) t ^= s[b[c++] = g[i][t]];
	while (c--) printf("%d ",b[c]);
	return 0;
	
}
