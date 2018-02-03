#define ll long long
#define pb push_back
#define vi vector<int>
#include<bits/stdc++.h>
const int N = 300;
using namespace std;
bool seen[N];
vector<pair<int,int> >team,chck;
int match[N], n, m, k, speed[N];
vi v[N];
ll dist[N][N];
bool bpm(int idx){
	for(int to : v[idx]){
		if(!seen[to]){
			seen[to] = true;
			if(match[to] == -1 || bpm(match[to])){
				match[to] = idx;
				return true;
			}
		}
	}
	return false;
}
bool check(ll _time){
	int i, j;
	for(i = 0; i < team.size(); i++){
		v[i].clear();
		for(j = 0; j < chck.size(); j++){
			if(_time >= dist[i][j]){
				v[i].pb(j);
			}
		}
	}
	for(i = 0; i < chck.size(); i++){
		match[i] = -1;
		seen[i] = false;
	}
	int match_ = 0;
	for(int i = 0; i < team.size(); i++){
		for(j = 0; j < chck.size(); j++){
			seen[j] = false;
		}
		if(bpm(i)) match_++;
	}
	if(match_ >= k) return true;
	return false;
}
ll solve(){
	ll l = 0, r = 1ll * 1e16;
	ll ans = 0;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(check(mid)){
			ans = mid; r = mid - 1;
		}else l = mid + 1;
	}
	return ans;
}
int main(){
	cin >> n >> m >> k;
	pair<int, int> tmp;
	for(int i = 0; i < n; i++){
		cin >> tmp.first >> tmp.second;
		team.pb(tmp);
	}
	for(int i = 0; i < m; i++){
		cin >> tmp.first >> tmp.second;
		chck.pb(tmp);
	}
	for(int i = 0; i < n; i++) cin >> speed[i];
	for(int i = 0; i < team.size(); i++){
		for(int j=0;j<chck.size();j++){
			ll val,tmp;
			val=(chck[j].first-team[i].first);
			val=val * val;
			tmp=(chck[j].second-team[i].second);
			tmp=tmp*tmp;
			dist[i][j]=val+tmp;
			if(dist[i][j]%speed[j])
			dist[i][j]=(dist[i][j]/speed[i])+1;
			else
			dist[i][j]=dist[i][j]/speed[i];
		}
	}
	cout<<solve()<<endl;
	//fclose(stdout);
	return 0;
}
