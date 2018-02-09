#define ll long long
#define N 220000
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
string a, s, b;
struct _tuple{
	int idx, fs, sc;
};
_tuple suf[N];
int n, sufR[30][N], K, lenA, lenB, stp;
bool cmp(_tuple a, _tuple b){
	return a.fs != b.fs ? a.fs < b.fs : a.sc < b.sc;
}
int LCP(int i, int j){
	if(i == j) return n - j;
	int len = 0;
	for(int k = stp - 1; k >= 0 && i < n && j < n; k--){
		if(sufR[k][i] == sufR[k][j]){
			i += (1 << k);
			j += (1 << k);
			len += (1 << k);
		}
	}
	return len;
}
void buildSa(){
	stp = 1;
	for(int i = 0; i < n; i++) sufR[0][i] = s[i] - 'a';
	for(int cnt = 1; cnt < n; cnt <<= 1, stp++){
		for(int i = 0; i < n; i++){
			suf[i].idx = i;
			suf[i].fs = sufR[stp - 1][i];
			suf[i].sc = i + cnt < n ? sufR[stp - 1][i + cnt] : -1;
		}
		sort(suf, suf + n, cmp);
		sufR[stp][suf[0].idx] = 0;
		for(int i = 1, curR = 0; i < n; i++){
			if(suf[i].fs != suf[i - 1].fs || suf[i].sc != suf[i - 1].sc){
				curR++;
			}
			sufR[stp][suf[i].idx] = curR;
		}
	}
	int ans = 0;
	for(int i = 0; i < n - 1; i++){
		int lcp = LCP(suf[i].idx, suf[i + 1].idx);
		int i1 = suf[i].idx, i2 = suf[i + 1].idx;
		if(i1 > i2) swap(i1, i2);
		//if(i1 + lcp < K || i2 - lenA - 1 + lcp < K) continue;
	//	if(lcp < K || i1 >= 1 + lenA || i2 <= lenA) continue;
		if(lcp < K) continue;
		ans += (lcp - K + 1);
	}
	cout << ans << endl;
}
void solve(){
	cin >> lenA >> lenB >> K;
	cin >> a >> b;
	s = a + "#" + b;
	n = s.size();
	buildSa();
}
int main(void){
	solve();
	return 0;
}
