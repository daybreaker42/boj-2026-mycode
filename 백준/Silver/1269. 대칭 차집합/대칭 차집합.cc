// Baekjoon No. 1269
// Time Complexity O(nlogn)
// #Binary Search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& arr, int findNum);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, cnt = 0;
    int i;
    cin >> n >> m;
    vector<int> aArr(n);
    vector<int> bArr(m);
    for (i = 0; i < n; i++)
        cin >> aArr[i];
    for (i = 0; i < m; i++)
        cin >> bArr[i];

    // solving
    sort(aArr.begin(), aArr.end());
    sort(bArr.begin(), bArr.end());
    for (i = 0; i < n; i++)
        if (!binarySearch(bArr, aArr[i]))
            cnt++;
    for (i = 0; i < m; i++)
        if (!binarySearch(aArr, bArr[i]))
            cnt++;

    // output
    cout << cnt;
    return 0;
}
int binarySearch(vector<int>& arr, int findNum) {
    int st = 0, ed = arr.size() - 1, pivot;
    while (st <= ed) {
        pivot = (st + ed) / 2;
        if (findNum == arr[pivot])
            return 1;
        else if (findNum < arr[pivot])
            ed = pivot - 1;
        else
            st = pivot + 1;
    }
    return 0;
}