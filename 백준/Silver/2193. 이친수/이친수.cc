// BOJ 2193
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> memory(n, 0);

	// solving
	memory[0] = 1;
	if (n > 1) memory[1] = 1;

	for (int i = 2; i < n; i++) {
		memory[i] = memory[i - 1] + memory[i - 2];
	}

	// output
	cout << memory[n - 1];

	return 0;
}