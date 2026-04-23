#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 3

using namespace std;

int arr[SIZE] = {0};

// const bool debug = false;

int getGcd(int n, int m){
    if(n < m) swap(n, m);
    if(n % m == 0) return m;
    return getGcd(m, n % m);
}

void getDivisors(int n){
    stack<int> s;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            cout << i << "\n";
            if(i * i != n){
                s.push(n / i);
            }
        }
    }
    while(!s.empty()){
        cout << s.top() << "\n";
        s.pop();
    }
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
    int gcd = getGcd(arr[0], arr[1]);
    if(n == 3){
        gcd = getGcd(gcd, arr[2]);
    }

    getDivisors(gcd);

	return 0;
}