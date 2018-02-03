#define ll long long int
#define pb push_back
#define N 300000
#include<bits/stdc++.h>
using namespace std;
unordered_set<int> ss;
int n, m, a, b;
int cycle[N];
ll subsize[N];
ll help;
struct Node{
	int r, p;
};
Node node[N];
bool cmp(int x, int y){
	return subsize[x] < subsize[y];
}
int find(int x){
	if(x != node[x].p){
		node[x].p = find(node[x].p);
	}
	return node[x].p;
}
ll get(ll x){
	ll rrr =  (x - 1ll) * x * (x + 1ll);
	return rrr / 3;
}
void _union(int x, int y, bool ok){
	int rootX = find(x), rootY = find(y);
	if(rootX == rootY){
		cycle[rootX]++;
		return;
	}
	if(node[rootX].r > node[rootY].r){
		node[rootY].p = rootX;
	}else if(node[rootX].r < node[rootY].r){
		node[rootX].p = rootY;
	}else{
		node[rootY].p = rootX;
		node[rootX].r++;
	}
	ll size = subsize[rootX] + subsize[rootY];
	subsize[rootX] = size, subsize[rootY] = size;
	int sz = cycle[rootX] + cycle[rootY];
	cycle[rootX] = cycle[rootY] = sz;
}
void solve(){
	ss.clear();
	ll ans = 0;
	cin >> n >> m;
	help = 0;
	for(int i = 1; i <= n; i++) subsize[i] = 1ll, node[i].p = i, node[i].r = cycle[i] = 0;
	vector<int > vv;
	while(m--){
		cin >> a >> b;
		_union(a, b, false);
	}
	for(int i = 1; i <= n; i++){
		int r = find(i);
		if(ss.find(r) == ss.end()){
			ss.insert(r);
			vv.pb(r);
		}
	}
	ll tmp = 0;
	sort(vv.begin(), vv.end(), cmp);
	int cy = 0;
	for(int i = vv.size() - 1; i >= 0; i--){
		if(subsize[vv[i]] == 1) break; 
		cy += cycle[vv[i]];
		ll sz = subsize[vv[i]];
		help += sz * (sz - 1);
		ans += get(sz) + (sz - 1) * tmp;
		tmp += get(sz);
	}
	ans += help  * cy;
	cout << ans << endl;
}
int main(void){
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
