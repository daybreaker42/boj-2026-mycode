#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

bool binSearch(int st, int ed, int n, vector<int>& vec);

int main() {
	fastio;
	int n, m;
	cin >> n;
	map<int, int> cards;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		cards[val]++;
	}
	cin >> m;
	vector<int> checkNumList(m);
	for (int i = 0; i < m; i++) {
		cin >> checkNumList[i];
	}
	// solving
	for (int i = 0; i < m; i++) {
		cout << cards[checkNumList[i]] << " ";
	}
	return 0;
}