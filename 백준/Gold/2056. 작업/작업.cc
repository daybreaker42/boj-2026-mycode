#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 10000
using namespace std;

// const bool debug = false;

int dp[SIZE];
int work_time[SIZE];
int sub_work_num[SIZE];
int sub_works[SIZE][100];

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> work_time[i];
        cin >> sub_work_num[i];
        for (int j = 0; j < sub_work_num[i]; j++){
            cin >> sub_works[i][j];
            sub_works[i][j]--;
        }
        sort(sub_works[i], sub_works[i] + sub_work_num[i]);
    }

    // solving
    int ans = 0;
    // dp[i] - i번 작업을 완료하는데 걸리는 시간
    for (int i = 0; i < n; i++){
        // 1. 먼저 현재 작업을 하는데 걸리는 시간 추가
        dp[i] += work_time[i];
        // 2. 이전 작업을 하는데 걸리는 시간 중 가장 긴 시간을 구함
        int maxTime = 0;
        for(int j = 0; j < sub_work_num[i]; j++){
            int prev = sub_works[i][j];
            maxTime = max(maxTime, dp[prev]);
        }
        // 가장 긴 시간 추가
        dp[i] += maxTime;
    }
    

    // output
    ans = dp[0];
    for(int i = 1; i < n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;

	return 0;
}

/* comment 



*/