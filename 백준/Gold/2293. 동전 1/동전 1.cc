#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NUM 100
#define MAX 10000
using namespace std;

// const bool debug = false;

int dp[MAX + 1];
int coins[NUM];

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n, target;
    cin >> n >> target;
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }

    // solving
    int result = 0;
    sort(coins, coins + n);         // 동전이 오름차순대로 안나오는 경우 방지
    
    dp[0] = 1;
    for (int c_idx = 0; c_idx < n; c_idx++){
        for (int i = 0; i < target; i++){
            if(!dp[i]) continue;
            
            int next = i + coins[c_idx];
            if(next <= target){
                dp[next] += dp[i];
            }
        
        }
    }

    // output    
    cout << dp[target];
    
	return 0;
}