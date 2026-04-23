#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // solving
    int idx = 0;
    stack<int> s;
    vector<char> turn;
    for (int i = 1; i <= n; i++){
        s.push(i);
        turn.push_back('+');
        while(!s.empty() && s.top() == arr[idx]){
            s.pop();
            turn.push_back('-');
            idx++;
        }
    }

    if(s.empty()){
        for (char c : turn){
            cout << c << "\n";
        }
    }else{
        cout << "NO";
    }
    

	return 0;
}