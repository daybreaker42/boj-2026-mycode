/** 
DATE : 230506
#dp, graph
*/

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main(){
	fastIO;

	int n, m;
	cin >> n >> m;
	vector<int> shelterNum(n, 0);	// stores maximum number of visiting shelter by each idx
	vector<vector<int>> heights(n);	// stores like {height, idx}
	vector<vector<int>> graph(n);	// 작은거 -> 큰거만 저장하는 방향그래프
	vector<vector<int>> rev_graph(n);	// 자신한테 오는 idx 저장
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		heights[i] = {-t, i};	// 높이 내림차순 정렬
	}
	for(int i = 0; i < m; i++){
		int v, w;	// heights[v] < heights[w], v -> w
		cin >> v >> w;
		if(-heights[v - 1][0] > -heights[w - 1][0]){	// heights 음수로 저장하기 때문에 비교 기준 바꿔줌
			swap(v, w);
		}
		graph[v - 1].push_back(w - 1);
		rev_graph[w - 1].push_back(v - 1);
	}
	// solving
	int stIdx = 0;
	queue<int> q;
	
	// order : descending
	sort(heights.begin(), heights.end());
	
	for(int i = 0; i < n; i++){
		int idx = heights[i][1];
		int maxNum = 0;
		// gets maximum shelter number of previous visits
		for(int j = 0; j < graph[idx].size(); j++){
			int prev_idx = graph[idx][j];
			if(shelterNum[prev_idx] > maxNum){
				maxNum = shelterNum[prev_idx];
			}
		}

		shelterNum[idx] = maxNum + 1;
	}
	
	for(int i = 0; i < n; i++){
		cout << shelterNum[i] << "\n";
	}
	
  return 0;
}