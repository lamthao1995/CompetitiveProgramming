#define pb push_back
const int N  = 100000;
const int LOGN = 20;
#define vi vector<int>
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int count;
	Node *l, *r;
	Node(int c, Node* l_, Node* r_){
		count = c; l = l_; r = r_;
	}
	Node* insert(int l, int r, int w);
};
typedef Node* pnode;
pnode null = new Node(0, NULL, NULL);
map<int, int> mp;
vi adj[N];
int rev[N], G[N], ptr;
int n, q, a, b, x, y;
int depth[N], pa[LOGN][N];
pnode node[N];
Node* Node::insert(int l, int r, int w){
	if(l <= w && w < r){
		if(l + 1 == r){
			return new Node(this->count + 1, null, null);
		}
		int mid = (l + r) >> 1;
		return new Node(this->count + 1, this->l->insert(l, mid, w),
						this->r->insert(mid, r, w));
	}
	return this;
}
void dfs(int cur, int prev = -1, int depth_ = 0){
	pa[0][cur] = prev; 
	depth[cur] = depth_;
	node[cur] = (prev == -1 ? null : node[prev])->insert(0, ptr, mp[G[cur]]);
	for(int v : adj[cur]) if(v != prev){
		dfs(v, cur, depth_ + 1);
	}
}
int LCA(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	for(int i = 0; i < LOGN; i++) if((diff >> i) & 1){
		u = pa[i][u];
	}
	if(u == v) return u;
	for(int i = LOGN - 1; i >= 0; i--) if(pa[i][u] != pa[i][v]){
		u = pa[i][u]; v = pa[i][v];
	}
	return pa[0][u];
}
int query(pnode u, pnode v, pnode lca, pnode plca, int l, int r, int k){
	if(l + 1 == r) return l;
	int mid = (l + r) >> 1; 
	int count = u->l->count + v->l->count - lca->l->count - plca->l->count;
	if(count >= k){
		return query(u->l, v->l, lca->l, plca->l, l, mid, k);
	}
	return query(u->r, v->r, lca->r, plca->r, mid, r, k-count); 
}
int queryFre(pnode u, pnode v, pnode lca, pnode plca, int l, int r, int k){
	if(k < l || k >= r) return 0;
	int count = u->count + v->count - lca->count - plca->count;
	if(l + 1 == r) return count;
	int mid = (l + r) >> 1; 
	return queryFre(u->r, v->r, lca->r, plca->r, mid, r, k) +
		 queryFre(u->l, v->l, lca->l, plca->l, l, mid, k);
}
void answer(int u, int v){
	int lca = LCA(u, v);
	int plca = pa[0][lca];
	int numCity = depth[a] + depth[b] - 2 * depth[lca] + 1;
	int k = numCity / 2 + 1;
	int id = query(node[u], node[v], node[lca], plca == -1 ? null : node[plca], 0, ptr, k);
	int fre = queryFre(node[u], node[v], node[lca], plca == -1 ? null : node[plca], 0, ptr, id);
//	cout << "Fre: " << fre  << " and val: " << rev[id] << " total city: " << numCity<< endl;
	if(fre >= k){
		printf("D %d\n", rev[id]);
		//cout << "D " << rev[id] << endl;
	}else printf("S\n");
}
void init(){
	for(int i = 0; i < n; i++){
		adj[i].clear();
		for(int j = 0; j < LOGN; j++) pa[j][i] = -1;
	}
}
void solve(){
	ptr = 0;
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++) scanf("%d", &G[i]), mp[G[i]];
	for(auto it = mp.begin(); it != mp.end(); it++){
		mp[it->first] = ptr;
		rev[ptr] = it->first;
		ptr++;
	}
	init();
	for(int i = 0; i < n - 1; i++){
		scanf("%d %d", &a, &b);
		adj[a - 1].pb(b - 1); adj[b - 1].pb(a - 1);
	}
	dfs(0);
	for(int i = 1; i < LOGN; i++){
		for(int j = 0; j < n; j++){
			if(pa[i - 1][j] != -1) pa[i][j] = pa[i - 1][pa[i - 1][j]];
		}
	}
	while(q--){
		scanf("%d %d", &a, &b); a--;b--;
		answer(a, b);
	}
}
int main(void){
	null->l = null->r = null;
	solve();
	return 0;
}

