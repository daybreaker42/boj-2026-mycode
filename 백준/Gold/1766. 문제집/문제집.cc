#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 32001
using namespace std;

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<int> answer;
    vector<vector<int>> outbound(n + 1);
    vector<int> inboundNum(n + 1, 0);
    
    for(int i = 0; i < m; i++){
        int v, w;
        cin >> v >> w;
        outbound[v].push_back(w);
        inboundNum[w]++;
    }

    // solving
    priority_queue<int> pq; // 오름차순으로 뽑아야 하므로 idx 음수로 저장
    for(int i = 1; i <= n; i++){
        if(inboundNum[i] == 0){
            pq.push(-i);
        }
    }
    while(!pq.empty()){
        int curNum = -pq.top();
        pq.pop();
        answer.push_back(curNum);
        for(int nextIdx = 0; nextIdx < outbound[curNum].size(); nextIdx++){
            int next = outbound[curNum][nextIdx];
            inboundNum[next]--;
            if(inboundNum[next] == 0){
                pq.push(-next);
            }
        }
    }

    // output
    for (int i = 0; i < n; i++){
        cout << answer[i] << " ";
    }
    
	return 0;
}