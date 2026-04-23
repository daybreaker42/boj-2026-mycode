// Baekjoon No. 1043 거짓말 - 221102~
// Time Complexity
/*
*
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 51
using namespace std;

// int knowing_status[SIZE + 1] = { 0 };	// 인덱스 1부터 시작
// int party_people[SIZE][SIZE] = { 0 };

int dfs(int idx, int n, vector<vector<int>> &relations, vector<int> &visited, vector<int> &status);
int main() {
	fastIO;
	bool isLieable;
	int n, m, k, tmp, idx, cnt;
	int i, j, l, o;
	cin >> n >> m >> k;
	vector<int> status(n, 0);
	vector<vector<int>> parties(m);
	vector<vector<int>> relations(n, vector<int>(n, 0));
	for (i = 0; i < k; i++) {
		cin >> tmp;
		status[tmp - 1] = 1;
	}
	for (i = 0; i < m; i++) {
		cin >> tmp;
		// party init
		for (j = 0; j < tmp; j++) {
			cin >> idx;
			parties[i].push_back(idx - 1);
		}
		// inits relations
		for (j = 0; j < tmp; j++) {
			for (l = 0; l < tmp; l++) {
				if (j != l) {
					relations[parties[i][j]][parties[i][l]] = 1;
					relations[parties[i][l]][parties[i][j]] = 1;
				}
			}
		}
	}
	// solving
	cnt = 0;
	for (i = 0; i < m; i++) {
		// party의 각 인원 for문으로 돌면서, visited == 0이라면 dfs돌려서 한 명이라도 status == 1인지 판별
		isLieable = true;
		vector<int> visited(n, 0);
		for (j = 0; j < parties[i].size(); j++) {
			if (!visited[parties[i][j]] && dfs(parties[i][j], n, relations, visited, status)) {
				isLieable = false;
				break;
			}
		}
		if (isLieable) cnt++;
	}

	cout << cnt;
	return 0;
}
int dfs(int idx, int n, vector<vector<int>>& relations, vector<int>& visited, vector<int> &status){
	visited[idx] = 1;
	if (status[idx]) return 1;
	for (int i = 0; i < n; i++) {
		if (relations[idx][i] && !visited[i] && dfs(i, n, relations, visited, status)) {
			return 1;
		}
	}
	return 0;
}