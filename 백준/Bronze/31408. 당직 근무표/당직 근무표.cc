#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    vector<int> schedule(n);
    map<int, int> m;
    int maxOccur = 0;
    for (int i = 0; i < n; i++){
        cin >> schedule[i];
        if(m.find(schedule[i]) != m.end()){
            m[schedule[i]]++;
        }else{
            m[schedule[i]] = 1;
        }
        maxOccur = max(maxOccur, m[schedule[i]]);
    }
    // solving

    // output
    if(maxOccur > n / 2 + n % 2){
        cout << "NO";
    }else{
        cout << "YES";
    }

	return 0;
}