#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    short n, k;
    cin >> n >> k;

    // solving
    vector<bool> primeList(n + 1, true);

    for(int i = 2; i <= n; i++){
        if(primeList[i]){
            k--;    // P도 지우므로
            if(k == 0){
                cout << i;
                return 0;
            }
            // cout << "remove - " << i << "\n";
            for(int j = 2 * i; j <= n; j += i){
                if(primeList[j]){
                    // cout << "remove - " << j << "\n";

                    primeList[j] = false;
                    k--;
                    if(k == 0){
                        cout << j;
                        return 0;
                    }
                }
            }
        }
    }


	return 0;
}