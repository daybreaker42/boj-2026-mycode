#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 500
using namespace std;

// const bool debug = false;
int m, n;
short board[SIZE][SIZE];
int dp[SIZE][SIZE];

const pair<int, int> delta[] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};

int dfs(int i, int j);

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    cin >> m >> n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    // solving
    // dp[m - 1][n - 1] = 1;
    int ans = dfs(0, 0);

    // output
    cout << ans;

	return 0;
}

int dfs(int i, int j){
    if(dp[i][j] > 0) {
        // 방문한 곳은 다시 체크 x
        return dp[i][j];
    }else if(dp[i][j] < 0){
        return 0;
    }

    if(i == m - 1 && j == n - 1){
        // 목표 도착시
        return 1;
    }

    // int 
    // bool next = false;  // 다음에 갈 곳이 있는지 check
    for(int idx = 0; idx < 4; idx++){
        int nx = j + delta[idx].second, ny = i + delta[idx].first;
        if(0 <= nx && nx < n && 0 <= ny && ny < m && board[i][j] > board[ny][nx]){
            // next = true;
            dp[i][j] += dfs(ny, nx);
        }
    }
    if(dp[i][j] == 0) {
        dp[i][j] = -1;  // 답이 없는 곳은 -1로 체크
        return 0;
    }
    // if(!next) return 0;
    return dp[i][j];
}