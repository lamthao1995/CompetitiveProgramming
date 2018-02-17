#define ll long long
#define pb push_back
#define N 1000000
#define fs first
#define sc second
#include<bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
int n, arr[N], x;
void solve(){
	cin >> n;
	pi arrPos[n];
	for(int i = 0; i < n; i++){
		cin >> x;
		arrPos[i].fs = x;
		arrPos[i].sc = i;
	}
	sort(arrPos, arrPos + n);
	vector<bool> vs(n, false);
	int ans1 = 0, ans2 = 0, ans = 0;
	for(int i = 0; i < n; i++){
		if(vs[i] || arrPos[i].sc == i) continue;
		int cycleSize = 0;
		int j = i;
		while(!vs[j]){
			vs[j] = true;
			j = arrPos[j].sc;
			cycleSize++;
		}
		ans1 += (cycleSize - 1);
	}
	vs = vector<bool>(n, false);
	for(int i = 0, j = n - 1; i <= j; i++, j--) swap(arrPos[i], arrPos[j]);
	for(int i = 0; i < n; i++){
		if(vs[i] || arrPos[i].sc == i) continue;
		int cycleSize = 0;
		int j = i;
		while(!vs[j]){
			vs[j] = true;
			j = arrPos[j].sc;
			cycleSize++;
		}
		ans2 += (cycleSize - 1);
	}
	ans = min(ans1, ans2);
	cout << ans << endl;
}
int main(){
	solve();
	return 0;
}
