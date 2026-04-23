#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NUM 100
#define MAX 10000
using namespace std;

// const bool debug = false;

int coins[NUM];
int dp[MAX + 1];

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n, target;
    cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // solving
    // dp[0] = 1;
    for(int i = 0; i < n; i++){
        if(coins[i] <= target) dp[coins[i]] = 1;
    }
    for(int i = 0; i <= target; i++){
        for(int j = 0; j < n; j++){
            int next = i + coins[j];
            if(dp[i] && next <= target){
                if(dp[next] != 0) dp[next] = min(dp[next], dp[i] + 1);
                else dp[next] = dp[i] + 1;
            }
        }
    }
    
    // output
    cout << (dp[target] > 0 ? dp[target] : -1);

	return 0;
}

/* comment 



*/