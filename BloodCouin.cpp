#include <bits/stdc++.h>
#define LOGN 17
#define MAX	131072
using namespace std;

int parent[LOGN][MAX], depth[MAX], start[MAX], finish[MAX], t = 0;
vector<int > g[MAX], store[MAX];

void dfs(int u, int lev)
{
	depth[u] = lev;
	store[lev].push_back(t);
	start[u] = t++;
	for (int i = 0; i < g[u].size(); i++)
		dfs(g[u][i], lev + 1);
	finish[u] = t;
}

int main()
{
	int n, m, v, p;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> parent[0][i];
		g[parent[0][i]].push_back(i);
	}
	dfs(0, 0);
	for (int i = 1; i < LOGN; i++)
		for (int j = 1; j <= n; j++)
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
	cin >> m;
	while (m--)
	{
		cin >> v >> p;
		vector<int > &u = store[depth[v]];
		for (int i = 16; i >= 0; i--)
			if ((p >> i) & 1)
				v = parent[i][v];
		printf("%ld%c", v == 0 ? 0 : lower_bound(u.begin(), u.end(), finish[v]) - lower_bound(u.begin(), u.end(), start[v]) - 1, m ? ' ' : '\n');
	}
	return 0;
}
