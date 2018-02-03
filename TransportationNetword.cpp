#define pb push_back
#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
struct Node{
	int p, r;
};
unordered_set<int> ss;
int n, q, type, x, y;
int sizeRoad[N], sizeRail[N];
Node road[N], rail[N];
int cut = 0;
int find(Node s[], int x){
	if(x != s[x].p) s[x].p = find(s, s[x].p);
	return s[x].p;
}
void _union(Node s[], int x, int y){
	int rX = find(s, x), rY = find(s, y);
	if(s[rX].r > s[rY].r){
		s[rY].p = rX;
	}else if(s[rX].r < s[rY].r){
		s[rX].p = rY;
	}else{
		s[rY].p = rX;
		s[rX].r++;
	}
}
void solve(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		road[i].p = rail[i].p = i;
		road[i].r = rail[i].r = 0;
		sizeRail[i] = sizeRoad[i] = 1;
	}
	bool ok = false;
	while(q--){
		cin >> type >> x >> y; 
		if(type == 1){
			int rX = find(rail, x), rY = find(rail, y);
			if(rX != rY){
				_union(rail, rX, rY);
				int sz = sizeRail[rX] + sizeRail[rY];
				sizeRail[rX] = sizeRail[rY] = sz;
				cut++;
			}
		}else if(type == 2){
			int rX = find(road, x), rY = find(road, y);
			if(rX != rY){
				_union(road, rX, rY);
				int sz = sizeRoad[rX] + sizeRoad[rY];
				sizeRoad[rX] = sizeRoad[rY] = sz;
				cut--;
			}
		}else{
			assert(1 == 2);
		}
		if(cut) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	
}
int main(void){
	solve();
	return 0;
}
