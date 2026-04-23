// Baekjoon No. 2750
// Time Complexity O(n^2)
// #Sort

#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int>& arr);
void swap(int* n, int* m);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int i;
    cin >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++)
        cin >> arr[i];

    // insertion sort로 구현
    insertionSort(arr);

    // output
    for (i = 0; i < n; i++)
        cout << arr[i] << "\n";
    return 0;
}
void swap(int* n, int* m) {
    *n ^= *m;
    *m ^= *n;
    *n ^= *m;
    return;
}
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1])
                swap(&arr[j], &arr[j - 1]);
        }
    }
    return;
}