#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100
using namespace std;

// const bool debug = false;
int arr[SIZE] = {0};

int gcd(int n, int m){
    if(m == 0) return n;
    return gcd(m, n % m);
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    short t;
    cin >> t;
    while(t-- > 0){
        short n;
        cin >> n;
        long long sum = 0;
        for(short i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(short i = 0; i < n; i++){
            for(short j = i + 1; j < n; j++){
                sum += gcd(arr[i], arr[j]);
            }
        }
        cout << sum << "\n";
    }

	return 0;
}