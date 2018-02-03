#include<bits/stdc++.h>
#define mp(a, b) make_pair((a), (b))
#define vi vector<int>
#define pb push_back
#define ll long long
#define mod 1000000007
#define mm 5005
#define psi pair<int, string>
#define pii pair<int, int>
#define x first
#define ui unsigned int
#define y second
using namespace std;
ui On(ui i, ui k){
	return i | ((ui)1 << k);
}
bool check(ui i, ui k){
	return i & ((ui)1 << k);
}
int total1 = 16, total0 = 16;
int main(void){
	int t;
	cin >> t;
	while(t--){
		ui x; cin >> x;
		bool arr[44];
		int ind = 4, t1, t0;
		t1 = t0 = 0;
		for(ui i = 31; (int)i >= 0; i--){
			arr[ind] = check(x, i);
			if(arr[ind]) t1++;
			else t0++;
			ind++;
		}
		if(t1 != total1){
			puts("no");
			continue;
		}
		arr[3] = arr[35]; arr[2] = arr[34];arr[1] = arr[33];arr[0] = arr[32];
		set<ui> ss;
		ui ii = 0;
		for(int i = 0; i <= 31; i++){
			ss.insert(ii++);
		}
		ui tr = 0;
		unsigned idx = 0;
		for(int i =  35, j = 0; j < 5; j++, i--, idx++){
			if(arr[i] == 1){
				tr = On(tr, idx); 
			}
		}
		ss.erase(tr);
		int cur = 30;
		for(int tu = 2; tu < 33; tu++, cur--){
			tr >>= 1;
			if(arr[cur] == 1){
				tr = On(tr, unsigned(4));
			}
			ss.erase(tr);
		}
		if(ss.empty()) puts("yes");
		else puts("no");
	}
	return 0;
}
