#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LEN 2187
using namespace std;

void paperNum(int n, pair<int, int>stp);
int board[LEN][LEN] = {0};
int paperNumArr[3] = {0};

int main(){
	fastIO;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}
	paperNum(n, {0, 0});	

	// output
	for(int i = 0; i < 3; i++){
		cout << paperNumArr[i] << "\n";
	}
	return 0;
}

// edp는 영역 끝의 다음 점을 표시
void paperNum(int n, pair<int, int>stp){
	int checker = board[stp.second][stp.first];
	if(n == 1){
		paperNumArr[checker + 1] += 1;
		return;
	}
	int littleN = n / 3;
	bool isSuccess = true;
	for(int i = stp.second; i < stp.second + n; i++){
		if(!isSuccess) break;
		for(int j = stp.first; j < stp.first + n; j++){
			if(board[i][j] != checker){
				isSuccess = false;
				break;
			}
		}
	}
	if(isSuccess){
		paperNumArr[checker + 1] += 1;
		return;
	}
	for(int i = 0; i < n; i += littleN){
		for(int j = 0; j < n; j += littleN){
			paperNum(littleN, {stp.first + j, stp.second + i});
		}
	}
	return;
}