#include<bits/stdc++.h>
#define pb push_back
#define fs first
#define sc second
using namespace std;
const int limit = 20008;
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pair<int, int> >
#define mp(i,j) make_pair(i,j)
vpii dd;
vvi w;
int mr[limit], mc[limit], seen[limit], r, c, p;
int findMath(int sc){
	for(int i = 0; i < w[sc].size(); i++){
		if(!seen[w[sc][i]]){
			seen[w[sc][i]] = 1;
			if(mc[w[sc][i]] < 0 || findMath(mc[w[sc][i]])){
				mr[sc] = w[sc][i];
				mc[w[sc][i]] = sc;
				return 1;
			}
		}
	}
	return 0;
}
int bitP(){
	int ct = 0;
	memset(mr,-1, sizeof(mr));
	memset(mc, -1, sizeof(mc));
	for(int i = 1; i <= r; i++){
		memset(seen, 0, sizeof(seen));
		if(findMath(i)) ct++;
	}
	return ct;
}
int main(void){
	int t;
	char cc ;
	int kCase = 1;
	while(cin >> r >> c && (r + c)){
		dd.clear();
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++){
				cin >> cc;
				if(cc == '.'){
					dd.pb(mp(i,j));
				}
			}
		}
		r = dd.size();
		w = vvi(r + 1, vi(0));
		for(int i = 0; i < r; i++){
			for(int j = i + 1; j < r; j++){
				if(abs(dd[i].fs - dd[j].fs) == 0 && abs(dd[i].sc - dd[j].sc) == 1){
					w[i + 1].pb(j + 1);
					w[j + 1].pb(i + 1);
				}
				if(abs(dd[i].fs - dd[j].fs) == 1 && abs(dd[i].sc - dd[j].sc) == 0){
					w[i + 1].pb(j + 1);
					w[j + 1].pb(i + 1);
				}
			}
		}
		int ans = bitP() / 2;
		r  = (r - 2 * ans);
		if(r > 0){
			r = r / 2 + r % 2;
		} else r = 0;
		cout << "Case #" <<kCase++ << ": " << r << endl;
		
	}
	
	return 0;
}
