#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;

    // solving
    queue<int> q;
    vector<int> ans;
    int next = 1;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    while(ans.size() < n){
        if(next % k == 0){
            ans.push_back(q.front());
            q.pop();
            next++;
            continue;
        }
        q.push(q.front());
        q.pop();
        next++;
    }

    cout << "<";
    for(int i = 0; i < n; i++){
        cout << ans[i];
        if(i < n - 1){
            cout << ", ";
        }else{
            cout << ">";
        }
    }

	return 0;
}