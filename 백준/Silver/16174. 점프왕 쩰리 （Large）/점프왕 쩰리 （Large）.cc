/** 
DATE : 230502
# dfs, backtracking
*/

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 66
using namespace std;

short n;
short board[SIZE][SIZE] = {0};
bool visited[SIZE][SIZE] = {0};
// 정답 도달하면 1 return, 없으면 0 return
bool dfs(short x, short y);

int main(){
	fastIO;
	
	cin >> n;
	for(short i = 1; i <= n; i++){
		for(short j = 1; j <= n; j++){
			cin >> board[i][j];
		}
	}

	// solving
	if(dfs(1, 1)){
		cout << "HaruHaru";
	}else{
		cout << "Hing";
	}
	
  return 0;
}

bool dfs(short x, short y){
	short d = board[y][x];
	
	if(d == -1) return 1;
	if(visited[y][x]) return 0;
	if(d == 0){
		visited[y][x] = 1;
		return 0;
	}
	if(x + d <= n && dfs(x + d, y)){
		return 1;
	}
	if(y + d <= n && dfs(x, y + d)){
		return 1;
	}
	visited[y][x] = 1;
	return 0;
}