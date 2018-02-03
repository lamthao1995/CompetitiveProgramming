#include<bits/stdc++.h>
using namespace std;
int main(void){
	string s;
	cin >> s;
	int len = s.size();
//	cout << len << endl;
	int i = 0;
	for(i = 0; i < len; i++){
		if(s[i] == '1'){
			break;
		}
	}
	if(i == len){
		cout << "No" << endl;
		return 0;
	}
	int count = 0, j = i + 1;
	for(; j < len; j++){
		if(s[j] == '0') count++;
	}
	//cout << count << endl;
	if(count >= 6){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	
	return 0;
}
