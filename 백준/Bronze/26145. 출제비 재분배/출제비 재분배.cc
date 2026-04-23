// Baekjoon No. 26145
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int main() {
	fastIO;
	int n, m;
	cin >> n >> m;
	vector<int> money(n + m, 0);
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}
	for (int i = 0; i < n; i++) {
		int elseTotal = 0, tmp;
		for (int j = 0; j < n + m; j++) {
			cin >> tmp;
			if (i != j) {
				money[j] += tmp;
				elseTotal += tmp;
			}
		}
		money[i] -= elseTotal;
	}
	
	// output
	for (int i = 0; i < n + m; i++) {
		cout << money[i] << " ";
	}
	return 0;
}