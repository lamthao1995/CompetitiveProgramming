#define ll long long
#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
unordered_map<string, int > mp;
unordered_map<int, int > _count;
void solve(){
	int conn = (1 << 10) - 1;
	string s; int n; cin >> n;
	vector<string> vs;
	for(int i = 0; i < n; i++){
		int w = 0; cin >> s; vs.push_back(s);
		for(int i = 0; i < s.size(); i++){
			w |= (1 << (s[i] - '0'));
			if(w == conn) break;
		}
		mp[s] = w;
		_count[w]++;
	}
	ll ans = 0;
	for(int i = 0; i < vs.size(); i++){
		int bit = mp[vs[i]];
		for(int j = 1; j < (1 << 10); j++){
			if((bit | j) == conn){
				if(bit == j){
					ans += (_count[j] - 1);
				}else{
					ans += _count[j];
				}
			}
		}
	}
	cout << ans / 2 << endl;
}
int main(){
	solve();
	return 0;
}
