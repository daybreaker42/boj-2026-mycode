#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

struct circle {
    int idx;
    int status;
};

// struct circle{
//     int st;
//     int ed;
//     int num;
// };

// circle circles[NUM];    // {center, radius}

// bool checkCollision(coord circle_1, coord circle_2);

map<int, circle> x_axis;   // {좌표, {원 번호, 상태}} / 상태 : 시작 = 1, 종료 = 2

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int c, r, st, ed;
        cin >> c >> r;
        st = c - r; ed = c + r;
        // circles[i] = {st, ed, i};
        if(x_axis.find(st) != x_axis.end() || x_axis.find(ed) != x_axis.end()){
            // 애초에 겹치는 좌표가 있었을 경우 - 시작부터 안됨
            // success = false;
            cout << "NO";
            return 0;
        }
        x_axis[st] = {i, 1};
        x_axis[ed] = {i, 2};
    }

    // solving
    // sort(circles, circles + n);

    stack<int> s;   // 현재 열려있는 원 번호, 열려있는것만 들어감.
    for(const auto c : x_axis){
        int circleIdx = c.second.idx, status = c.second.status;
        if(status == 1){
            s.push(circleIdx);
        }else{
            if(s.empty()){
                // 원의 시작은 없는데 끝나버린 경우
                cout << "NO";
                return 0;
            }
            if(s.top() != circleIdx){
                // 한 원이 끝나지 않았는데 다른 원이 시작될 경우
                cout << "NO";
                return 0;
            }
            s.pop();
        }
    }

    cout << "YES";

	return 0;
}