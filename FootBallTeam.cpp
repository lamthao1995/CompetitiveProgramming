#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
#define N 500100
#define LOGN 23
#define REP(i,j,n) for(ll i=j;i<n;i++)
ll pst[LOGN * N], root[N], L[N * LOGN], R[N * LOGN];
ll ptr = 0;
int power[N], _left[N], _right[N];
void make_tree(int l, int r, int root){
	pst[root] = 0;
	if(l == r) return;
	L[root] = ptr++;
	R[root] = ptr++;
	int mid = (l + r) >> 1, c1 = L[root], c2 = R[root];
	make_tree(l, mid, c1); make_tree(mid + 1, r, c2); 
} 
ll update(int pos, ll x, int l, int h, int root){
	int newRoot = ptr++;
	pst[newRoot] = pst[root];
	if(l == h){
		pst[newRoot] = max(pst[newRoot], x);
		return newRoot;
	}
	L[newRoot] = L[root], R[newRoot] = R[root];
	int mid = (l + h) >> 1, c1 = L[root], c2 = R[root];
	if(pos <= mid){
		L[newRoot] = update(pos, x, l, mid, L[newRoot]);
	}else{
		R[newRoot] = update(pos, x, mid + 1, h, R[newRoot]);
	}
	pst[newRoot] = max(pst[L[newRoot]], pst[R[newRoot]]);
	return newRoot;
}
ll query(int ql, int qh, int l, int h, int root){
	if(ql > h || qh < l || l > h) return 0;
	if(ql <= l && h <= qh) return pst[root];
	int mid = (l + h) >> 1, c1 = L[root], c2 = R[root];
	ll q1 = query(ql, qh, l, mid, c1);
	ll q2 = query(ql, qh, mid + 1, h, c2);
	return max(q1, q2);
}
int main(){
	ptr = 0;
	int n; cin >> n;
	REP(i, 1, n + 1) cin >> power[i];
	REP(i, 1, n + 1) cin >> _left[i];
	REP(i, 1, n + 1) cin >> _right[i];
	ll ans = 0;
	make_tree(0, n + 1, 0);
	REP(i,1,n+1){
		int ind = i - _left[i] - 1;
		ll val = query(0, i, 0, n + 1, root[ind]) + power[i];
		ans = max(ans, val);
		root[i] = update(i + _right[i] + 1, val, 0, n + 1, root[i - 1]);
	}
	cout << ans << endl;
	return 0;
}
