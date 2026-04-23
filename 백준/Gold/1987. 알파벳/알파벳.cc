#include <bits/stdc++.h>
using namespace std;

int r, c;
char board[20][20];
bool isUsed[26] = {0};

int dfs(int x, int y, int cnt);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> board[i][j];
    }
  }

  // dfs코드
  cout << dfs(0, 0, 0);
}

int dfs(int x, int y, int cnt) {
  int currentVal = ++cnt;
  int xWeight[] = {-1, 0, 1, 0}, yWeight[] = {0, -1, 0, 1};
  isUsed[board[y][x] - 'A'] = 1;
  if (26 == currentVal)
    return currentVal;

  for (int i = 0; i < 4; i++) {
    if (x + xWeight[i] >= 0 && x + xWeight[i] < c && y + yWeight[i] >= 0 && y + yWeight[i] < r &&
        !isUsed[board[y + yWeight[i]][x + xWeight[i]] - 'A']) {
      cnt = max(cnt, dfs(x + xWeight[i], y + yWeight[i], currentVal));
      isUsed[board[y + yWeight[i]][x + xWeight[i]] - 'A'] = 0;
    }
  }

  return cnt;
}