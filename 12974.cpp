#include<bits/stdc++.h>
#define pb push_back
#define fs first
#define inf 0x3f3f3f3f
#define sc second
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pair<int, int> >
#define mp(i,j) make_pair(i,j)
using namespace std;
const int limit = 20008;
const int mod = 1e9 + 7;
const int N = 200000 + 10;
int wa[N], wb[N], wx[N], wv[N];
int cmp(int *r, int a, int b, int c){
	return r[a + c] == r[b + c] && r[a] == r[b]; 
}
void dp(char *r, int *sa, int n, int m){
	int *x = wa, *y = wb, *t;
	int i, j, k, p;
	for(int i = 0; i < m; i++){
		wx[i] = 0;
	}
	for(int i = 0; i < n; i++){
		++wx[x[i] = r[i]];
	}
	for(int i = 1; i < m; i++){
		wx[i] += wx[i - 1];
	}
	for(int i = n - 1; i >= 0; i--){
		sa[--wx[x[i]]] = i;
	}
	for(j = 1, p =1; p < n; j *= 2, m = p){
		for(p = 0, i = n - j; i<n; i++) y[p++] = i;
		for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0; i < n; i++) wv[i] = x[y[i]];
		for(i = 0; i < m; i++) wx[i] = 0;
		for(i = 0; i < n; i++) ++wx[wv[i]];
		for(i = 1; i < m; i++) wx[i] += wx[i - 1];
		for(i = n - 1;i >= 0; i--) sa[--wx[wv[i]]] = y[i];
		for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++){
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++; 
		}
			
		
	}
}
char s[N];
int Rank[N], sa[N], height[N];
void calH(char *r, int n){
	int i, j, k = 0;
	for(i = 1; i <= n; i++) Rank[sa[i]] = i;
	for(i = 0; i < n; height[Rank[i++]] = k){
		if(k) k--;
		else k = 0;
		for(j =  sa[Rank[i] - 1]; r[i + k] == r[j + k]; k++);
	}
}
ll get(int x){
	return 1ll * x * (1 + x) / 2;
}
int min(int x, int y){
	return x < y ? x : y;
}
int main(void){
	int cas = 0;
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> s >> k;
		int len = strlen(s);
		s[len] = 0;
		dp(s, sa, len + 1, 130);
		calH(s, len);
		int mi = inf;
		ll ans = 0, res = 0;
		for(int i = 1; i <= len; i++){
			if(len - sa[i] > k){
				ans += get(len - sa[i] - k) % mod;
				ans %= mod;
			}
			mi = min(mi, height[i]);
			if(mi >= k){
				ans += (1LL * (len - sa[i] - k + 1) * res) % mod;
				ans %= mod;
				res += len - sa[i] - k + 1;
				res %= mod;
			}else{
				mi = height[i];
				if(mi >= k){
					res += (len - sa[i] - k + 1) + (len - sa[i - 1] - k + 1);
					ans += (1ll * (len - sa[i] - k + 1) * (len - sa[i - 1] - k + 1)) % mod;
					ans %= mod;
				}else res = 0;
			}
			
		}
		cout << "Case #" << ++cas << ": " << ans << endl;
	}
	
	return 0;
}
