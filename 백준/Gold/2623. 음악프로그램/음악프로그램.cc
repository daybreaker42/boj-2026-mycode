#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
/** 주의사항
 * - 인덱스 1부터 시작
 * - 없는건 0으로 표시 
*/

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<int> answer;
    vector<int> inboundNum(n + 1);
    vector<vector<int>> outbound(n + 1);
    for (int i = 0; i < m; i++){
        int num, prev = 0, cur;
        cin >> num;
        for (int j = 0; j < num; j++){
            cin >> cur;
            if(prev > 0){
                inboundNum[cur]++;
                outbound[prev].push_back(cur);
            }
            prev = cur;
        }
    }
    
    // solving
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if(inboundNum[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int target = q.front();
        q.pop();
        answer.push_back(target);
        for (int i = 0; i < outbound[target].size(); i++){
            int next = outbound[target][i];
            inboundNum[next]--;
            if(inboundNum[next] == 0){
                q.push(next);
            }
        }
    }

    // output
    if(answer.size() == n){
        for (int i = 0; i < n; i++){
            cout << answer[i] << "\n";
        }
    }else{
        cout << 0;
    }
	return 0;
}