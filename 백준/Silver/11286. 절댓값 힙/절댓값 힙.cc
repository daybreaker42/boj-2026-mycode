#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x != 0){
            // cout << "pair - " << abs(x) << " / " << x / abs(x) << endl;
            pq.push({abs(x), x / abs(x)});       // {절댓값 값, 부호}
        }else{
            if(!pq.empty()){
                cout << pq.top().first * pq.top().second << "\n";
                pq.pop();
            }else{
                cout << "0\n";
            }
        }
    }

	return 0;
}

/* comment 



*/