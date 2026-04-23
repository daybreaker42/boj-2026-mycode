#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NUM 100000

using namespace std;

int main() {
	fastio;
	int n;
	cin >> n;
	vector<int> honor(n);
	for (int i = 0; i < n; i++) {
		cin >> honor[i];
	}

	// solving
	int standard = 1;
	long long ans = 0;
	// 1. 수열을 정렬함
	sort(honor.begin(), honor.end());
	// 2. 돌면서 i번째 수에서 i + 1의 수를 각각 빼고, 같다면 넘김.
	for (int i = 0; i < n; i++) {
		// standard + 1 -> 원래 되어야 하는 숫자
		if (honor[i] == standard - 1) continue;
		ans += honor[i] - standard;
		standard++;
	}

	cout << ans;
	return 0;
}