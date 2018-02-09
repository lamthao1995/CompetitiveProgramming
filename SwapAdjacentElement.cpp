#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
string s;
const int N = 400000;
int arr[N],n;
int main(void){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cin >> s;
	s = s + "0";
	for(int i = 0; i < n;){
		if(s[i] == '0'){
			i++;
			continue;
		}
		int j = i;
		while(j < n && s[j] == '1') j++;
	//	cout << i << "->" << j << endl;
		sort(arr + i, arr + j + 1);
		i = j + 1;
	}
//	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	for(int i = 1; i < n; i++){
		if(arr[i] < arr[i - 1]){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}

