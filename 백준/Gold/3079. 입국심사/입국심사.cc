#include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100000
#define ll long long
using namespace std;

// const bool debug = false;

int check_time[SIZE];

ll binSearch(int n, int m, ll st, ll ed){
    if(st == ed) return st;
    ll mid = (st + ed) / 2;
    // 가능한지 검증, 안되면 mid + 1~ed, 되면 st~mid 검사
    ll total = 0;
    for(int i = 0; i < n; i++){
        total += mid / check_time[i];
        if(total > 1e9){
            total = m + 1;
            break;
        }
    }
    if(total >= m) return binSearch(n, m, st, mid);
    else return binSearch(n, m, mid + 1, ed);
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> check_time[i];
    }
    
    // solving
    int minT = check_time[0];
    for (int i = 1; i < n; i++){
        minT = min(minT, check_time[i]);
    }
    
    ll ans = (ll)minT * m;  // 일단 무조건 해결가능한 시간 아무거나
    // ans = min(ans, binSearch(n, m, 0, MAX * MAX));
    ans = binSearch(n, m, 1, ans);

    // output
    cout << ans;

	return 0;
}