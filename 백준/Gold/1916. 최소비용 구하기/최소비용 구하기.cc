/**
DATE : 230416
#그래프 최소비용 구하기 - dijkstra
*/

#include <bits/stdc++.h>
#define INF 200000007
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, start, end;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n + 1);
  for (int i = 0; i < m; i++) {
    int st, ed, w;
    cin >> st >> ed >> w;
    graph[st].push_back({ed, w}); // graph는 {node, weight} 저장
  }
  cin >> start >> end;

  // solving
  vector<bool> visited(n + 1, 0);
  vector<int> cost(n + 1, INF);
  priority_queue<pair<int, int>> pqueue; // { weight, node } 저장
  pqueue.push({0, start});
  cost[start] = 0;
  while (pqueue.size() > 0) {
    int curIdx = pqueue.top().second;
    pqueue.pop();
		if(!visited[curIdx]){
			for (int i = 0; i < graph[curIdx].size(); i++) {
      int targetIdx = graph[curIdx][i].first, weight = graph[curIdx][i].second;
      // updates cost
      if (!visited[targetIdx] && cost[targetIdx] > cost[curIdx] + weight) {
        cost[targetIdx] = cost[curIdx] + weight;
        pqueue.push({-cost[targetIdx], targetIdx});
      }
      visited[curIdx] = 1;
    }	
		}
  }

  cout << cost[end];
  return 0;
}