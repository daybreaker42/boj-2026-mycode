/** 
DATE : 230502
#
*/

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 101
using namespace std;

int arr[SIZE] = {0};

int main(){
	fastIO;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	// solving
	int lastVal = arr[n - 1], ans = 0;
	for(int i = n - 2; i >= 0; i--){
		if(arr[i] > arr[i + 1] - 1){
			ans += arr[i] - (arr[i + 1] - 1);
			arr[i] = arr[i + 1] - 1;
		}
	}
	cout << ans;
  return 0;
}