#define ll long long
#define pb push_back
#include<bits/stdc++.h>
const int N = 1001000;
using namespace std;
ll arr[N], _left[N], _right[N];
int n;
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i], _left[i] = _right[i] = -1;
	stack<ll> st;
	for(int i = 1; i <= n; i++){
		while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
		if(st.empty()) _left[i] = -1;
		else _left[i] = st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i = n; i >= 1; i--){
		while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
		if(st.empty()) _right[i] = -1;
		else _right[i] = st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i = 1; i <= n; i++) cout << _left[i] + _right[i] << " ";
	cout << endl;
}
int main(void){
	solve();
	return 0;
}
