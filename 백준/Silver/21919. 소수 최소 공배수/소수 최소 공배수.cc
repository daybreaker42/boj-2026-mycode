#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define SIZE 10000
using namespace std;

// const bool debug = false;

int arr[SIZE] = {0};

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // solving
    ll ans = 1;

    for(int i = 0; i < n; i++){
        if(isPrime(arr[i]) && ans % arr[i] != 0){
            ans *= arr[i];
        }
    }

    if(ans == 1){
        ans = -1;
    }
    
    cout << ans;
    
	return 0;
}