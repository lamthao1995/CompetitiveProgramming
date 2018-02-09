#define ll long long
#define pb push_back
#include<bits/stdc++.h>
const int N = 1000000;
using namespace std;
string a, b, s;
unordered_map<int, int> mp;
int sufR[40][N + 5], n, q, stp, lenA, k;
struct _tuple{
	int idx, fs, sc;
};
_tuple ss[N];
bool cmp(_tuple a, _tuple b){
	return a.fs != b.fs ? a.fs < b.fs : a.sc < b.sc;
}
void buildSA(){
	stp = 1;
	for(int i = 0; i < n; i++) sufR[0][i] = s[i] - 'a';
	for(int cnt = 1; cnt < n; cnt *= 2, stp++){
		for(int i = 0; i < n; i++){
			ss[i].idx = i;
			ss[i].fs = sufR[stp - 1][i];
			ss[i].sc = i + cnt < n ? sufR[stp - 1][i + cnt] : -1;
		}
		sort(ss, ss + n, cmp);
		sufR[stp][ss[0].idx] = 0;
		for(int i = 1, curR = 0; i < n; i++){
			if(ss[i].sc != ss[i - 1].sc || ss[i].fs != ss[i - 1].fs){
				curR++;
			}
			sufR[stp][ss[i].idx] = curR;
		}
	}
}
void solve(){
	cin >> lenA >> s;
	s = s + s;
	n = s.size();
	buildSA();
	for(int i = 0; i < n; i++) mp[ss[i].idx] = i; 
	cin >> q;
	while(q--){
		cin >> k;
		int idx0 = mp[0];
		int ans = min(idx0 / 2, k);
		cout << ans << endl;
	}
}
int main(void){
	solve();
	return 0;
}
