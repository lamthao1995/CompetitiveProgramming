#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
stack st[12];
int n, m, q, x, k;
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> m;
		while(m--) cin >> x, st[i].push(x);
	}
	cin >> q;
	while(q--){
		cin >> m;
		if(m == 0){
			cin >> k; st[k].pop();
		}else if(m == 1){
			cin >> k >> x; st[k].push(x);
		}else if(m == 2){
			
		}else assert(1 == 2);
	}
}
int main(void){
	
	return 0;
}
