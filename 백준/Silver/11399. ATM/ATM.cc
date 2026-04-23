/** 
* DATE : 230410
* #Greedy
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> P(n);
	for(int i = 0; i < n; i++){
		cin >> P[i];
	}
	
	// solve
	int totalTime = 0;
	sort(P.begin(), P.end());
	for(int i = 0; i < n; i++){
		totalTime += P[i] * (n - i);
	}
	
	cout << totalTime;
	return 0;
}