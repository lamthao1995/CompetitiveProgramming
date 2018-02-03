#include<bits/stdc++.h>
using namespace std;
int arr[100000 + 100];
int main(void){
	int n, k;
	cin >> n >> k;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[n];
		sum += arr[n];
	}
	sum += (n - 1);
	if(sum != k){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}
	
	return 0;
}
