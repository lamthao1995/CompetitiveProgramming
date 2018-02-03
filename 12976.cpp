#include<bits/stdc++.h>
#define pb push_back
#define fs first
#define inf 0x3f3f3f3f
#define sc second
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pair<int, int> >
#define mp(i,j) make_pair(i,j)
#define pii pair<long long, long long>
using namespace std;
const int lim = 100007;
pii dd[lim];
ll max(ll x, ll y){
	return x > y ? x : y;
}
ll min(ll x, ll y){
	return x < y ? x : y;
}
int main(void){
	ll n, m, t = 1;
	while(cin >> n >> m){
		if(n + m == 0) break;
		for(ll i = 0; i < n; i++){
			cin >> dd[i].fs >> dd[i].sc;
		}
		sort(dd, dd + n);
		ll sos= 0, maxs = -1e15, maxt = -1e15;
		ll maxtt = 0;
		double ans = 1e15;
		double rat = 0;
		for(ll i = 0; i < m; i++){
			sos += dd[i].fs;
			if(maxs <= dd[i].fs){
				if(maxs < dd[i].fs){
					maxs = dd[i].fs;
					maxt = dd[i].sc;
				}else if(maxs == dd[i].fs && maxt < dd[i].sc){
					maxs = dd[i].fs;
					maxt = dd[i].sc;
				}
			}
		}
		for(int i = 0; i < n; i++){
			if(dd[i].fs >= maxs){
				if(dd[i].fs == maxs){
					maxtt = max(maxt, dd[i].sc);
					
				}else{
					maxtt = dd[i].sc;
				}
				rat = 1.0 * maxtt / (1.0 * dd[i].fs);
				sos -= maxs;
				sos += dd[i].fs;
				ans = min(ans, rat * sos);
				sos += maxs;
				sos -= dd[i].fs;
			}
		}
		printf("Case #%lld: %.6lf\n", t++, ans);
	}
	
	return 0;
}
