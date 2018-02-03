#include<bits/stdc++.h>
#define pb push_back
#define fs first
#define inf 0x3f3f3f3f
#define sc second
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pair<int, int> >
#define mp(i,j) make_pair(i,j)
#define pii pair<long long, long long>
using namespace std;
int n, m, nm, flag[20], k, j, res, p = 1;
int kk = 100, fg, i, arr[11][11], ans[11][11];
vi v1, v2;
int main(void){
	while(cin >> n >> m && (m + n)){
		res = 0;
		memset(arr, 0, sizeof(arr));
		if(n > m) swap(m, n);
		if(ans[n][m]){
			printf("Case #%d: %d\n", p++, ans[n][m]);
			continue;
		}
		if(m == 3 && n==3){
				arr[1][3] = 2;	
			arr[1][9] = 5;	
			arr[1][7] = 4;	
			arr[2][8] = 5;	
				arr[3][7] = 5;	
			arr[3][9] = 6;	
			arr[3][1] = 2;	
			arr[4][6] = 5;
				arr[6][4] = 5;	
			arr[7][3] = 5;	
			arr[7][1] = 4;	
			arr[7][9] = 8;
				arr[8][2] = 5;	
			arr[9][1] = 5;	
			arr[9][3] = 6;	
			arr[9][7] = 8;
		}else if(n == 2 && m == 3){
				arr[1][3] = 2;	
			arr[3][1] = 2;	
			arr[4][6] = 5;	
			arr[6][4] = 5;
		}else if(m == 3 && n == 1){
			arr[1][3] = arr[3][1] = 2;
		}
		nm = (1 << (m * n));
		for(int i = 1; i < nm; i++){
			v1.clear();
			v2.clear();
			k = i; j = 1;
			while(k){
				if(k & 1){
					v2.pb(j); v1.pb(j);
				}
				k >>= 1;
				j++;
			}
			sort(v1.begin(), v1.end());
			do{
				fg = 1;
				memset(flag, 0, sizeof(flag));
				flag[v1[0]] = 1;
				flag[0] = 1;
				for(j = 1; j < v1.size(); j++){
					if(arr[v1[j - 1]][v1[j]] > 0 && flag[arr[v1[j - 1]][v1[j]]] == 0){
						fg = 0;
						break;
					} 
					flag[v1[j]] = 1;
				}
				res += fg;
			}while(next_permutation(v1.begin(), v1.end()));
			ans[n][m] = res;
		}
		printf("Case #%d: %d\n", p++, res);
	}
	return 0;
}
