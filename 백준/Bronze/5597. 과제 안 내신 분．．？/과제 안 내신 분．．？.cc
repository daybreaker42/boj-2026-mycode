/** 
DATE : 230426
#
*/

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
	fastIO;
	int arr[31] = {0};
	for(int i = 0; i < 28; i++){
		int idx;
		cin >> idx;
		arr[idx] = 1;
	}

	for(int i = 1; i <= 30; i++){
		if(!arr[i]){
			cout << i << "\n";
		}
	}

  return 0;
}