#include<bits/stdc++.h>
#define ll long long
#define pb push_back
const int N = 200000;
using namespace std;
set<int> s[2];
vector<int> v[2];
int arr[N], n, m, a;
void distSubset(int k, int sum, int id){
	if(v[k].size() <= id) return void(s[k].insert(sum));
	distSubset(k, sum, id + 1);
	distSubset(k, (sum + v[k][id]) % m, id + 1); 
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a, v[i >= n / 2].push_back(a);
	distSubset(1, 0, 0); distSubset(0, 0, 0);
	int rs = 0;
	for(auto& i : s[0]) if(m - i - 1 >= 0){
		rs = max(rs, i + *(--s[1].upper_bound(m - i - 1)));
	}	  
	cout << rs << endl;
}
int main(void){
	solve();
	return 0;
}
