/** 
* DATE : 2304010
* #Greedy
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> ropes(n);
	for(int i = 0; i < n; i++){
		cin >> ropes[i];
	}
	
	// solving
	// 정렬한 후, 최댓값부터 로프를 1개씩 선택하며 각 집합의 최솟값 * 로프개수의 최댓값을
	// 찾는 방식
	sort(ropes.begin(), ropes.end());
	int maxWeight = 0;
	for(int i = 0; i < n; i++){
		maxWeight = max(maxWeight, ropes[n - 1 - i] * (i + 1));
	}
	
	cout << maxWeight;
	
	return 0;
}