#include<bits/stdc++.h>
using namespace std;
const int maxx = 100007;
int n, k, arr[maxx];
void solve(int l, int r, int rBeg, int rEnd){
	if(l + 1 >= r){
		arr[l] = rBeg;
	}else{
		if(k){
			k -= 2;
			int mid = (l + r) / 2;
			int rMid = (rBeg + rEnd) / 2;
			solve(l, mid, rMid + 1, rEnd);
			solve(mid, r, rBeg, rMid); 
		}else{
			for(int i = l, j = rBeg; i < r; i++, j++){
				arr[i] = j;
			}
			
		}
	}
	
}
int main(void){
	int i;
	cin >> n >> k;
	if(k % 2 == 1 || 2 * n < k +1){
		puts("-1");
		return 0;
	}
	k--;
	solve(0, n, 1, n);
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	puts("");
	return 0;
}
