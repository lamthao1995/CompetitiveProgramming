#define ll long long
#define N 5000
#define M 1004
#define sigma 54
#define ms(a,b) memset(a, b, sizeof(a))
#include<bits/stdc++.h>
using namespace std;
int k, states = 1;
string sAr[M], txt;
unordered_set<int> out[M];
int to[N][sigma], link[N];
unordered_set<int> rs;
int buildMachine(){
	for(int i = 0; i < M; i++) out[i].clear();
	ms(to, -1);
	states = 1;
	for(int i = 0; i < k; i++){
		const string& word = sAr[i];
		int curState = 0;
		for(int j = 0; j < word.size(); j++){
			int ch = word[j] >= 'A' ? word[j] - 'A' + 26 : word[j] - 'a';
			if(to[curState][ch] == -1) to[curState][ch] = states++;
			curState = to[curState][ch];
		}
		out[curState].insert(i);
	}
	for(int ch = 0; ch < sigma; ch++){
		if(to[0][ch] == -1) to[0][ch] = 0;
	}
	ms(link, -1);
	queue<int> q;
	for(int ch = 0; ch < sigma; ch++){
		if(to[0][ch] != 0) {
			link[to[0][ch]] = 0;
			q.push(to[0][ch]);
		}
	}
	while(!q.empty()){
		int state = q.front(); q.pop();
		for(int ch = 0; ch < sigma; ++ch){
			if(to[state][ch] == -1) continue;
			int ff = link[state];
			while(to[ff][ch] == -1) ff = link[ff];
			ff = to[ff][ch];
			link[to[state][ch]] = ff;
			for(int vv : out[ff]){
				out[to[state][ch]].insert(vv);
			}
			q.push(to[state][ch]);
		}
	}
	return states;
}
int nextState(int cur, char ch){
	int aw = cur;
	int cc = ch >= 'A' ? ch - 'A' + 26 : ch - 'a';
	while(to[aw][cc] == -1) aw = link[aw];
	return to[aw][cc]; 
}
void solve(){
	cin >> txt >> k;
	bool ans[k];
	ms(ans, false);
	for(int i = 0; i < k; i++) cin >> sAr[i];
	buildMachine();
	int curState = 0;
	rs.clear();
	for(int i = 0; i < txt.size(); i++){
		curState = nextState(curState, txt[i]);
		for(int vv : out[curState]){
			rs.insert(vv);
		}
	}
	for(int i = 0; i < k; i++){
		if(rs.find(i) != rs.end()) printf("y\n");
		else printf("n\n");
	}
}
int main(void){
	 ios_base::sync_with_stdio(0);
     cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
}
