#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
	fastio;
    while(true){
        int t1, t2;
        cin >> t1 >> t2;
        if(t1 == 0 && t2 == 0) break;
        if(t1 > t2) cout << "Yes\n";
        else cout << "No\n";
    }

	return 0;
}