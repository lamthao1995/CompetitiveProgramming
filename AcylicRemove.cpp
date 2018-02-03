#define ll long long
#include<bits/stdc++.h>
#define N 505
#define INF 1000000000
using namespace std;
int n, m, in[N], deg[N];
bool a[N][N], vis[N];
void dfs(int x){
	vis[x] = 1;
	for(int i = 1; i <= n; i++){
		if(a[x][i] && !vis[i]){
			--deg[i];
			if(deg[i] <= 0) dfs(i);
		}
	}
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		a[x][y] = 1;
		in[y]++;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			deg[j] = in[j]; vis[j] = 0;
		}
		deg[i]--;
		for(int j = 1; j <= n; j++){
			if(deg[j] <= 0 && !vis[j]) dfs(j);
		}
		bool ok = 0;
		for(int j = 1; j <= n; j++) if(!vis[j]){
			ok = 1;
		}
		if(!ok) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}
int main(void){
	solve();
	return 0;
}
