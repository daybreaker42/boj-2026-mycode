/** 
* DATE : 230409
* #Two-Pointer
*/
#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, s;
	cin >> n >> s;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	// solving
	int e = 0, ans = INF;
	long long totalSum = 0;
	for(int st = 0; st < n; st++){
		while(totalSum < s && e < n){
			totalSum += arr[e++];
		}
		if(totalSum >= s){
			ans = min(ans, e - st);
		}
		totalSum -= arr[st];
	}
	
	// output
	if(ans == INF) cout << 0;
	else cout << ans;
	return 0;
}