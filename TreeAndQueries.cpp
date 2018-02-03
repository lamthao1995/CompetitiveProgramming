#include<bits/stdc++.h>
#define N 200000
using namespace std;
struct nd{
	int l, r, id, k;
};
nd q[N];
vector<int> g[N];
int n, m, dv, t, c[N], cc[N], cnt[N], lid[N], l[N], r[N], ans[N];
bool cmp(nd a, nd b){
	if(a.l / dv != b.l / dv) return a.l < b.l;
	return a.r < b.r;
}
void dfs(int v, int p){
	t++; lid[t] = v; l[v] = t;
	for(auto &u : g[v]) if(u != p) dfs(u, v);
	r[v] = t;
}
#define pb push_back
int main(void){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for(int i = 1; i < n; i++){
		int u, v; scanf("%d %d", &u, &v);
		g[u].pb(v); g[v].pb(u);
	}
	t = 0; dfs(1, 0);
	for(int i = 1; i <= m; i++){
		int v, k; scanf("%d %d", &v, &k);
		q[i].l = l[v]; q[i].r = r[v]; q[i].k = k; q[i].id = i;
	}
	dv = (int)sqrt(n);
	sort(q + 1, q + m + 1, cmp);
	int l = 0, r = 0;
	for(int i = 1; i <= m; i++){
		while(l < q[i].l) cc[cnt[c[lid[l++]]]--]--;
		while(l > q[i].l) cc[++cnt[c[lid[--l]]]]++;
		while(r < q[i].r) cc[++cnt[c[lid[++r]]]]++;
		while(r > q[i].r) cc[cnt[c[lid[r--]]]--]--;
		ans[q[i].id] = cc[q[i].k];
	}
	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}
