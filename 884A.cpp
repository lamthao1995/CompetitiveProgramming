#include<bits/stdc++.h>
using namespace std;
const int timeA = 86400;
int main(void){
	int n, t;
	cin >> n >> t;
	int arr[n];
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		sum += (timeA - arr[i]);
		if(sum >= t){
			break;
			ans = i + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
