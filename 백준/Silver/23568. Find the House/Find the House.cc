// Baekjoon No. 23658 Find the House
// Time Complexity O(
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, ans, st, ed;
    int i;
    char tmp;
    map<int, int> coords;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> st >> tmp >> ed;
        if (tmp == 'R')
            coords[st] = st + ed;
        else
            coords[st] = st - ed;
    }

    // solving
    for (map<int, int>::iterator itr = coords.begin(); itr != coords.end(); itr++) {
        // cout << itr->first << " : " << itr->second << '\n';
        if (coords.find(itr->second) == coords.end()) {
            ans = itr->second;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}