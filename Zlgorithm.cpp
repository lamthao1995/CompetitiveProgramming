#define ll long long
#include<bits/stdc++.h>
using namespace std;
int z[2000007];
void buildZ(string s){
	int L = 0, R = 0;
	for(int i = 1; i < s.size(); i++){
		if(i > R){
			L = R = i;
			while(R < s.size() && s[R - L] == s[R]){
				R++;
			}
			z[i] = R - L;
			R--;
		}else{
			int k = i - L;
			if(z[k] < R - i + 1){
				z[i] = z[k];
			}else {
				L = i;
				while(R < s.size() && s[R - L] == s[R]){
					R++;
				}
				z[i] = R - L;
				R--;
			}
		}
	}
}
int solve(void){
	string a, b; cin >> a >> b;
	int lenA = a.size();
	a = a + "$" + b + b.substr(0, b.size() - 1);
	buildZ(a);
	int rs = 0;
	for(int i = 1; i < a.size(); i++){
		if(z[i] == lenA) rs++;
	}l
	cout << rs << endl;
	
	return 0;
}
int main(){
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
