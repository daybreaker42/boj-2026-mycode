/** 
DATE : 230502
#
*/

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100001
using namespace std;

int dp[SIZE] = {0};

int main(){
	fastIO;
	int n;
	cin >> n;

	// solving
	dp[2] = 1;
	dp[5] = 1;
	for(int i = 1; i < n; i++){
		if(i + 2 <= n && dp[i] && (!dp[i + 2] || dp[i + 2] > dp[i] + 1)){
			dp[i + 2] = dp[i] + 1;
		}
		if(i + 5 <= n && dp[i] && (!dp[i + 5] || dp[i + 5] > dp[i] + 1)){
			dp[i + 5] = dp[i] + 1;
		}
	}

	if(dp[n]){
		cout << dp[n];
	}else{
		cout << -1;
	}

  return 0;
}