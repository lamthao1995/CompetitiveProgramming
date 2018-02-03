#define ll long long
#define fs first
#define sc second
#define N 10100
#define root 0
#define LM 14
#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int> 
using namespace std;
char s[40];
int ptr, baseArray[N];
int chainNo, chainId[N], chainHead[N], posInBase[N];
int depth[N], pa[LM][N], subsizep[N], otherend[N];
vector<int> adj[N], indexx[N], costs[N];
int st[8 * N], qt[8 * N];
void buildTree(int cur, int s, int e){
	if(s == e - 1){
		st[cur] = baseArray[s];
		return;
	}
		//cout << "HIHI" << endl;
	int c1 = cur << 1, c2 = c1 | 1, m = (s + e) >> 1;
	buildTree(c1, s, m); buildTree(c2, m, e);
	st[cur] = st[c1] + st[c2];
}
void update(int cur, int s, int e, int x, int val){
	if(s > x || e <= x) return;
	if(s == x && s == e - 1){
		st[cur] = val;
		return;
	}
		//cout << "HIHI" << endl;
	int c1 = cur << 1, c2 = c1 | 1, m = (s + e) >> 1;
	update(c1, s, m, x, val); update(c2, m, e, x, val);
	st[cur] = st[c1] + st[c2];
}
void queryTree(int cur, int s, int e, int S, int E){
	if(s >= E || e <= S){
		qt[cur] = 0;
		return;
	}
	if(s >= S && e <= E){
		qt[cur] = st[cur];
		return;
	}
		//cout << "HIHI" << endl;
	int c1 = cur << 1, c2 = c1 | 1, m = (s + e) >> 1;
	queryTree(c1, s, m, S, E); queryTree(c2, m, e, S, E);
	qt[cur] = qt[c1] + qt[c2];
}
int queryUp(int u, int v){
	if(u == v) return 0;
	int uchain, vchain = chainId[v], ans = 0;
	while(1){
		//cout << "HIHI" << endl;
		uchain = chainId[u];
		if(uchain == vchain){
			if(u == v) break;
			queryTree(1, 0, ptr, posInBase[v] + 1, posInBase[u] + 1);
			ans += qt[1];
			break;
		}
		queryTree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u] + 1);
		ans += qt[1];
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
	for(int i = LM - 1; i >= 0; i--){
		if(pa[i][u] != pa[i][v]){
			u = pa[i][u]; v = pa[i][v];
		}
	}
	return pa[0][u];
}
void query(int u, int v){
	int lca = LCA(u, v);
	int ans = queryUp(u, lca) + queryUp(v, lca);
	printf("%d\n", ans);
}
void HLD(int cur, int cost, int prev){
	if(chainHead[chainNo] == -1) chainHead[chainNo] = cur;
	chainId[cur] = chainNo;
	posInBase[cur] = ptr;
	baseArray[ptr++] = cost;
	int sc = -1, ncost;
	for(int i = 0; i < adj[cur].size(); i++) if(adj[cur][i] != prev){
		if(sc == -1 || subsizep[sc] < subsizep[adj[cur][i]]){
			sc = adj[cur][i]; ncost = costs[cur][i];
		}
	} 
	if(sc != -1) HLD(sc, ncost, cur);
	for(int i = 0; i < adj[cur].size(); i++){
		if(adj[cur][i] != prev && adj[cur][i] != sc){
			chainNo++;
			HLD(adj[cur][i], costs[cur][i], cur);
		}
	}
	//	cout << "HIHI" << endl;
}
void dfs(int cur, int prev, int depth_ = 0){
	depth[cur] = depth_;
	subsizep[cur] = 1;
	pa[0][cur] = prev;
	for(int i = 0; i < adj[cur].size(); i++) if(adj[cur][i] != prev){
		otherend[indexx[cur][i]] = adj[cur][i];
		dfs(adj[cur][i], cur, depth_ + 1);
		subsizep[cur] += subsizep[adj[cur][i]];
	}
		//cout << "HIHI" << endl;
}
void find(int p, int t){
	int i, stp;
	for(stp = 1; 1 << stp <= depth[p]; stp++);
	stp--;
	for(i = stp; i >= 0; i--){
		if(depth[p] - (1 << i) >= t){
			p = pa[i][p];
		}
	}
	printf("%d\n", (p + 1));
}
void solve(){
	ptr = 0; chainNo = 0;
	int n, u, v, c; scanf("%d", &n);
	for(int i = 0; i <= n; i++){
		indexx[i].clear();
		adj[i].clear(); costs[i].clear();
		chainHead[i] = -1;
		for(int j = 0; j < LM; j++){
			pa[j][i] = -1;
		}
	}
	for(int i = 1; i < n; i++){
		scanf("%d %d %d", &u, &v, &c); u--; v--;
		adj[u].pb(v); adj[v].pb(u);
		indexx[u].pb(i - 1); indexx[v].pb(i - 1);
		costs[u].pb(c); costs[v].pb(c);
	}
	dfs(root, -1);
	HLD(root, -1, -1);
	buildTree(1, 0, ptr);
	for(int i = 1; i < LM; i++){
		for(int j = 0; j < n; j++){
			if(pa[i - 1][j] != -1) pa[i][j] = pa[i - 1][pa[i - 1][j]];
		}
	}
	int a, b, k;
	while(1){
		scanf("%s", &s);
		if(s[0] == 'D' && s[1] == 'O') break;
		else if(s[0] == 'D'){
			scanf("%d %d", &a, &b);
			query(a - 1, b - 1);
		}else{
			scanf("%d %d %d", &a, &b, &k); a--; b--;
			int lca = LCA(a, b);
			if(depth[a] - depth[lca] + 1 >= k){
				find(a, depth[a] - k + 1);
			}else{
				find(b, 2 * depth[lca] + k - depth[a] - 1);
			}
			
		}
	}
}
int main(void){
	int t; scanf("%d", &t);
	while(t--) solve();
	return 0;
}
