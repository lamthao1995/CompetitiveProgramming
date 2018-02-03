#include<bits/stdc++.h>
using namespace std;
#define N 10010
#define LN 14
#define vi vector<int>
vi adj[N], costs[N], indexx[N];
int baseArray[N], ptr;
int chainNo, chainId[N], chainHead[N], posInBase[N];
int depth[N], pa[LN][N], otherEnd[N], subsize[N];
int st[8 * N], qt[8 * N];
void makeTree(int cur, int s, int e){
	if(s == e - 1){
		st[cur] = baseArray[s];
		return;
	}
	int c1 = cur << 1, c2 = c1 | 1, m = (s + e) >> 1;
	makeTree(c1, s, m);
	makeTree(c2, m, e);
	st[cur] = max(st[c1], st[c2]);
	
}
void updateTree(int cur, int s, int e, int x, int val){
	if(s > x || e <= x){
		//x la index can thay the
		return;
	}
	if(s == x && s == e - 1){
		st[cur] = val;
		return;
	}
	int c1 = cur << 1, c2 = c1 | 1, m = (s + e) >> 1;
	updateTree(c1, s, m, x, val);
	updateTree(c2, m, e, x, val);
	st[cur] = max(st[c1], st[c2]);
}
void queryTree(int cur, int s, int e, int S, int E){
	if(s >= E || e <= S){
		qt[cur] = -1;
		return;
	}
	if(e <= E && s >= S){
		qt[cur] = st[cur];
		return;
	}
	int c1 = cur << 1, c2 = c1 | 1, m = (s + e) >> 1;
	queryTree(c1, s, m, S, E);
	queryTree(c2, m, e, S, E);
}
int queryUp(int u, int v){
	if(u == v) return 0;
	int uchain, vchain = chainId[v], ans = -1;
	while(1){
		uchain = chainId[u];
		if(uchain == vchain){
			if(u == v) break;
			queryTree(1, 0, ptr, posInBase[v] + 1, posInBase[u] + 1);
			ans = max(ans, qt[1]);
			break;
		}
		queryTree(1, 0, ptr, posInBase[chainHead[uchain]] + 1, posInBase[u] + 1);
		ans = max(ans, qt[1]);
		u = chainHead[u];
		u = pa[0][u];
	}
	return ans;
}
int LCA(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	for(int i = 0; i < LN; i++) if((diff >> i) & 1){
		u = pa[i][u];
	}
	if(u == v) return u;
	for(int i = LN - 1; i >= 0; i--){
		if(pa[i][u] != pa[i][v]){
			u = pa[i][u]; v = pa[i][v];
		}
	}
	return pa[0][u];
}
void query(int u, int v){
	int lca = LCA(u, v);
	int ans = max(query(lca, u), query(lca, v));
	cout << ans << endl;
}
void change(int i, int val){
	int u = otherEnd[i];
	updateTree(1, 0 , ptr, posInBase[u], val);
}
void HLD(int curNode, int cost, int prev){
	if(chainHead[chainNo] == -1) chainHead[chainNo] = curNode;
	chainId[curNode] = chainNo;
	posInBase[curNode] = ptr;
	baseArray[ptr++] = cost;
	int sc = -1, ncost;
	for(int i = 0; i < adj[curNode].size(); i++){
		if(adj[curNode][i] != prev){
			if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]){
				sc = adj[curNode][i];
				ncost = costs[curNode][i];s
			}
		}
	}
	if(sc != -1){
		HLD(sc, ncost, curNode);
	}
	for(int i = 0; i < adj[curNode].size(); i++){
		if(adj[curNode][i] != prev){
			if(sc != adj[curNode][i]){
				chainNo++;
				HLD(adj[curNode][i], costs[curNode][i], curNode);
			}
		}
	}
}
void dfs(int cur, int prev, int depth_){
	pa[0][cur] = prev;
	depth[cur] = depth_;
	subsize[cur] = 1;
	for(int i = 0; i < adj[cur].size(); i++){
		if(adj[cur][i] != prev){
			otherEnd[indexx[cur][i]] = adj[cur][i];
			dfs(adj[cur][i], cur, depth_ + 1);
			subsize[cur] += subsize[adj[cur][i]];
		}
	}
}
