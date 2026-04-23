#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, k; cin >> n >> k;
    string number; cin >> number;
    int left_pop = k;
    deque<int> s;       // back에서 삽입해서 front로 나옴
    for(int i = 0; i < n; i++){
        char c = number[i];
        int num = c - '0';
        while(!s.empty() && s.back() < num && left_pop > 0){
            // 갑자기 증가하는 부분 나왔는데, 아직 지울 수 있으면 해당 수 지우고 
            s.pop_back();
            left_pop--;
        }
        // 단조 감소하거나, 지울거 다 지웠으면 숫자 계속 추가
        s.push_back(num);
    }

    for(int i = 0; i < n - k; i++){
        cout << s.front();
        s.pop_front();
    }

	return 0;
}

/* comment 



*/