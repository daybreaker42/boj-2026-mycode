/**
DATE : 230426~
#dfs

markSector로 구역 표시하고, getSectorNum 등에서는
markSector 이용해서 for문으로 돌면서 영역 수 세야함

적록색약 - 빨, 초 똑같이 보임
*/

#include <bits/stdc++.h>
#define fastIO                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
using namespace std;

// 1~n까지의 인덱스 사용
char board[101][101] = {0};

int getSectorNum(int n, bool isColorWeekness);
void markSector(int n, int x, int y, int visited[][101], bool isColorWeekness);

int main() {
  fastIO;

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    for (int j = 1; j <= n; j++) {
      board[i][j] = str[j - 1];
    }
  }
	
  // solving
	cout << getSectorNum(n, false);
  cout << " ";
  cout << getSectorNum(n, true);

  return 0;
}

// 같은 구역들 표시하면서 구역 수 세어 나가는 함수
int getSectorNum(int n, bool isColorWeekness) {
	int sectorNum = 0;
	int visited[101][101] = {0};
	
  for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(!visited[i][j]){
				markSector(n, j, i, visited, isColorWeekness);
				sectorNum++;
			}
		}
	}
	return sectorNum;
}

// 현재 색깔로 이어진 구역들 표시하는 함수
void markSector(int n, int x, int y, int visited[][101], bool isColorWeekness){
	visited[y][x] = true;
  int xWeight[] = {-1, 0, 1, 0}, yWeight[] = {0, -1, 0, 1};
  
	for (int i = 0; i < 4; i++) {
    int newX = x + xWeight[i], newY = y + yWeight[i];
		if(isColorWeekness){	// 적록색약일 경우
			if (newX > 0 && newX <= n && newY > 0 && newY <= n  
			&& !visited[newY][newX]
			&& ((board[y][x] == board[newY][newX]) || (board[y][x] != 'B' && board[newY][newX] != 'B'))){
				markSector(n, newX, newY, visited, isColorWeekness);
    	}
		}else{
			if (newX > 0 && newX <= n && newY > 0 && newY <= n 
			&& board[newY][newX] == board[y][x] 
			&& !visited[newY][newX]) {
      	markSector(n, newX, newY, visited, isColorWeekness);
    	}
		}
  }
  return;
}