#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N = 300000;
int a[N], n;
struct Node{
	int val;
	Node *l, *r;
	Node(int v){
		val = v;
		l = r = NULL;
	}
};
typedef Node* pnode;
pnode insert(pnode r, int val){
	if(!r) return new Node(val);
	if(r->val < val){
		r->r = insert(r->r, val);
	}else if(r->val > val){
		r->l = insert(r->l, val);
	}
	return r;
}
ll total;
int maxDepth;
pnode root;
void inorder(pnode r){
	if(!r) return;
	inorder(r->l);
	cout << r->val << " ";
	inorder(r->r);
}
int dfs1(pnode r, int depth_ = 0){
	if(!r) return 0;
	maxDepth = max(depth_, maxDepth);
	int left = dfs1(r->l, depth_ + 1);
	int right = dfs1(r->r, depth_ + 1);
	int dis = max(left, right) + 1;
	total += 1ll * (dis - 1);
	return dis;
}
void solve(){
	total = maxDepth = 0;
	cin >> n;
	root = NULL;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		root = insert(root, a[i]);
	}
	//inorder(root);
	dfs1(root);
	cout << maxDepth << endl;
	cout << total << endl;
}
int main(void){
	solve();
	return 0;
}
