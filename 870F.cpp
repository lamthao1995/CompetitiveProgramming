#include<bits/stdc++.h>
#define max 1e7 + 10
bool isPrime[max];
bool isBad[max];
int n;
int numBad;
void init(){
	memset(isPrime, true, sizeof(isPrime));
	isPrime[1] = false; isPrime[0] = false;
	for(int i = 2; i * i < max; i++){
		if(isPrime[i]){
			for(int j = i * i; j < max; j += i){
				isPrime = false;
			}
		}
	}
	
}
void solve(){
	numBad = 0;
	for(int i = 1; i <= n; i++) isBad[i] = false;
	for(int i = 1; i <= n; i++){
		if(i == 1 || isPrime[i] && i * 2 > n){
			isBad = true;
			numBad++;
		}
	}
}
int main(void){
	init();
	
	return 0;
}
