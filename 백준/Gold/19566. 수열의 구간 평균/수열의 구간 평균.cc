// Baekjoon No. 19566
// Time Complexity
/*
* 
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int main() {
	fastIO
	int n, k;
	int i;
	long long ans, tmp;
	cin >> n >> k;
	vector<long long> arr(n);	// 누적합
	map<long long, long long> m;
	cin >> arr[0];
	for (i = 1; i < n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	
	// solving
	ans = 0;
	for (i = 0; i < n; i++) {
		tmp = arr[i] - (i + 1) * (long long)k;
		ans += m[tmp]++;
	}
	ans += m[0];
	cout << ans;

	return 0;
}