#define ll long
#define N 1000000
#define M 200000
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007, sigma = 26;
int term[M], len[M], to[M][sigma], link[M], sz = 1;
void addStr(string s){
	int cur = 0;
	for(auto c : s){
		if(!to[cur][c - 'a']){
			to[cur][c - 'a'] = sz++;
			len[to[cur][c - 'a']] = len[cur] + 1;
		}
		cur = to[cur][c - 'a'];
	}
	term[cur] = cur;// de lam gi
}
void push_links(){
	int que[sz];
	int st = 0, fi = 1;
	que[0] = 0;
	while(st < fi){
		int v = que[st++];
		int u = link[v];
		if(!term[v]) term[v] = term[u];
		for(int c = 0; c < sigma; c++){
			if(to[v][c]){
				link[to[v][c]] = v ? to[u][c] : 0;
				que[fi++] = to[v][c];
			}else{
				to[v][c] = to[u][c];
			}
		}
	}
}
void buildAhorasick(){
	string ar[6] = {"lam", "mai", "khang", "thao", "tan", "lim"};
	string txt = "lxmaikhangthaoo";
	for(int i = 0; i < 6; i++) addStr(ar[i]);
	for(int i = 0; i < sz; i++) cout << term[i] << " ";
//	for(int i = 0; i < txt.size(); i++){
//		int cur = 0;
//		int ch = txt[i] - 'a';
//		while(to[cur][ch]){
//			cur = to[cur][ch];
//		}
//		cout << len[cur] << endl;		
//	}
}
int main(){
	buildAhorasick();
}
