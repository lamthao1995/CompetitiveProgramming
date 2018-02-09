#define N 1000000
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
string a, b,s;
int z[N], n, lenA, lenB;
int solve(){
	cin >> a >> b;
	int l = 0, r = 0;
	lenA = a.size(); lenB = b.size();
	s = a + "#" + b + b;
	n = s.size();
	for(int i = 0; i < n; i++){
		if(i > r){
			l = r = i;
			while(r < n && s[r - l] == s[r]) r++;
			z[i] = r - l;
			r--;
		}else{
			int k = i - l;
			if(k < r - i + 1){
				z[i] = z[k];
			}else{
				l = i;
				while(r < n && s[r - l] == s[r]) r++;
				z[i] = r - l;
				r--;
			}
		}
	}
	bool ok = false;
	for(int i = lenA + 1; i < n; i++){
		if(z[i] == lenA){
			ok = true;
			break;
		} 
	}
	if(ok && lenA == lenB) cout << "1" << endl;
	else cout << "0" << endl;
	return 0;
}
int main(void){
	int t; cin >> t;
	while(t--) solve();
}
