#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
const int N = 400000;
int arr[N], nextG[N], nextS[N];
void solve(){
	stack<int> st1, st2;
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	arr[0] = -1;
	for(int i = n; i >= 1; i--){
		while(!st1.empty() && arr[st1.top()] >= arr[i]) st1.pop();
		while(!st2.empty() && arr[st2.top()] <= arr[i]) st2.pop();
		if(!st1.empty()) nextG[i] = st1.top();
		if(!st2.empty()) nextS[i] = st2.top();
		st1.push(i);
		st2.push(i); 
	}
	for(int i = 1; i <= n; i++){
		cout << arr[nextG[nextS[i]]] << " ";
	}
}
int main(void){
	solve();
	return 0;
}
