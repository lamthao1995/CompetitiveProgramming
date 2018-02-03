#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define N 100100
#define LM 20
int n, q, a, b, x, y, root = 0;
int st[N * 8], qt[8 * N];
int chainNo, chainId[N], chainHead[N], posInBase[N];
int ptr, baseArr[N];
vi adj[N], indexx[N];
int subsize[N], pa[LM][N], depth[N], otherEnd[N];
void buildTree(int cur, int s, int e){
	if(s == e - 1) return void(st[cur] = baseArr[s]);
	int c1 = cur << 1, c2 = c1 | 1, m = (s + e) >> 1;
	buildTree(c1, s, m); buildTree(c2, m, e);
	st[cur] = max(st[c1], st[c2]);
}
void updateTree(int cur, int s, int e, int x){
	if(x < s || x >= e) return;
	if(s == x && s == e - 1){
		st[cur] = baseArr[x];
		return;
	}
	int c1 = cur << 1, c2 = c1 | 1, m = (s + e) >> 1;
	updateTree(c1, s, m, x); updateTree(c2, m, e, x);
	st[cur] = max(st[c1], st[c2]);
}
void queryTree(int cur, int s, int e, int S, int E){
	if(s >= E || e <= S) return void(qt[cur] = 0);
	if(s >= S && e <= E) return void(qt[cur] = st[cur]);
	int c1 = cur << 1, c2 = c1 | 1, m = (s + e) >> 1;
	queryTree(c1, s, m, S, E); queryTree(c2, m, e, S, E);
	qt[cur] = max(qt[c1], qt[c2]);
}
int queryUp(int u, int v){
	int uchain, vchain = chainId[v], ans = 0;
	while(1){
		uchain = chainId[u];
		if(uchain == vchain){
			queryTree(1, 0, ptr, posInBase[v], posInBase[u] + 1);
			ans = max(ans, qt[1]);
			break;
		}
		queryTree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u] + 1);
		ans = max(qt[1], ans);
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
	for(int i = LM - 1; i >= 0; i--) if(pa[i][u] != pa[i][v]){
		u = pa[i][u]; v = pa[i][v];
	}
	return pa[0][u];
}
void HLD(int cur, int prev){
	if(chainHead[chainNo] == -1) chainHead[chainNo] = cur;
	chainId[cur] = chainNo;
	posInBase[cur] = ptr;
	baseArr[ptr++] = 0;
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
		if(v != prev && v != sc){
			chainNo++;
			HLD(v, cur);
		}
	}
}
void dfs(int cur, int prev, int depth_ = 0){
	subsize[cur] = 1; pa[0][cur] = prev; depth[cur] = depth_;
	for(int i = 0; i < adj[cur].size() ; i++){
		int v = adj[cur][i];
		if(v != prev){
			dfs(v, cur, depth_ + 1);
			subsize[cur] += subsize[v];
		}
	}
}
void change(int i, int val){
	baseArr[posInBase[i]] += val;
	updateTree(1, 0, ptr, posInBase[i]);
}
void query(int a, int b){
	int lca = LCA(a, b);
	int ans = max(queryUp(a, lca), queryUp(b, lca));
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
		adj[i].clear(); chainHead[i] = -1;
		for(int j = 0; j <= LM; j++) pa[j][i] = -1;
		baseArr[i] = 0;
	}
}
void solve(){
	scanf("%d", &n);
	init();
	for(int i = 1; i < n; i++){
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	dfs(root, -1); HLD(root, -1); buildTree(1, 0, ptr);
	dynamicLCA();
	scanf("%d", &q);
	while(q--){
		char s[10];
		scanf("%s", &s);
		scanf("%d %d", &a, &b);
		if(s[0] == 'I'){
			a--;
			change(a, b);
		}else{
			a--; b--;
			query(a, b);
		}
	}
}
int main(){
	solve();
	return 0;
}