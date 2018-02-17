#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=4e5+5;
ll lazy[4*M],seg[4*M],ans,val;
int st[M] ,ft[M],c[M] ,mark[M];
int timer=1,n,ql,qr;
vector<int> adj[M];
void dfs(int v){
	mark[timer]=v ,st[v] = timer++;
	for(auto u : adj[v]) if(!st[u]) dfs(u);
	ft[v] = timer;
}
ll build(int l=1,int r=n+1,int id=1){
	if(r-l<=1) return seg[id]=1ll<<c[mark[l]];
	int mid=(l+r)/2;
	return seg[id] = build(l,mid,2*id)|build(mid,r,2*id+1);
}
ll upd(int l=1,int r=n+1,int id=1){
	if(r<=ql || qr<=l) return seg[id];
	if(ql<=l && r<=qr) return seg[id] = lazy[id] = val;
	if(lazy[id]) seg[2*id] = seg[2*id+1] = lazy[2*id] = lazy[2*id+1] = lazy[id] , lazy[id]=0;
	int mid=(l+r)/2;
	return seg[id]= upd(l,mid,2*id)|upd(mid,r,2*id+1);
}
void get(int l=1,int r=n+1,int id=1){
	if(r<=ql || qr<=l) return;
	if(ql<=l && r<=qr){ ans|=seg[id]; return;}
	if(lazy[id]){ ans|=seg[id]; return;}
	int mid = (l+r)/2;
	get(l,mid,2*id);
	get(mid,r,2*id+1);
}
int32_t main()
{
	int m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		adj[u].push_back(v) , adj[v].push_back(u);
	}
	dfs(1);
	build();
	while(m--){
		int f; scanf("%d",&f);
		if(f==1){
			int u,c; scanf("%d%d",&u,&c);
			ql=st[u] , qr=ft[u] , val=1ll<<c , upd();
		}else{
			int v; scanf("%d",&v);
			ans = 0 ,ql =st[v],qr=ft[v] , get();
			int e = __builtin_popcountll(ans);
			printf("%d\n",e);
		}
	}
	return 0;
}
