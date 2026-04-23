#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// functions
int binSearch(int n, int st, int ed, vector<int> &arr);

int main() {
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> mycard(m);
    vector<bool> visited(m, false);
    vector<int> target(k);
    for (int i = 0; i < m; i++){
        cin >> mycard[i];
    }
    for (int i = 0; i < k; i++){
        cin >> target[i];
    }
    
    // solving
    sort(mycard.begin(), mycard.end());
    // cout << "sorted mycard" << endl;
    // for (int i = 0; i < m; i++){
    //     cout << mycard[i] << " ";
    // }
    // cout << endl;
    
    for (int i = 0; i < k; i++){
        int idx = binSearch(target[i], 0, m - 1, mycard);
        // cout << "idx - " << idx << endl;
        // if(idx < 0){
        //     cout << "error" << endl;
        //     continue;
        // }
        if(visited[idx]){
            while(idx < m - 1 && visited[idx]) idx++;
        }
        // cout << "new idx - " << idx << endl;
        cout << mycard[idx] << "\n";
        visited[idx] = true;
    }

    // output

	return 0;
}

// n보다 큰 가장 앞쪽의 수를 찾는 이진탐색
int binSearch(int n, int st, int ed, vector<int> &arr){
    // cout << "finding - " << n << " > " << st << " ~ " << ed << endl;
    if(arr[st] > n) return st;
    if(arr[ed] <= n) return -1;
    int mid = (st + ed) / 2;
    int pivot = arr[mid];
    if(pivot <= n) return binSearch(n, mid + 1, ed, arr);
    else return binSearch(n, st, mid, arr);
}