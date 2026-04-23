// 230409~
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int totalSum = 0, e = 0, ans = 0;
	totalSum = arr[e];
	for(int s = 0; s < n; s++){
		while(totalSum < m && e < n - 1){
			totalSum += arr[++e];
		}
		if(totalSum == m){
			ans++;
		}
		totalSum -= arr[s];
	}
	cout << ans;
	
	return 0;	
}