#include<bits/stdc++.h>
const int N = 201;
const int oo = 1000000000;
using namespace std;
int a[N][N], n, m, d, res[N*N], Q[N*N], F[N*N], deg[N];
bool Link[N][N];
 
bool ok(int pos) {
    if (d != m+1) return false;
    for(int i=1; i<=n; i++)
        if (deg[i] & 1) return false;
    int sum = 0;
    for(int i=pos; i<d; i++) {
        sum += a[res[i]][res[i+1]];
        if (sum < 0) return false;
    }
    for(int i=1; i<pos; i++) {
        sum += a[res[i]][res[i+1]];
        if (sum < 0) return false;
    }
    return true;
}
 
int main()
{
    cin >> n >> m;
    int i, u, v, c;
    for(i=1; i<=m; i++) {
        cin >> u >> v >> c;
        Link[u][v] = true; Link[v][u] = true;
        a[u][v] = c; a[v][u] = c;
        deg[u]++; deg[v]++;
    }
    int top = 1; Q[1] = 1;
    while (top) {
        u = Q[top];
        for(v=1; v<=n; v++) {
            if (Link[u][v]) {
                Link[u][v] = Link[v][u] = false;
                Q[++top] = v;
				break;
            }
         }
        if (u == Q[top]) {
            res[++d] = u;
            top--;
        }
    }
    int low = oo, start; F[1] = 0;
    for(i=2; i<=d; i++) {
        F[i] = F[i-1] + a[res[i]][res[i-1]];
        if (F[i] < low) {
            low = F[i]; start = i;
        }
    }
    for(int i = 1; i <= d ; i++) cout << res[i] << " ";
    cout << endl;
    if (!ok(start)) printf("-1");
    else {
        for(i=start; i<=d; i++) printf("%d ", res[i]);
        for(i=2; i<=start; i++) printf("%d ", res[i]);
    }
    return 0;
}
 
