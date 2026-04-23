#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
	fastio;
	int N, E;
	cin >> N >> E;
	vector<vector<int>> musicStatus(N, vector<int>(E, 0));
	for (int tc = 0; tc < E; tc++) {
		int K;
		bool visited = false;
		cin >> K;
		vector<int> people(K);
		for (int i = 0; i < K; i++) {
			cin >> people[i];
			if (people[i] == 1) visited = true;
		}

		if (visited) {
			// 선영이 참가 -> 새로운 노래 체크
			for (int i = 0; i < K; i++) {
				musicStatus[people[i] - 1][tc] = 1;
			}
		}
		else {
			// 선영 x -> 그동안 아는 노래 공유
			int check;
			for (int i = 0; i < tc; i++) {
				check = 0;
				for (int j = 0; j < K; j++) {
					check = check + musicStatus[people[j] - 1][i];
				}
				if (check > 0) {
					for (int j = 0; j < K; j++) {
						musicStatus[people[j] - 1][i] = 1;
					}
				}
			}
		}
	}

	bool success = false;
	cout << "1\n";
	for (int i = 1; i < N; i++) {
		success = true;
		for (int j = 0; j < E; j++) {
			if (musicStatus[i][j] != musicStatus[0][j]){
				success = false;
				break;
			}
		}
		if(success) cout << i + 1 << "\n";
	}
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < E; j++) {
			cout << musicStatus[i][j] << " ";
		}
		cout << "\n";
	}
	*/
}