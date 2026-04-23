#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ui unsigned int
using namespace std;

// const bool debug = false;

bool isPrime(ui n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t-- > 0){
        ui n;
        cin >> n;
        while(!isPrime(n)){
            n++;
        }
        cout << n << "\n";
    }

	return 0;
}