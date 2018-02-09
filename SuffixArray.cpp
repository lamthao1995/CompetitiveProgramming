#define N 200000
#define LOGN 50
#define pb push_back
#define ll long long
#include<bits/stdc++.h>
using namespace std;
struct _tuple{
	int fs, sc, idx;
};
string s;
int n, sufR[LOGN][N], lcp[N], ra[N], stp;
_tuple suffix[N];
bool cmp(_tuple a, _tuple b){
	if(a.fs != b.fs) return a.fs < b.fs;
	return a.sc < b.sc;
}
int longestCommonPrefix(int i, int j){
	int len = 0;
	if(i == j) return n - i;
	for(int k = stp - 1; k >= 0 && i < n && j < n; k--){
		if(sufR[k][i] == sufR[k][j]){
			i+= (1 << k);
			j += (1 << k);
			len += (1 << k);
		}
	}
	return len;
}
void solve(){
	cin >> s; n = s.size();
	stp = 1;
	for(int i = 0; i < n; i++) sufR[0][i] = s[i] - 'a';
	for(int cnt = 1; cnt < n; cnt *= 2, stp++){
		//cout << stp << " ";
		for(int i = 0; i < n; i++){
			suffix[i].idx = i;
			suffix[i].fs = sufR[stp - 1][i];
			suffix[i].sc = i + cnt < n ? sufR[stp - 1][i + cnt] : -1;
		}
		sort(suffix, suffix + n, cmp);
		sufR[stp][suffix[0].idx]  = 0;
		for(int curR = 0, i = 1; i < n; i++){
			if(suffix[i].fs != suffix[i - 1].fs || suffix[i].sc != suffix[i - 1].sc){
				curR++;
			}
			sufR[stp][suffix[i].idx] = curR;
		}
	}
	//cout << longestCommonPrefix(1, 7) << endl;
	vector<int> hist;
	for(int i = 0; i < n - 1; i++){
		hist.pb(longestCommonPrefix(suffix[i].idx, suffix[i + 1].idx));
	}
	stack<int> st;
	int i = 0, rs = 0;
	while(i < hist.size()){
		if(st.empty() || hist[st.top()] <= hist[i]){
			st.push(i++);
		}else{
			int bar = st.top(); st.pop();
			int area = hist[bar] * (st.empty() ? i + 1 : i - st.top());
			rs = max(rs, area);
		}
	}
	while(!st.empty()){
		int bar = st.top(); st.pop();
		int area = hist[bar] * (st.empty() ? i + 1 : i - st.top());
		rs = max(rs, area);
	}
	cout << max(rs, n) << endl;
}
int main(){
	solve();
	return 0;
}
