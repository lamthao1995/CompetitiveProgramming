#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
const int N = 1001000;
int nextE[N + 1], arr[N + 1], leftE[N + 1], maxLen[N + 1];
int main(){
	int n; cin >> n; stack<int> st;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	for(int i = n; i >= 1; --i){
		while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
		if(st.empty()) nextE[i] = -1;
		else nextE[i] = st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i = 1; i <= n; i++){
		while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
		if(st.empty()) leftE[i] = 0;
		else leftE[i] = st.top();
		st.push(i);
	}
	for(int i = 1; i <= n; i++) if(nextE[i] != -1){
		maxLen[nextE[i] - i] = max(maxLen[nextE[i] - i], i - leftE[i]);
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans += maxLen[i];
	cout << ans << endl;
	return 0;
}
