#include<bits/stdc++.h>
#define N 400000
#define pb push_back
using namespace std;
struct node{
	node *l, *r;
	int cnt, prior, val;
	bool rev;
	node(int val){
		this->l = this->r = NULL; this->cnt = 1; this->val = val;
		this->prior = rand() % 1000;
		this->rev = false;
	}
};
typedef node* pnode;
int sz(pnode t){
	return t ? t->cnt : 0;
}
void updz(pnode t){
	if(t) t->cnt = 1 + sz(t->l) + sz(t->r); 
}
void lazy(pnode t){
	if(!t || t->rev == false) return;
	t->rev = false;
	if(t->l) t->l->rev = !t->l->rev;
	if(t->r) t->r->rev = !t->r->rev;
	swap(t->l, t->r);
}
void split(pnode t, pnode &l, pnode&r, int pos, int add = 0){
	lazy(t);
	if(!t) return void(l = r = NULL);
	int curPos = add + sz(t->l);
	if(curPos <= pos) split(t->r, t->r, r, pos, curPos + 1), l = t;
	else split(t->l, l, t->l, pos, add), r = t;
	updz(t);
//	operation(t);
}
void merge(pnode &t, pnode l, pnode r){
	lazy(l); lazy(r);
	if(!l || !r) return void(t = l ? l : r);
	else if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	updz(t);
//	operation(t);
}
void insert(pnode& t, int pos, int val){
	pnode L, R, cur = new node(val);
	split(t, L, R, pos - 1);
	merge(L, L, cur);
	merge(t, L, R);
	
}
int x, n, m, q, t, l, r;
int b[N], ans[N], arr[N], c = 0;
pnode root, L, R, MID, tmp;
void traverse(pnode t){
	if(!t) return;
	lazy(t);
	traverse(t->l);
	arr[c++] = t->val;
	traverse(t->r);
}

void pp(pnode t){
	if(!t) return;
	pp(t->l); cout << t->val << " "; pp(t->r);
}
void printf(pnode t){
	cout << "Duyet mang test " << endl;
	pp(t);
	cout << endl;
} 
void solve(){
	scanf("%d %d %d", &n, &q, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		insert(root, i, x);
	}
	for(int i = 0; i < q; i++){
		scanf("%d %d %d", &t, &l, &r); l--; r--;
		if(t == 1){
			split(root, L, R, l - 1);
			split(R, MID, R, r - l);
			lazy(R); lazy(MID);
		    split(MID, MID, tmp, sz(MID) - 2);
			merge(MID, tmp, MID);
			merge(R, MID, R);
			merge(root, L, R);
		}else{
			split(root, L, R, l - 1);
			split(R, MID, R, r - l);
			MID->rev = !MID->rev;
			merge(R, MID, R);
			merge(root, L, R);
		}
	}
	traverse(root);
	for(int i = 0; i < m; i++){
		scanf("%d", &x); x--;
		b[i] = arr[x];
	}
	for(int i = 0; i < m; i++){
		printf("%d ", b[i]);
	}
}
int main(){
	solve();
	return 0;
}
