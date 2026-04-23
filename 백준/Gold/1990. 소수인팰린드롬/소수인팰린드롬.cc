#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE (int)1E7 + 1
using namespace std;

// const bool debug = false;

bool isPrime[SIZE] = {false};
int startNum, endNum;

bool isPalidrome(int n){
    string str = to_string(n);
    int len = str.length();
    for(int i = 0; i < len / 2; i++){
        if(str[i] != str[len - i - 1]){
            return false;
        }
    }
    return true;
}

void initPrimeList();

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    cin >> startNum >> endNum;

    initPrimeList();

    cout << -1;

	return 0;
}

void initPrimeList(){
    fill(isPrime, isPrime + SIZE, true);
    isPrime[1] = false;
    for(int i = 2; i <= SIZE; i++){
        if(isPrime[i]){
            if(startNum <= i && i <= endNum && isPalidrome(i)){
                cout << i << "\n";
            }
            // cout << i << "\n";
            for(int j = i * 2; j <= SIZE; j += i){
                isPrime[j] = false;
            }
        }
    }
}

