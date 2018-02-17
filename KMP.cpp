#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
void computeLPSArray(char *pat, int m, int *lps){
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while(i < m){
		if(pat[i] == pat[len]){
			lps[i++] = ++len;
		}else{
			if(len){
				len = lps[i - 1];
			}else{
				lps[i++] = 0;
			}
		}
	}
}
void KMPSearch(char *pat, char* txt){
	int m = strlen(pat);
	int n = strlen(txt);
	int lps[m];
	computeLPSArray(pat, m, lps);
	int i = 0, j = 0;
	while(i < n){
		if(pat[j] == txt[i]){
			j++; i++;
		}
		if(j == m){
			printf("Found pattern at index %d\n", i - j);
			j = lps[j - 1];
		}else if(i < n && pat[j] != txt[i]){
			if(j != 0) j = lps[j - 1];
			else i++;
		}
	}
}
void solve(){
	char* pat = "pham";
	char* txt = "phamngoclamngoclampham";
	KMPSearch(pat, txt);
}
int main(void){
	solve();
	return 0;
}
