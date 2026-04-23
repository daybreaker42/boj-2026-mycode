#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    while(t-- > 0){
        int n, targetIdx, idx = 0;  // idx - sort_priority에서 현재 남아있는 수들 중 가장 중요도가 큰 수 가리킴
        cin >> n >> targetIdx;
        vector<int> sort_priority(n);
        vector<pii> priority(n);  // {중요도, 원래 순서}
        queue<pii> printer;
        for(int i = 0; i < n; i++){
            cin >> priority[i].first;
            priority[i].second = i;
            printer.push(priority[i]);
            sort_priority[i] = priority[i].first;
        }
        // solving
        sort(sort_priority.begin(), sort_priority.end(), greater<>());

        int count = 1, maxPriority = sort_priority[idx];
        while(printer.front().second != targetIdx || maxPriority != printer.front().first){    // printer != {sort_priotity[idx].first, targetIdx} 일때
            if(printer.front().first == maxPriority){
                count++;
                idx++;
                maxPriority = sort_priority[idx];
            }else{
                printer.push(printer.front());
            }
            printer.pop();
        }
        cout << count << "\n";
    }

	return 0;
}