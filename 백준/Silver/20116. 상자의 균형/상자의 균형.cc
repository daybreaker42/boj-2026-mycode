/** 
DATE : 230429
#brute force, 누적합
*/

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 200001
#define ERROR 0.00001
using namespace std;

int main(){
	fastIO;

	int n, l;
	int xCoords[SIZE] = {0};
	long long curSum[SIZE] = {0};
	cin >> n >> l;
	for(int i = 0; i < n; i++){
		cin >> xCoords[i];
	}

	// solving
	curSum[0] = xCoords[n - 1];
	bool isSuccess = true;
	for(int i = 1; i < n; i++){	// n - 1번 반복, i는 위에있는 상자개수
		int idx = n - i - 1;	// 현재 상자 idx, 위에서 두번째부터 시작(n - 2~ 0)
		int left = xCoords[idx] - l, right = xCoords[idx] + l;
		long double cog = curSum[i - 1] / (double)i;
		if(cog <= left || cog >= right
			|| abs(cog - left) <= ERROR
			|| abs(cog - right) <= ERROR){
			isSuccess = false;
			break;
		}
		curSum[i] = curSum[i - 1] + xCoords[idx];
	}

	if(isSuccess){
		cout << "stable";
	}else{
		cout << "unstable";
	}

  return 0;
}