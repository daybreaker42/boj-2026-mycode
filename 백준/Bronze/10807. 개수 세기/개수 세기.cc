/** 
DATE : 230424
#
*/

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
	fastIO;
	
	int n, v, arr[101];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cin >> v;

	// solving
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] == v) cnt++;
	}
	cout << cnt;

  return 0;
}