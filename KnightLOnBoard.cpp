#define pb push_back
#include<bits/stdc++.h>
using namespace std;
int stp[8][2] = {{-1, -2}, {1, 2}, {-1, 2}, {1, -2}, {2, 1}, {-2, 1}, {-2, -1}, {2, -1}};
struct Node{
	int r, c, num;
	Node* prev;
	Node(int r_, int c_){
		num = 0;
		r = r_;
		c = c_;
		prev = NULL;
	}
	Node(int r_, int c_, int move){
		num = 0;
		r = r_;
		c = c_;
		num = move;
		prev = NULL;
	}
};
typedef Node* pnode;
int n, m, a, b;
void solve(){
	cin >> n;
	queue<Node*> q;
	q.push(new Node(0,0));
	unordered_set<int> vs;	
	int ans = -1;
	Node* aw = NULL;
	while(q.empty() == false){
		Node* cur = q.front(); q.pop();
		if(cur->r == n - 1 && cur->c == n - 1){
			ans = cur->num;
			aw = cur;
			break;
		}
		for(int i = 0; i < 8; i++){
			int r = cur->r + stp[i][0];
			int c = cur->c + stp[i][1];
			if(r >= 0 && c >= 0 && r < n && c < n && vs.find(r * n + c) == vs.end()){
				vs.insert(r * n + c);
				Node* newNode = new Node(r, c, cur->num + 1);
				newNode->prev = cur;
				q.push(newNode);
			}
		}
	}
	if(ans == -1){
		cout << -1;
	}else{
		while(aw->n= NULL){
			
		}
	}
}
int main(void){
	solve();
}
