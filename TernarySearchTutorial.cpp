#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
double func(double x){
	return 2.0 * x * x - 12.0 * x + 7.0;
}
double ts(double start, double end){
	double l = start, r= end;
	for(int i = 0; i < 100000; i++){
		double l1 = (l * 2 + r) / 3.0;
		double l2 = (l + r * 2) / 3.0;
		if(func(l1) < func(l2)){
			r = l2;
		}else{
			l = l1;
		}
	}
	return func(l);
}
int main(void){
    int t; cin >> t;
    while(t--){
        double x, y; cin >> x >> y;
        double ans = ts(x, y);
	    printf("%.0f\n", ans);
    }
	
	return 0;
}
