#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N = 300000;
int a[N], n, t;
void solve(){
	cin >> n >> t;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	int sum = 0, ans = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		if(sum > t){
			break;
		}else ans++;
	}
	cout << ans << endl;
}
int main(){
	solve();
}
