#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

// O((log N)/2) ?
bool isPalidrome(int n){
    string str = to_string(n);
    int length = str.length();
    for(int i = 0; i < length / 2; i++){
        if(str[i] != str[length - 1 - i]) return false;
    }
    return true;
}

// O(sqrt(N))
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

    while(!isPalidrome(n) || !isPrime(n)){
        n++;
    }

    cout << n;

	return 0;
}