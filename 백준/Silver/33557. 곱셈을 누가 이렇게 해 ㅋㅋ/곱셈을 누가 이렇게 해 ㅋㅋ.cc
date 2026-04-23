#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int t; cin >> t;
    while(t-- > 0){
        string a, b; cin >> a >> b;
        string strange_ans = "";
        long long ans = (long long)stoi(a) * stoi(b);
        if(a.length() < b.length()) swap(a, b);     // a가 b보다 길거나 같게 설정
        int aIdx = 0, bIdx = 0;
        while(aIdx < a.length() - b.length()){
            strange_ans += a[aIdx++];
        }
        while(aIdx < a.length()){
            strange_ans += to_string((a[aIdx] - '0') * (b[bIdx] - '0'));
            aIdx++;
            bIdx++;
        }
        cout << (stoll(strange_ans) == ans) << "\n";
    }

	return 0;
}

/* comment 



*/