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
const int N = 1000002;
int ip[N], hit[N], total = 0;
void pg(int n){
	int z = sqrt(n) + 1; ip[total++] = 2; hit[0] = hit[1] = 1;
	for(int i = 3; i <= z; i++) for(int j = i * i; j <= n; j +=  2 * i) hit[j] = 1;
	for(int i = 3; i <= z; i += 2) if(!hit[i]) ip[total++] = i;
}
ll solve(ll n){
	ll z = sqrt(n) + 1;
	ll ans = 1;
	for(int i = 0; ip[i] <= z && i < total; i++){
		if(n % ip[i] == 0){
			ll p = 1, tmp = 1;
			while(n % ip[i] == 0){
				n /= ip[i];
				p *= ip[i];
				tmp += p;
			}
			z = sqrt(n)  + 1;
			ans *= tmp;
		}
	}
	if(n != 1) ans *= (n + 1);
	return ans;
}
int main(void){
	pg(N - 2);
	int t;
	cin >> t; ll n;
	while(t--){
		cin >> n;
		ll sum = solve(n) - n;
		if(sum < n) puts("deficient");
		else if(sum == n) puts("perfect");
		else puts("abundant");
	}
	return 0;
}
