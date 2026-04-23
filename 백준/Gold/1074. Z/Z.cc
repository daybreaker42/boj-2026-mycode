#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int getExecutionOrder(int r, int c, int n, int prevCnt);

int main(){
	fastIO;
	int n, r, c;
	cin >> n >> r >> c;
	int ans = getExecutionOrder(r, c, n, 0);
	cout << ans;
  return 0;
}

int getExecutionOrder(int r, int c, int n, int prevCnt){
	if(n == 1){
		return r * 2 + c + prevCnt;
	}
	int currCnt = 0;
	int newR = r, newC = c, nextArea;
	nextArea = pow(2, 2 * n - 2);
	if(r >= pow(2, n - 1)){
		currCnt += nextArea * 2;
		newR = r - pow(2, n - 1);
	}
	if(c >= pow(2, n - 1)){
		currCnt += nextArea;
		newC = c - pow(2, n - 1);
	}
	currCnt += prevCnt;
	return getExecutionOrder(newR, newC, n - 1, currCnt);
}