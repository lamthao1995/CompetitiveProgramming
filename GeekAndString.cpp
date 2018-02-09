#define ll long long
#include<bits/stdc++.h>
using namespace std;
vector<string> v;
struct Node{
	Node* child[26];
	int cnt;
	Node(){
		cnt = 1;
		for(int i = 0; i < 26; i++) child[i] = NULL;
	}
};
typedef Node* pnode;
int n, q;
pnode root;
void add(pnode t, string s){
	for(int i = 0; i < s.size(); i++){
		int idx = s[i] - 'a';
		if(t->child[idx] == NULL) t->child[idx] = new Node();
		else t->child[idx]->cnt++;
		t = t->child[idx];
	}
}
int query(pnode t, string s){
	for(int i = 0; i < s.size(); i++){
		int idx = s[i] - 'a';
		if(t->child[idx] == NULL) return 0;
		else t = t->child[idx];
	}
	return t->cnt;
}
string s;
void solve(){
	delete root;
	root = new Node();
	v.clear();
	pnode t;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		add(root, s);
	}
	cin >> q;
	while(q--){
		cin >> s;
		cout << query(root, s) << endl;
	}
	
}
int main(){
	int t; cin >> t;
	while(t--) solve();
}
