/** 
DATE : 230504
#backtracking
*/

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000001
using namespace std;

int n;
int arr[SIZE] = {0};
bool backtracking(int idx);

int main(){
	fastIO;

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	// solving
	// 기존에 있는 숫자들로 했을때 1차적으로 되는지 체크
	for(int i = 0; i < n; i++){
		if(arr[i] > 0 && arr[i] == arr[i + 1]){
			cout << -1;
			return 0;
			}
	}
	
	if(backtracking(0)){
		for(int i = 0; i < n; i++){
			cout << arr[i] << " ";
		}
	}else{
		cout << -1;
	}

  return 0;
}

bool backtracking(int idx){
	// n == 1인 있을경우
	if(n == 1){
		if(!arr[idx]){
			arr[idx] = 1;	// 일단 아무거나 정해줌
		}
		return 1;
	}
	// 잘 끝난 경우
	if(idx == n){
		return 1;
	}
	
	if(arr[idx] == 0){
		for(int i = 1; i <= 3; i++){
			// i가 앞뒤 숫자랑 같은지 체크
			if((idx > 0 && arr[idx - 1] == i) || (idx < n - 1 && arr[idx + 1] == i)){
				continue;
			}
			arr[idx] = i;
			if(backtracking(idx + 1)){
				return 1;
			}
		}	// for문
	}else{
		return backtracking(idx + 1);
	}
	return 0;
}