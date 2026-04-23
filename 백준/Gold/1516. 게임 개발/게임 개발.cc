/**
DATE : 230416
#위상정렬
*/

#include <bits/stdc++.h>
#define INF 200000007
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  // 입력 간선 차수 매번 세주는게 아닌, 배열 하나 만들어 거기에 정보 저장
  vector<int> time(n + 1, 0), buildingTime(n + 1, 0), in_edge_num(n + 1, 0);
  vector<vector<int>> edge(n + 1); // 나가는 간선 저장

  for (int i = 1; i <= n; i++) {
    int t, inputIdx;
    cin >> t >> inputIdx;
    buildingTime[i] = t;
    while (inputIdx > 0) {
      // input -> node, 인접행렬 방식, 문제에서 n <= 500이라 가능
      edge[inputIdx].push_back(i);
      in_edge_num[i]++;
      cin >> inputIdx; // 다음번 inputIdx 입력
    }
  }

  // solving
  queue<int> q; // 큐에는 입력 간선 없는 노드만 들어감
  for (int i = 1; i <= n; i++) {
    if (!in_edge_num[i]) {
      q.push(i);
      // time[i] = buildingTime[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    // if(q.empty()) break;	// 사이클 존재 -> 위상정렬 불가능
    int idx = q.front(), prevMaxTime = 0;
    // cout << "방문 - " << idx << endl;
    q.pop();

    // time[idx] 계산
    time[idx] += buildingTime[idx];

    // idx -> j 로 가는 간선 제거했을 때 입력 차수가 0이 되는 노드 idx 큐에 추가
    for (int j = 0; j < edge[idx].size(); j++) {
      int targetIdx = edge[idx][j];
      if (--in_edge_num[targetIdx] == 0) {
        q.push(targetIdx);
      }
      time[targetIdx] = max(time[targetIdx], time[idx]); // 미래에 방문할 예정인 노드엔 이전
    }
		
  }

  for (int i = 1; i <= n; i++) {
    cout << time[i] << "\n";
  }

  return 0;
}