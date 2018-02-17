#define ll long long
#define pb push_back
#include<bits/stdc++.h>
#define signma 26
#define M 3000
#define N 101000
#define ms(a,b) memset(a, b, sizeof(a))
using namespace std;
int m, n, k, states = 1;
unordered_set<int> out[N], avai;
unordered_map<int,int> rs;
string arr[N], s;
int to[M][signma], link[M];
int buildMachine(){
	states = 1;
	ms(to, -1);
	ms(link, -1);
	for(int i = 0; i < k; i++){
		const string &word = arr[i];
		int state = 0;
		for(int j = 0; j < word.size(); j++){
			int ch = word[j] - 'a';
			if(to[state][ch] == -1) to[state][ch] = states++;
			state = to[state][ch];
		}
		out[state].insert(i);
	}
	queue<int> q;
	for(int ch = 0; ch < signma; ch++){
		if(to[0][ch] == -1){
			to[0][ch] = 0;
		}
	}
	for(int ch = 0; ch < signma; ch++){
		if(to[0][ch] != 0){
			link[to[0][ch]] = 0;
			q.push(to[0][ch]);
		}
	}
	while(!q.empty()){
		int state = q.front(); q.pop();
		for(int ch = 0; ch < signma; ch++){
			if(to[state][ch] == -1) continue;
			int f = link[state];
			while(to[f][ch] == -1) f = link[f];
			f = to[f][ch];
			link[to[state][ch]] = f;
			for(int v : out[f]){
				out[to[state][ch]].insert(v);
			}
			q.push(to[state][ch]);
		}
	}
	return states;
}
int getNum(){
	int sum = 0;
	for(int i = 1; i < s.size(); i++){
		sum = sum * 10 + s[i] - '0';
	}
	return sum;
}
int nextTransition(int cur, char in){
	int ch = in - 'a';
	int aw = cur;
	while(to[aw][ch] == -1) aw = link[aw];
	return to[aw][ch];
}
void solve(){
	cin >> m >> k;
	avai.clear();
	for(int i = 0; i < k; i++) cin >> arr[i], avai.insert(i);
	buildMachine();
	//cout << "HIHI" << endl;
	while(m--){
		cin >> s;
		if(s[0] == '+'){
			int idx = getNum();
			avai.insert(idx - 1);
		}else if(s[0] == '-'){
			int idx = getNum();
			avai.erase(idx - 1);
		}else{
			rs.clear();
			int curState = 0, ans = 0, sum = 0;
			for(int i = 1; i < s.size(); i++){
				curState = nextTransition(curState, s[i]);
				for(int v : out[curState]){
					if(avai.find(v) != avai.end())
						sum++;
				}
			}
			cout << sum << endl;
			
		}
	}
}
int main(void){
	int t = 1;
	while(t--) solve();
	return 0;
}
