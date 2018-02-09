#define pb push_back
#include<bits/stdc++.h>
using namespace std;
int arr[1000000], n;
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	int prev = -1;
	vector<string> v;
	string s;
	if(arr[0] == 1) v.push_back("0");
	else if(arr[0] > 1){
		s = "0-" + to_string(arr[0] - 1);
		v.push_back(s);
	}
	for(int i = 1; i < n; i++){
		if(arr[i] != arr[i - 1] + 1 && arr[i] > arr[i - 1]){
			if(arr[i] == arr[i - 1] + 2){
				s =  to_string(arr[i - 1] + 1);
			}else s = to_string(arr[i - 1] + 1) + "-" + to_string(arr[i] - 1);
			v.push_back(s);
		}
	}
	if(arr[n - 1] == 98) v.push_back("99");
	else if(arr[n - 1] < 98){
		s = to_string(arr[n - 1] + 1) + "-99";
		v.push_back(s);
	}
	for(int i = 0; i < v.size(); i++){
		if(!i) cout << v[i];
		else cout << "," << v[i];
	}
}
int main(){
	int t; cin >> t; while(t--) solve();
}
