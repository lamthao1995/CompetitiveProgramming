#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 1000004
int tree[N];
void update(int idx, int val){
	while(idx < N){
		tree[idx] += val;
		idx += -idx & idx;
	}
}
int query(int idx){
	int sum = 0;
	while(idx > 0){
		sum += tree[idx];
		idx -= idx & -idx;
	}
	return sum;
}
int main(void){
	int n, m, k; cin >> n >> m >> k;
	int ar[n]; for(int i = 1; i <= n; i++) cin >> ar[i - 1];
	sort(ar, ar + n);
	memset(tree, 0, sizeof tree);
	int rs = 0;
	for(int i = 0; i < n; i++){
		int pi = query(ar[i]) - query(ar[i] - m)  + 1;
		//cout << "So dong ho dang chay : " << pi << endl;
		if(pi >= k) rs++;
		else update(ar[i], 1);
	}
	cout << rs << endl;
	return 0;
}
