#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, a, b, res;
    int i, j;
    int NSquares[32] = { 0 };
    cin >> t;

    for (i = 0; i < t; i++) {
        cin >> a >> b;
        res = 1;
        // init towNSquare
        NSquares[0] = (int)pow(a, 1) % 10;
        for (j = 1; j < 32; j++)
            NSquares[j] = NSquares[j-1] * NSquares[j-1] % 10;
        string number = bitset<32>(b).to_string();
        for (j = 0; j < 32; j++) {
            if (number[j] == '1') {
                res *= NSquares[31 - j];
                res %= 10;
            }
        }
        number.clear();
        if (!res)
            res = 10;
        cout << res << '\n';
    }
    return 0;
}