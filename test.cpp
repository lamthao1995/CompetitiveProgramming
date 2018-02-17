#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = 10;
	vector<int> v{1,2};
//	for(int i = 1; i <= n; i++) v.push_back(i);
	reverse(begin(v) + 1, end(v));
	for(int i : v) cout << i << " ";
}
