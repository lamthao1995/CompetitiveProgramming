#define ll long long
#define pb push_back
#define N 100000
#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int v, flow, c, rev;
};
vector<Edge> adj[N];
void addEdge(int u, int v, int c){
	Edge a{v, 0, c, adj[v].size()};
	Edge b{u, 0, 0, adj[u].size()};
	adj[u].pb(a); adj[v].pb(b);
}
int main(void){
	return 0;
}

