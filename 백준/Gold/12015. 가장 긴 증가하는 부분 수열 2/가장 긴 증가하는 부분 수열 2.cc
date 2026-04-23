#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 2000000000
using namespace std;

// functions
int binSearch(int, int, int, vector<int>&);

int main() {
	fastio;
    int n;
    cin >> n;
    vector<int> inputArray(n);
    vector<int> lis(n + 1, MAX);
    for(int i = 0; i < n; i++){
        cin >> inputArray[i];
    }

    // solving
    for(int i = 0; i < n; i++){
        int idx = binSearch(inputArray[i], 1, n, lis);
        if(idx > 0){
            lis[idx] = inputArray[i];
        }
    }

    // output
    int answer = 0;
    for(int i = 0; i <= n; i++){
        if(lis[i] < MAX){
            answer = i;
        }
    }
    cout << answer;
	return 0;
}

int binSearch(int baseValue, int st, int ed, vector<int>& arr){
    // 값이 똑같아도 여기서 걸러줌
    if(arr[st] > baseValue) return st;  // 배열에서 가장 작은 값이 baseValue보다 큰 경우 -> 답은 st임
    if(arr[ed] <= baseValue) return -1;  // 배열에서 가장 큰 값이 baseValue보다 작은 경우 -> baseValue보다 작은 값 없음, -1 return
    
    int mid = (st + ed) / 2;
    int pivot = arr[mid];
    if(pivot == baseValue) return -1;   // 이미 해당 값이 lis에 있다면, 추가할 필요가 없음
    else if(pivot < baseValue) return binSearch(baseValue, mid+1, ed, arr);
    else return binSearch(baseValue, st, mid, arr);
}