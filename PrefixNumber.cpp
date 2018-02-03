#define ll long long
#include<bits/stdc++.h>
using namespace std;
int fail[400000];
void getP(string s){
	for(int i = 1, k = 0; i < s.size(); i++){
		while(k > 0 && s[i] != s[k]) k = fail[k - 1];
		if(s[i] == s[k]) k++;
		fail[i] = k;
	}
}
int main(){
	string s; cin >> s;
	int ans = 0;
	getP(s);
	for(int i = 1; i < s.size(); i++) cout << fail[i] << " ";
	for(int j = 1, i = 1; j <= s.size() / 2; j++, i += 2){
		if(fail[i] == j) ans++;
		else if(fail[i] > j && s[j] == s[j - 1]) ans++;
	}
	cout << ans << endl;
}
