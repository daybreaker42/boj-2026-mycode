#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// 문자를 숫자로 변환하는 함수
int char_to_num(char c) {
    if(isdigit(c)) return c - '0';
    return c - 'A' + 10;
}

int main() {
    fastio;
    
    string n;
    int b;
    cin >> n >> b;
    
    // 10진수 변환
    long long result = 0;  // 오버플로우 방지
    for(char c : n) {
        result = result * b + char_to_num(c);
    }
    
    cout << result;
    
    return 0;
}