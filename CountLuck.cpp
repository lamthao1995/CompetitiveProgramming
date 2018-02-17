#define ll long long
#define N 200
#include<bits/stdc++.h>
using namespace std;
int k, n, m;
int startX, startY, endX, endY;
string matrix[N];
int ans = 0;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
unordered_set<int> vs;
void dfs(int r, int c, int sum){
	if(r == endX && c == endY){
	//	cout << "Sum = " << sum << endl;
		ans = sum;
		return;
	}
	int idx;
	int count = 0;
	for(int i = 0; i < 4; i++){
		int rr = dir[i][0] + r;
		int cc = dir[i][1] + c;
		idx = rr * m + cc;
		if(rr >= 0 && cc >= 0 && rr < n && cc < m && vs.find(idx) == vs.end()){
			if(matrix[rr][cc] == '.' || matrix[rr][cc] == '*'){
				count++;
			}
		}
	}
	int add = 0;
	if(count >= 2) add = 1;
//	cout << sum + add << endl;
	for(int i = 0; i < 4; i++){
		int rr = dir[i][0] + r;
		int cc = dir[i][1] + c;
		idx = rr * m + cc;
		if(rr >= 0 && cc >= 0 && rr < n && cc < m && vs.find(idx) == vs.end()){
			if(matrix[rr][cc] == '.' || matrix[rr][cc] == '*'){
				vs.insert(idx);
				dfs(rr, cc, sum + add);
			}
		}
	}
}
void solve(){
	ans = 0;
	vs.clear();
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> matrix[i];
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == '*'){
				endX = i; endY = j;
			}
			if(matrix[i][j] == 'M'){
				startX = i; startY = j; 
			}
		}
	}
	cin >> k;
	vs.insert(startX * m + startY);
	dfs(startX, startY, 0);
	string rs = k == ans ? "Impressed" : "Oops!";
//	cout << "ANS : " <<  ans << endl;
	cout << rs << endl;
}
int main(){
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
