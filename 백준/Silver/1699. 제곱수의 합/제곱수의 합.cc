// Baekjoon No. 1699
// Time Complexity 
// #

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main() {
	fastIO
	int n, res, tmp, pivot;
	int i;
	cin >> n;
	vector<int> memory(n + 1, -1);
	memory[0] = 0;
	memory[1] = 1;
	for (i = 2; i <= n; i++) {
		pivot = 1;
		while (i - pivot * pivot >= 0) {
			if (memory[i] < 0 || memory[i] > memory[i - pivot * pivot] + 1) {
				memory[i] = memory[i - pivot * pivot] + 1;
			}
			pivot++;
		}
	}
	
	cout << memory[n];
	return 0;
}