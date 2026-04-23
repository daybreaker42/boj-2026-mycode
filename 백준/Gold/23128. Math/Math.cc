#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000000
using namespace std;

// const bool debug = false;
int arr[SIZE];

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n; cin >> n;
    int maxVal = 0;
    unordered_set<int> s;
    s.reserve(SIZE);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.insert(arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int iter = 1;
        long long aj = 2 * iter * arr[i] + (long long)iter * iter;
        while(aj <= SIZE && aj <= maxVal){
            if(s.find(aj) != s.end()){
                // cout << arr[i] << " | " << aj << endl;
                ans++;
            }
            iter++;
            aj = 2 * iter * arr[i] + (long long)iter * iter;
        }
    }
    cout << ans;

	return 0;
}