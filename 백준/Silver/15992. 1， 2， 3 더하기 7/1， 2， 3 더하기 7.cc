/**
DATE : 230418
#DP
*/
#include <bits/stdc++.h>
#define VAL 1000000009
using namespace std;

int arr[1001][1001] = {0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

	arr[1][1] = 1;
	arr[2][1] = 1;
	arr[3][1] = 1;
	
	for(int i = 2; i <= 1000; i++){
		for(int j = 2; j <= i; j++){
			if(i > 3) {
				arr[i][j] += ((arr[i - 1][j - 1] + arr[i - 2][j - 1]) % VAL + arr[i - 3][j - 1]) % VAL;
			}else if(i > 2) {
				arr[i][j] += (arr[i - 1][j - 1] + arr[i - 2][j - 1]) % VAL;
			}else {
				arr[i][j] += arr[i - 1][j - 1];
			}
			arr[i][j] %= VAL;
		}
	}
	
  while (t > 0) {
    int n, m;
    cin >> n >> m;
    // {사용한 수 : 방법의 수} 배열, m은 사용한 수
    // method #2 - 탑 다운
    cout << arr[n][m] << "\n";

		// for (int i = 0; i <= n; i++) {
		// 	cout << i << " - ";
		// 		for (int j = 0; j <= m; j++) {
		// 			cout << j << " : " << arr[i][j] << " ";
		// 		}
		// 	cout << endl;
		// }
    t--;
  }

  return 0;
}
