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
#define y second
using namespace std;

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n, d;
		cin >> n >> d;
		psi p[4000];
		map<string, int> m;
		priority_queue<pii, vector<pii>, greater<pii> > pq;
		for(int i = 0; i < n; i++){
			string s;
			int a;
			cin >> s >> a;
			p[i] = mp(a, s);
			pq.push(mp(a, i)); m[s] = a;
			
		}
		for(int i = 0; i < d; i++){
			pii tp = pq.top();
			pq.pop();
			cout << tp.x <<  " " << p[tp.y].y << endl;
			int a = tp.x + p[tp.y].x, b = tp.y;
			pq.push(make_pair(a, b));
		}
	}
	return 0;
}
