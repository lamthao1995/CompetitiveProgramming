#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, a, b; cin >> n; string s, rs; int max_ = 0;
	for(int i = 0; i < n; i++){
		cin >> s >> a >> b;
		if((b - a) > max_){
			max_ = b - a;
			rs = s;
		}
	}
	cout << rs << " "<< max_ << endl;
}
int main(void){
	solve();
	return 0;
}
