/** 
DATE : 230429
#brute force
*/

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000
using namespace std;

int main(){
	fastIO;

	int n;
	int loc[SIZE] = {0}, length[SIZE] = {0};
	char color[SIZE];

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> loc[i];	
	}
	for(int i = 0; i < n; i++){
		cin >> length[i];
	}
	for(int i = 0; i < n; i++){
		cin >> color[i];
	}

	// solving
	bool isSuccess = false;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(loc[j] - loc[i] <= length[i] + length[j] && color[i] != color[j]){
				isSuccess = true;
				cout << "YES\n" << i + 1 << " " << j + 1;
				break;
			}
		}
		if(isSuccess) break;
	}
	
	if(!isSuccess){
		cout << "NO";
	}
  return 0;
}