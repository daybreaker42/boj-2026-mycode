#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backTracking(vector<int> &arr, vector<int> &numbers, int n, int m, int cnt);
int main(){
    ios::sync_with_stdio(false);
    int n, m;
    int i, j;
    scanf("%d %d", &n, &m);
    vector<int> arr(n, 0);
    for(i = 0; i < n; i++)
        scanf(" %d", &arr[i]);
    
    // solving & output
    sort(arr.begin(), arr.end());
    vector<int> numbers;
    backTracking(arr, numbers, n, m, 0);
    return 0;
}

void backTracking(vector<int> &arr, vector<int> &numbers, int n, int m, int cnt){
    int i;
    // output
    if(cnt == m){
        for(i = 0; i < m; i++)
            printf("%d ", numbers[i]);
        printf("\n");
        return;
    }
    
    for(i = 0; i < n; i++){
        numbers.push_back(arr[i]);
        backTracking(arr, numbers, n, m, cnt+1);
        numbers.pop_back();
    }
    return;
}