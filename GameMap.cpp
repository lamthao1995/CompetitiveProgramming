#include <bits/stdc++.h>
 using namespace std;
 
 typedef  long long ll;
 typedef pair<int, int> ii;
 typedef pair<ll, ll> l4;
 typedef pair<ii, int> iii;
 #define mp make_pair
 #define pb push_back
 
 
 
 const int maxn = 1e5+1;
 int n, m;
 vector<int> g[maxn];
 int d[maxn];
 
 int dp(int cur)
 {
   int &ret = d[cur];
   if (ret == -1)
     {
       ret = 1;
       for (int i = 0; i < g[cur].size(); ++i)
     {
       int nxt = g[cur][i];
       if (g[nxt].size() > g[cur].size())
         ret = max(ret, 1+dp(nxt));
     }
     }
   return ret;
 }
 
 
 int main()
 {
   scanf("%d %d", &n, &m);
   for (int i = 0; i < m; ++i)
    {
      int a, b;
       scanf("%d %d", &a, &b);
       g[a].pb(b);
       g[b].pb(a);
    }
  memset(d, -1, sizeof(d));
  int ans = 1;
  for (int i = 0; i < n; ++i)
     ans = max(ans, dp(i));
  printf("%d\n", ans);
 }
