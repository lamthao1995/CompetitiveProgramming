#define ll long long
#define N 300000
#include<bits/stdc++.h>
using namespace std;
int n, h[N], pos[N];
pair<int,int> pp[N];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> pos[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> h[i];
		pp[i].first = pos[i];
		pp[i].second = h[i];
	}
	sort(pp + 1, pp + n + 1);
	bool right = true, left = true;
	for(int i = 1; i < n; i++){
		if(pp[i].first + pp[i].second >= pp[i + 1].first){
			right = false;
		}
		if(pp[i + 1].first + pp[i + 1].second >= pp[i].first){
			left = false;
		}
	}
	string rs = "NONE";
	if(left && right){
		rs = "BOTH";
	}else if(left){
		rs = "LEFT";
	}else if(right){
		rs = "RIGHT";
	}
	cout << rs << endl;
}
int main(){
	int t = 1;
	while(t--) solve();
	return 0;
}
