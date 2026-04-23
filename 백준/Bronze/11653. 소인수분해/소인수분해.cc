#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

void factorize(int n) {
    // 2로 나누어 떨어지는 경우 먼저 처리
    while(n % 2 == 0) {
        cout << 2 << '\n';
        n /= 2;
    }
    
    // 3 이상의 홀수 소인수 처리
    for(int i = 3; i * i <= n; i += 2) {
        while(n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }
    
    // 남은 수가 1보다 크면 그 수는 소수
    if(n > 1) cout << n << '\n';
}

int main() {
    fastio;
    
    int n;
    cin >> n;
    
    // 1은 소인수분해 불가
    if(n > 1) factorize(n);
    
    return 0;
}