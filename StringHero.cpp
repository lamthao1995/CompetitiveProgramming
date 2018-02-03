#define ll long long
#define pb push_back
#define vi vector<int>
#include<bits/stdc++.h>
const int N = 200000;
int n, arr[N], ptr, rev[N];
using namespace std;
map<int, int> mp;
struct Node{
	Node *l, *r;
	int count;
	Node(int c, Node* l_, Node* r_){
		count = c; l = l_; r = r_;
	}
	Node* insert(int l, int r, int w);
};
typedef Node* pnode;
pnode node[N];
pnode null = new Node(0, NULL, NULL);
Node* Node::insert(int l, int r, int w){
	if(l <= w && w < r){
		if(l + 1 == r){
			return new Node(this->count + 1, null, null);
		}
		int mid = (l + r) >> 1;
		return new Node(this->count + 1, this->l->insert(l, mid, w),
			this->r->insert(mid, r, w));
	}
	return this;
}
int getFre(pnode cur, pnode prev, int l, int r, int id){
	if(l <= id && id < r){
		if(l + 1 == r){
			return cur->count - prev->count;
		}
		int m = (l + r) >> 1;
		return getFre(cur->l, prev->l, l, m, id)
			+ getFre(cur->r, prev->r, m, r, id);
	}
	return 0;
}
void solve(){
	char s[N];
	scanf("%s", s);
	n = strlen(s);
	int ans = 0;
	for(int i = 0; i < n; i++){
		arr[i] = s[i] - '0';
		if(arr[i] != 0) ans++;
		mp[arr[i]];
	}
	ptr = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		mp[it->first] = ptr;
		rev[ptr] = it->first;
		ptr++;
	}
	node[0] = null;
	for(int i = 0; i < n; i++){
		node[i + 1] = node[i]->insert(0, ptr, mp[arr[i]]);
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int sz = j - i + 1;
			int num0 = 0;
			if(mp.find(0) != mp.end())
				num0 = getFre(node[j + 1], node[i], 0, ptr, mp[0]);
			if(num0 == 0){
				ans++; continue;
			}
			int dis = 0;
			for(int k = 0; k < 10; k++){
				if(mp.find(k) == mp.end()) continue;
				int ff = getFre(node[j + 1], node[i], 0, ptr, mp[k]);
				if(ff > 0) dis++;
			}
			if(1.0 * num0 < 1.0 * sz / dis){
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}
int main(){
	ios_base::sync_with_stdio(false);
	null->l = null->r = null;
	solve();
}
