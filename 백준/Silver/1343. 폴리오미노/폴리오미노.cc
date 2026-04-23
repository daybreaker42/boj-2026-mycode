/** 
* DATE : 230410
* #
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string board;
	cin >> board;
	
	bool isImpossible = false;
	int size = board.length(), count = 0;
	vector<char> answer(size);
	
	for(int i = 0; i < size; i++){
		if(board[i] == 'X'){
			count++;
		}else{
			if(count){
				// 불가능 체크
				if(count % 2 == 1){
					isImpossible = true;
					break;
				}
				// AAAA 입력
				int j;
				for(j = 0; j < count / 4 * 4; j++){
					answer[i - count + j] = 'A';
				}
				// BB 입력
				while(j != count){
					answer[i - count + j] = 'B';
					j++;
				}
			}
			count = 0;
			answer[i] = '.';
		}
		
		// X 다음에 .으로 안끝났을때
		if(i == size - 1){
			// 불가능 체크
			if(count % 2 == 1){
				isImpossible = true;
				break;
			}
			// AAAA 입력
			int j;
			for(j = 0; j < count / 4 * 4; j++){
				answer[i + 1 - count + j] = 'A';
			}
			// BB 입력
			while(j != count){
				answer[i + 1 - count + j] = 'B';
				j++;
			}
		}
	}
	
	if(isImpossible){
		cout << -1;
	}else{
		for(int i = 0; i < size; i++){
			cout << answer[i];
		}
	}
	
	return 0;
}