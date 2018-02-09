#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
int n, arr[100000];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	int ans = 0, l = 1, r = n;
	while(l < r){
		while(arr[l] < arr[r]){
			ans = max(arr[l] * (r - l), ans);
			l++;
		}
		while(arr[l] >= arr[r]){
			ans = max(arr[r] * (r - l), ans);
			r--;
		}
	}
	cout << ans << endl;
}
int main(void){
	int t;
	cin >> t; while(t--) solve();
}
