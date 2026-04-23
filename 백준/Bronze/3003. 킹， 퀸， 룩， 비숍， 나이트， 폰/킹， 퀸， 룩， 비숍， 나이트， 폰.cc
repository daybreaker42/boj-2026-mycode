/** 
DATE : 230421
#
*/

#include <bits/stdc++.h>
#define SIZE 6
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int arr[SIZE] = {0}, ans[] = {1, 1, 2, 2, 2, 8};
	
	for(int i = 0; i < SIZE; i++){
		cin >> arr[i];
	}

	for(int i = 0; i < SIZE; i++){
		cout << ans[i] - arr[i] << " ";
	}
	
  return 0;
}