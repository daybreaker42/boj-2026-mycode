#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define SIZE (int)1E7
#define MAX (ll)1E14
using namespace std;

// const bool debug = false;

bool isPrime[SIZE + 1] = {false};
void initPrimes(){
    fill(isPrime, isPrime + SIZE, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= SIZE; i++){
        if(isPrime[i]){
            for(int j = i * 2; j <= SIZE; j += i){
                isPrime[j] = false;
            }
        }
    }
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    ll startNum, endNum;
    cin >> startNum >> endNum;

    // solving
    ll count = 0;
    initPrimes();
    for(ll i = 2; i * i <= endNum; i++){   // 계산시 overflow 방지를 위해 i를 long long으로 선언
        if(isPrime[i]){
            ll targetPrime = i * i; // n >= 2이므로
            while(targetPrime <= endNum){
                // cout << targetPrime << "\n";
                if(startNum <= targetPrime) {
                    count++;
                }
                if(targetPrime > LLONG_MAX / i) {    // long long overflow 방지
                    break;
                }
                targetPrime *= i;
            }
        }
    }
    cout << count;

	return 0;
}