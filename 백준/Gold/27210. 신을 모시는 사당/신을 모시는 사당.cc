#include <bits/stdc++.h>
#define INF 100001
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, size;
	cin >> n;
	vector<int> arr(n);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	// solving
	int curValue = 0, totalValue = 0;
	// 왼쪽 먼저
	for(int i = 0; i < n; i++){
		if(arr[i] == 1){
			curValue++;
		}else{
			curValue--;
		}
		if(curValue < 0) curValue = 0;
		totalValue = max(totalValue, curValue);
	}
	curValue = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] == 2){
			curValue++;
		}else{
			curValue--;
		}
		if(curValue < 0) curValue = 0;
		totalValue = max(totalValue, curValue);
	}
	
	cout << totalValue;
	return 0;
}