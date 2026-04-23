#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    // solving
    int val1 = n;
    int cycleCount = 0;

    while(cycleCount == 0 || val1 != n){
        int val2 = val1 / 10 + val1 % 10;
        val1 = val1 % 10 * 10 + val2 % 10;
        cycleCount++;
    }

    cout << cycleCount;

	return 0;
}