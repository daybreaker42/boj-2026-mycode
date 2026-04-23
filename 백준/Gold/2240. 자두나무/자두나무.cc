#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {

	fastio;

	// freopen("../../input.txt", "r", stdin);
    int t, w;
    cin >> t >> w;

    int prev = 0, num = 0;
    vector<vector<int>> arr(2);             // {{1번나무 떨어지는개수}, {2번나무떨어지는개수}}
    for(int i = 0; i < t; i++){
        int val;
        cin >> val;
        if(i == 0){
            prev = val;
            num++;
        }else if(prev != val){
            // 구간이 끝났을때 - 이전 구간의 개수는 이전 나무 배열에 추가, 다른 나무 배열엔 0 추가
            arr[prev - 1].push_back(num);
            arr[2 - prev].push_back(0);      // 다른 나무
            num = 1;
            prev = val;
        }else{
            num++;
        }
    }
    // 마지막일때
    arr[prev - 1].push_back(num);
    arr[2 - prev].push_back(0);      // 다른 나무

    // solving
    int length = arr[0].size(), currTree = 0; // currTree - 0, 1 -> 나무 1, 2
    vector<vector<int>> dp(length, vector<int>(w + 1));
    for(int j = 0; j <= w; j++){
        currTree = j % 2;
        for(int i = 0; i < length; i++){
            if(j < 1){
                if(i < 2){
                    dp[i][j] += arr[currTree][i];
                }else{
                    dp[i][j] += dp[i - 2][j] + arr[currTree][i];
                }
            }else{
                if(i < 1){
                    dp[i][j] += arr[currTree][i];
                }else if(i < 2){
                    dp[i][j] += dp[i - 1][j - 1] + arr[currTree][i];
                }else{
                    dp[i][j] = max(dp[i - 2][j], dp[i - 1][j - 1]) + arr[currTree][i];
                }
            }
        }
    }

    int maxNum = 0;
    if(length > 1){
        for(int i = 0; i <= w; i++){
            maxNum = max(maxNum, dp[length - 2][i]);
        }
    }
    for(int i = 0; i <= w; i++){
        maxNum = max(maxNum, dp[length - 1][i]);
    }
    cout << maxNum;

	return 0;
}