#include<bits/stdc++.h>
using namespace std;
#define N 100100
#define root 0
#define LM 20
#define INF 9000000
#define vi vector<int>
#define pb push_back
int n, q, a, b, x, y;
vi adj[N], costs[N], indexx[N];
int st[N * 8], qt[8 * N];
int baseArray[N], ptr;
int chainHead[N], chainId[N], posInBase[N], chainNo;
int depth[N], subsize[N], otherEnd[N], pa[LM][N];
void build(int cur, int s, int e){
	if(s == e - 1) return void(st[cur] = baseArray[s]);
	int c1 = cur << 1, c2 = c1 | 1, m = (s + e) >> 1;
	build(c1, s, m); build(c2, m, e);
	st[cur] = min(st[c1], st[c2]);
}
void updateTree(int cur, int s, int e, int x){
	if(x < s || x >= e) return;
	if(s == x && s == e - 1){
		st[cur] = baseArray[x];
		return;
	}
	int c1 = cur << 1, c2 = c1 | 1, m = (s + e) >> 1;
	updateTree(c1, s, m, x); updateTree(c2, m, e, x);
	st[cur] = min(st[c1], st[c2]);
}
void queryTree(int cur, int s, int e, int S, int E){
	if(s >= E || e <= S) return void(qt[cur] = INF);
	if(s >= S && e <= E) return void(qt[cur] = st[cur]);
	int c1 = cur << 1, c2 = c1 | 1, m = (s + e) >> 1;
	queryTree(c1, s, m, S, E); queryTree(c2, m, e, S, E);
	qt[cur] = min(qt[c1], qt[c2]);
}
int queryUp(int u, int v){
	int uchain, vchain = chainId[v], ans = INF;
	while(1){
		uchain = chainId[u];
		if(uchain == vchain){
			queryTree(1, 0, ptr, posInBase[v], posInBase[u] + 1);
			ans = min(ans, qt[1]);
			break;
		}
		queryTree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u] + 1);
		ans = min(qt[1], ans);
		u = chainHead[uchain];
		u = pa[0][u];
	}
	return ans;
}
int LCA(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	for(int i = 0; i < LM; i++) if((diff >> i) & 1){
		u = pa[i][u];
	}
	if(u == v) return u;
	for(int i = LM - 1; i >= 0; --i) if(pa[i][u] != pa[i][v]){
		u = pa[i][u]; v = pa[i][v];
	}
	return pa[0][u];
}
void HLD(int cur, int prev){
	if(chainHead[chainNo] == -1) chainHead[chainNo] = cur;
	chainId[cur] = chainNo;
	posInBase[cur] = ptr;
	baseArray[ptr++] = INF;
	int sc = -1;
	for(int i = 0; i < adj[cur].size(); i++){
		int v = adj[cur][i];
		if(v != prev){
			if(sc == -1 || subsize[sc] < subsize[v]){
				sc = v;
			}
		}
	}
	if(sc != -1) HLD(sc, cur);
	for(int i = 0; i < adj[cur].size(); i++){
		int v = adj[cur][i];
		if(v != sc && v != prev){
			chainNo++;
			HLD(v, cur);
		}
	}
}
void dfs(int cur, int prev, int depth_ = 0){
	depth[cur] = depth_; pa[0][cur] = prev; subsize[cur] = 1;
	for(int i = 0; i < adj[cur].size(); i++){
		int v = adj[cur][i];
		if(v != prev){
			dfs(v, cur, depth_ + 1);
			subsize[cur] += subsize[v];
		}
	}
}
void change(int i){
	int u = posInBase[i]; // INF : white, 0 : black
	if(baseArray[u] != INF){
		baseArray[u] = INF;
	}else baseArray[u] = depth[i];
	updateTree(1, 0, ptr, u);
}
int findTthNode(int p, int t){
//	cout << "Nut : " << p << " voi level : " << t << endl;
	int i, stp;
	for(stp = 1; 1 << stp <= depth[p]; stp++);
	stp--;
	for(i = stp; i >= 0; i--){
		if(depth[p] - (1 << i) >= t){
			p = pa[i][p];
		}
	}
	return p + 1;
}
void query(int ss){
	int ans = queryUp(ss, 0);
	if(ans == INF) ans = -1;
	else {
	//	cout << "Not thu: " << ans << endl;
		ans = findTthNode(ss, ans);
	}
	printf("%d\n", ans);
}
void dynamicLCA(){
	for(int i = 1; i < LM; i++){
		for(int j = 0; j < n; j++){
			if(pa[i - 1][j] != -1) pa[i][j] = pa[i - 1][pa[i - 1][j]];
		}
	}
}
void init(){
	ptr = 0; chainNo = 0;
	for(int i = 0; i <= n; i++){
		adj[i].clear(); chainHead[i] = -1; baseArray[i] = INF;
		for(int j = 0; j < LM; j++) pa[j][i] = -1;
	}
}
void solve(){
	scanf("%d %d", &n, &q);
	init();
	for(int i = 1; i < n; i++){
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	dfs(root, -1); HLD(root, -1); build(1, 0, ptr);
	dynamicLCA();
	while(q--){
		scanf("%d %d", &a, &b);
		b--;
		if(a == 0){
			change(b);
		}else{
			query(b);
		}
	}
}
int main(void){
	solve();
	return 0;
}