#define ll long long
#include<bits/stdc++.h>
using namespace std;
int n, m;
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
map<char, string> mp;
map<string, char> mp1;
string str[1 << 12 + 1];
string cv(string &s){
	string rs = "";
	for(int i = 0; i < s.size(); i++){
		char c = s[i];
		rs = rs + mp[c];
	}
	return rs;
}

bool isValid(int r, int c){
	string s = str[r];
	int idx = c / 4;
	char ss = s[idx];
	string tmp = mp[ss];
	idx = c % 4;
	if(tmp[idx] == '0') return false;
	return true;
}
void dfs(int r, int c){
	if(r < 0 || c < 0 || r >= n || c >= m) return;
	string s = str[r];
	int idx = c / 4;
	char ss = s[idx];
	string tmp = mp[ss];
	idx = c % 4;
	if(tmp[idx] == '0') return;
	tmp[idx] = '0';
	ss = mp1[tmp];
	s[c / 4] = ss;
	str[r] = s;
	for(int i = 0; i < 4; i++){
		int x = dirs[i][0] + r;
		int y = dirs[i][1] + c;
		dfs(x, y);
	}
}

int main(void){
	mp['1'] = "0001"; mp['2'] = "0010"; mp['0'] = "0000"; mp['3'] = "0011"; mp['4'] = "0100"; mp['5'] = "0101"; mp['6'] = "0110";
	mp['7'] = "0111"; mp['8'] = "1000"; mp['9'] = "1001"; mp['A'] = "1010"; mp['B'] = "1011"; mp['C'] = "1100"; mp['D'] = "1101";
	mp['E'] = "1110"; mp['F'] = "1111"; 
	for(map<char,string>::iterator it = mp.begin(); it != mp.end(); it++){
		mp1[it->second] = it->first;
	}
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> str[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(isValid(i, j)){
				dfs(i, j);
				ans++;
			}
			
		}
	}
	cout << ans << endl;
	return 0;
}
