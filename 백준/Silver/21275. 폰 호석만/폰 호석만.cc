#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

// const bool debug = false;

// origin을 base진법으로 계산시 10진법 정수를 구하는 함수
// base진법으로 변환 불가시 -1 return
ll convertNum(string origin, int base){
    // 이전에 base 진법으로 표현 가능한지 판별
    for(char c : origin){
        // 각 자리가 0~9일때 검사
        if(c <= '9' && c >= base + '0'){
            return -1;
        }
        // 각 자리가 a~z일때 검사
        if(c >= 'a' && c >= base - 10 + 'a'){
            return -1;
        }
    }

    // 변환가능시 base 진법으로 변환, 여전히 overflow날 수 있음
    ll result = 0;
    for(char c : origin){
        int currPosition = 0;
        if('0' <= c && c <= '9'){
            currPosition = c - '0';
        }else{
            currPosition = c - 'a' + 10;
        }
        result = currPosition + result * base;
    }
    // X는 long long 범위 이내이므로 overflow시 -1 return
    if(result < 0) return -1;
    return result;
}

int main() {
	fastio;

    string val1, val2;
    cin >> val1 >> val2;

    // solving
    int a, b;
    ll x;
    bool solvable = false;
    for(int i = 2; i <= 36; i++){
        for(int j = 2; j <= 36; j++){
            if(i == j) continue;
            ll convResult1 = convertNum(val1, i);
            if(convResult1 < 0) break;
            ll convResult2 = convertNum(val2, j);
            if(convResult2 < 0) continue;

            // cout << "conv - " << convResult1 << " / " << convResult2 << "\n";
            if(convResult1 == convResult2){
                // 답이 여러개인 경우우
                if(solvable){
                    cout << "Multiple";
                    return 0;
                }
                // 풀 수 있는 경우
                solvable = true;
                x = convResult1;
                a = i;
                b = j;
            }
        }   
    }

    if(solvable){
        cout << x << " " << a << " " << b;
    }else{
        cout << "Impossible";
    }

	return 0;
}
