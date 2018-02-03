#include<bits/stdc++.h>
using namespace std;
typedef struct suffix{
	int index, rank[2];
} suffix;
int compare(suffix a, suffix b){
	return a.rank[0] == b.rank[0] ? 
		(a.rank[1] < b.rank[1] ? 1 : 0) : (a.rank[0] < b.rank[0] ? 1 : 0);
}
int *build(char *txt, int n){
	suffix suffixs[n];
	for(int i = 0; i < n; i++){
		suffixs[i].index = i;
		suffixs[i].rank[0] = txt[i] - 'a';
		suffixs[i].rank[1] = (i + 1 < n) ? (txt[i + 1] - 'a') : -1;
	}
	sort(suffixs, suffixs + n, compare);
	int ind[n];
	for(int k = 4; k < 2 * n; k *= 2){
		int rank = 0;
		int prev_rank = suffixs[0].rank[0];
		ind[suffixs[0].index] = 0;
		for(int i = 1; i < n; i++){
			if(suffixs[i].rank[0] == prev_rank && suffixs[i].rank[1] == suffixs[i - 1].rank[1]){
				prev_rank = suffixs[i].rank[0];
				suffixs[i].rank[0] = rank;
				
			}else{
				prev_rank = suffixs[i].rank[0];
				suffixs[i].rank[0] = ++rank;
			}
			ind[suffixs[i].index] = i;
		}
		for(int i = 0; i < n; i++){
			int nextIndex = suffixs[i].index + k / 2;
			suffixs[i].rank[1] = (nextIndex < n) ? suffixs[ind[nextIndex]].rank[0] : -1;
		}
		sort(suffixs, suffixs + n, compare);
	}
	int *suffixArr = new int[n];
	for(int i = 0; i < n; i++) suffixArr[i] = suffixs[i].index;
	return suffixArr;
}
void printArray(int arr[], int n){
	for(int i = 0; i < n; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main(void){
	char text[] = "banana";
	int n = strlen(text);
	int *suffixArr = build(text, n);
	printArray(suffixArr, n);
	return 0;
}
