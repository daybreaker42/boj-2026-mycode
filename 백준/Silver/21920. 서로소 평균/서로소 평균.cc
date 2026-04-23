#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 500000
using namespace std;

// const bool debug = false;

int arr[SIZE] = {0};

int gcd(int n, int m){
    if(n < m) swap(n, m);
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> x;

    // solving
    int cnt = 0;
    double ave = 0;
    for(int i = 0; i < n; i++){
        if(gcd(arr[i], x) == 1){
            cnt++;
            ave += arr[i];
        }
    }

    ave /= cnt;
    cout << fixed;
    cout.precision(7);
    cout << ave;

	return 0;
}