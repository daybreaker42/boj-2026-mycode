#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t-- > 0){
        int k;
        cin >> k;
        
        map<int, int> m;    // {숫자, 개수} 저장
        while(k-- > 0){
            char c;
            int n;
            cin >> c >> n;
            if(c == 'D' && m.size() > 0){
                if(n > 0){
                    // 최댓값 삭제
                    if(prev(m.end())->second == 1){
                        m.erase(prev(m.end())->first);
                    }else{
                        prev(m.end())->second--;
                    }
                }else{
                    // 최솟값 삭제
                    if(m.begin()->second == 1){
                        m.erase(m.begin()->first);
                    }else{
                        m.begin()->second--;
                    }
                }
            }else if(c == 'I'){
                // 삽입
                if(m.find(n) != m.end()){
                    m[n]++;
                }else{
                    m[n] = 1;
                }
            }
        }
        // 큐에 값이 없으면 EMPTY 출력
        // 있다면 최대/최솟값 출력
        if(m.size() > 0){
            cout << prev(m.end())->first << " " << m.begin()->first  << "\n";
        }else{
            cout << "EMPTY\n";
        }
    }

	return 0;
}

/* comment - 250302
- 우선순위 큐 두개 사용, 밀리는 연산은 큐마다 map만들어 처리 못한 숫자들 저장
- 삭제시 해당 수가 map에 있는지 각각 확인 후 삭제
    - map에 있다면 해당 수는 바로 삭제 (횟수 0이상이면 -1, 0이면 삭제)
- insert시 map에 있는지 확인 후 삽입
    - 있다면 map에서만 제거
- map엔 {해당 수, 제거 횟수} 저장.

- c++에서 map은 균형이진트리로 구현돼있음 -> 그냥 이걸로 삽입/삭제 하면 양방향 큐 되는거 아님??
*/