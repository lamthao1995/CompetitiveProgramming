#define N 100100
#define ll long long
#define pb push_backs
#include<bits/stdc++.h>
using namespace std;
struct node{
	node *l, *r, *p;
	int size, rev, id;
	node(int id_, node* p_){
		p = p_; id = id_; l = r = p = NULL; rev = size = 1;
	}
};
typedef node* pnode;
int sz(pnode t){
	return t ? t->size : 0;
}
void updz(pnode t){
	if(t) t->size = 1 + sz(t->l) + sz(t->r);
}
void resolve(pnode t){
	if(!t) return;
	if(t->rev == -1){
		t->rev = 1;
		if(t->l) t->l->rev *= -1;
		if(t->r) t->r->rev *= -1;
		swap(t->l, t->r);
	}
}
void rotate(pnode t){
	pnode p = t->p;
	pnode g = p->p;
	resolve(g); resolve(p); resolve(t);
	if(g){
		if(g->l == p) g->l = t; else g->r = t;
		t->p = g;
	}else t->p = NULL;
	if(p->r == t){
		p->r = t->l;
		if(t->l) t->l->p = p;
		t->l = p;
	}else{
		p->l = t->r;
		if(t->r) t->r->p = p;
		t->r = p;
	}
	p->p = t;
	updz(p); updz(t);
}
void splay(pnode t){
	while(1){
		pnode p = t->p;
		resolve(p);
		if(!p) break;
		pnode g = p->p;
		resolve(g);
		if(!g) rotate(t);
		else if((p->l == t) == (g->l == p)) rotate(p), rotate(t);
		else rotate(t), rotate(t);
	}
}
pnode split(pnode &t, int k){
	if(k == t->size){
		pnode front = t;
		t = NULL;
		return front;
	}
	k++;
	resolve(t);
	int pos = sz(t->l);
	while(pos + 1 != k){
		if(pos >= k) t = t->l;
		else t = t->r, k -= pos + 1;
		resolve(t);
		pos = sz(t->l);
	}
	splay(t);
	pnode front = t->l;
	front->p = t->l = NULL;
	updz(t);
	return front;
}
pnode merge(pnode t1, pnode t2){
	if(!t1 || !t2) return t1 ? t1 : t2;
	resolve(t2);
	while(t2->l){
		t2 = t2->l;
		resolve(t2);
	}
	splay(t2);
	t2->l = t1;
	t1->p = t2;
	updz(t2);
	return t2;
}
