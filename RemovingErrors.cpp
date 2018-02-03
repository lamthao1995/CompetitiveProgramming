#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
const int N = 200000;
int _stack[N], dtime[N], low[N], comp[N], compNo = 0, _time = 0, sz = 0;
int n, m, q, a, b, _count[N];
vector<int> adj[N];
bool used[N];
void tarzan(int u){
	used[u] = 1;
	_stack[sz++] = u;
	dtime[u] = low[u] = ++_time;
	for(int v : adj[u]){
		if(dtime[v] == -1){
			tarzan(v);
			low[u] = min(low[u], low[v]);
		}else if(used[v]) low[u] = min(low[u], dtime[v]); 
	}
	if(dtime[u] == low[u]){
		int v = -1;
		compNo++;
		do{
			v = _stack[--sz];
			comp[v] = compNo;
			used[v] = 0;
		}while(v != u);
	}
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		adj[i].clear();
		comp[i] = low[i] = used[i] = _stack[i] = 0;
		dtime[i] = -1;
	}
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		adj[a].pb(b);
	}
	for(int i = 1; i <= n; i++) if(dtime[i] == -1){
		tarzan(i);
	}
	for(int i = 1; i <= n; i++){
		_count[comp[i]]++;
	}
//	cout << "In ra ket qua: " << compNo << endl;
	int best = 1;
	for(int i = 1; i <= compNo; i++){
		if(_count[best] < _count[i]) best = i;
	}
//	cout << "===" << _count[best] <<  endl;
	vector<int> rs;
	for(int i = 1; i <= n; i++) if(comp[i] == best){
		rs.pb(i);
	}
	for(int i = 0; i < rs.size(); i++) cout << rs[i] << " ";
	cout << endl;
}
int main(){
	solve();
	return 0;
}
