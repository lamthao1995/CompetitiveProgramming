#define ll long long
#define pb push_back
#define mp(a,b) make_pair(a,b)
#include<bits/stdc++.h>
using namespace std;
int n, sr, sc, er, ec, ans;
int d[6][2] = {{-2, -1}, {-2, 1},{0, 2}, {2, 1}, {2, -1}, {0, -2}};
map<pair<int,int> , string> mp;
struct Node{
	Node *prev;
	int r, c, num;
	Node(int r_, int c_){
		r = r_; c = c_;
		num = 0;
		prev = NULL;
	}
	Node(int r_, int c_, int num_){
		r = r_; c = c_;
		num = num_;
		prev = NULL;
	}
};
void solve(){
	cin >> n >> sr >> sc>>er>>ec;
	ans = -1;
	unordered_set<int> vs;
	queue<Node*> q;
	q.push(new Node(sr, sc));
	Node* aw = NULL;
	vs.insert(sr * n + sc);
	while(!q.empty()){
		Node* cur = q.front(); q.pop();
		if(cur->r == er && cur->c == ec){
			ans = cur->num;
			aw = cur;
			break;
		}
		for(int i = 0; i < 6; i++){
			int r = cur->r + d[i][0];
			int c = cur->c + d[i][1];
			int tmp = r * n + c;
			if(r >= 0 && c >= 0 && r < n && c < n && vs.find(tmp) == vs.end()){
				vs.insert(tmp);
				Node* newNode = new Node(r,c,cur->num + 1);
				newNode->prev = cur;
				q.push(newNode);
			}
		}
	}
	if(ans == -1){
		cout << "Impossible" << endl;
	}
	else{
		cout << ans << endl;
		vector<string> v;
		while(aw->prev != NULL){
			pair<int,int> p = mp(aw->r - aw->prev->r, aw->c - aw->prev->c);
			v.pb(mp[p]);
			aw = aw->prev;
		}
		for(int i = v.size() - 1; i >= 0;i--){
			cout << v[i] << " ";
		}
	}
}
int main(void){
	mp[mp(-2,-1)] = "UL";
	mp[mp(-2,1)] = "UR";
	mp[mp(2,-1)] = "LL";
	mp[mp(2,1)] = "LR";
	mp[mp(0,2)] = "R";
	mp[mp(0,-2)] = "L";
	solve();
	return 0;
}
