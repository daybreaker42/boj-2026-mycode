/**
DATE : 230425
#bfs
*/

#include <bits/stdc++.h>
#define fastIO                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define SIZE 101
using namespace std;

int main() {
  fastIO;
  int n, m;
  cin >> n >> m;
  bool maze[SIZE][SIZE] = {0}, visited[SIZE][SIZE] = {0};
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    for (int j = 1; j <= m; j++) {
      if (str[j - 1] == '1') maze[i][j] = 1;
      else maze[i][j] = 0;
      // maze[i][j] = str[j - 1] - '0';	// << 입력에서 뭐가 문제????
    }
  }

  // solving
  int cnt = 0, xWeight[4] = {-1, 0, 1, 0}, yWeight[4] = {0, -1, 0, 1};
  queue<vector<int>> q; // { x, y, cnt }
  q.push({1, 1, 1});
  while (true) {
    int x = q.front()[0], y = q.front()[1], cnt = q.front()[2];
    q.pop();
    if (visited[y][x]) {
      continue;
    }
    visited[y][x] = true;
    if (x == m && y == n) {
      cout << cnt;
      break;
    }
    for (int i = 0; i < 4; i++) {
      int newX = x + xWeight[i], newY = y + yWeight[i];
      if (newX > 0 && newX <= m && newY > 0 && newY <= n &&
          !visited[newY][newX] && maze[newY][newX]) {
        q.push({newX, newY, cnt + 1});
      }
    }
  }
  return 0;
}
