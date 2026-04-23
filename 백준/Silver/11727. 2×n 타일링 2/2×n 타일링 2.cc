#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define NUM 10007
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> memory(n, 0);
	
	// solving
	memory[0] = 1;
	memory[1] = 3;
	
	for (int i = 2; i < n; i++) {
		memory[i] = (memory[i - 1] + 2 * memory[i - 2]) % NUM;
	}

	// output
	cout << memory[n - 1];
	return 0;
}