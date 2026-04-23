// BOJ 14562 태권왕
#include <bits/stdc++.h>
#define SIZE 200
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int C;
	cin >> C;
	for(int tc = 0; tc < C; tc++){
		// runs each test case
		int S, T;
		cin >> S >> T;
		
		// solving
		queue<vector<int>> q;
		q.push({S, T, 0});
		while(true){
			vector<int> tmp(q.front());
			q.pop();
			// terminal condition
			if(tmp[0] == tmp[1]){
				cout << tmp[2] << "\n";
				break;
			}
			
			q.push({tmp[0] + 1, tmp[1], tmp[2] + 1});
			if(tmp[0] * 2 <= tmp[1] + 3) q.push({tmp[0] * 2, tmp[1] + 3, tmp[2] + 1});
		}
	}
	return 0;
}