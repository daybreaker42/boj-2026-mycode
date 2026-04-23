/** 
DATE : 230429
#Add-hoc

*/

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NUM 1000000007
using namespace std;

int main(){
	fastIO;

	int length, ans = 0;
	int power_2[100001] = {0};
	string str;
	cin >> str;
	length = str.length();


	// power_2 배열 초기화
	power_2[0] = 1;
	for(int i = 1; i <= 100000; i++){
		power_2[i] = power_2[i - 1] * (long long)2 % NUM;
	}
	
	for(int i = 0; i < length; i++){
		if(str[i] == 'O'){
			ans += power_2[i];
			ans %= NUM;
		}
	}

	cout << ans;

  return 0;
}