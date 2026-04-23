/** 
DATE : 230522
#brute force
*/

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 50
using namespace std;

int n, m, chickenNum = 0, houseNum = 0;	// chickenNum >= m
int ans = 0;
int street[SIZE][SIZE] = {0};
vector<pair<int, int>> chickenHouse, house;

int findChickenLength(int x, int y, vector<bool> c);
void comb(int depth, int idx, vector<bool> c);

int main(){
	fastIO;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> street[i][j];
			if(street[i][j] == 1){
				house.push_back({i, j});
				houseNum++;
			}else if(street[i][j] == 2){
				chickenHouse.push_back({i, j});	// y, x 순서로 저장
				chickenNum++;
			}
		}
	}
	// solving
	comb(0, chickenNum - 1, vector<bool>(chickenNum, 0));
	cout << ans;
		
	return 0;
}

/** continues combination process from right end of the array
puts 1 in idx, idx - 1 th array in next process
*/
void comb(int depth, int idx, vector<bool> c){
	if(depth == m){
		int cLengthSum = 0;
		// calculates chickenLength in this case
		for(int i = 0; i < houseNum; i++){
			int x = house[i].second, y = house[i].first;
			cLengthSum += findChickenLength(x, y, c);
		}

		if(!ans || ans > cLengthSum){
			ans = cLengthSum;
		}
		return;
	}
	
	// continues to next case
	// puts i in first left side idx of 1 from the idx
	for(int i = idx; i >= 0; i--){
		if(!c[i]){
			c[i] = 1;
			comb(depth + 1, idx - 1, c);
			c[i] = 0;
			if(i > 0){
				comb(depth, idx - 1, c);	
			}
			break;
		}
	}
	
	return;
}

// returns chickenLength of (x, y)
int findChickenLength(int x, int y, vector<bool> c){
	int length = 0, tmp;
	for(int i = 0; i < chickenNum; i++){
		if(c[i]){	
			// calculates if current chicken house is available
			tmp = abs(chickenHouse[i].first - y) + abs(chickenHouse[i].second - x);
			if(!length || length > tmp){
				length = tmp;
			}	
		}
	}
	return length;
}