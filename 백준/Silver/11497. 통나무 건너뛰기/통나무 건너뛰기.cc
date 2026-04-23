// BOJ 11497
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main(int argc, char* argv[]) {
	fastIO;
	int T;
	cin >> T;
	for(int tc = 0; tc < T; tc++){
		int n, minLvl = 0;
		cin >> n;
		vector<int> arr(n);
		vector<int> answer(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		// solving
		sort(arr.begin(), arr.end());
		
		// 홀수는 ceil(n/2)번, 짝수는 n/2번 실행
		for(int i = 0; i < ceil(n / 2.0f); i++){
			answer[i] = arr[i * 2];
		}
		for(int i = 0; i < n/2; i++){
			answer[n - i - 1] = arr[i * 2 + 1];
		}
		
		// minLvl 선정
		for(int i = 0; i < n - 1; i++){
			minLvl = (abs(answer[i+1] - answer[i]) > minLvl) ? abs(answer[i+1] - answer[i]) : minLvl;
		}
		// 첫번째와 마지막 차이만 따로 계산
		minLvl = (abs(answer[n-1] - answer[0]) > minLvl) ? abs(answer[n-1] - answer[0]) : minLvl;
		
		// output
		cout << minLvl << "\n";
	}
	return 0;
}