#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const bool debug = false;

int main() {
	fastio;

    // freopen("input.txt", "r", stdin);

    int a, b, c, m;
    cin >> a >> b >> c >> m;

    // solving
    int maxWork = 0, leftTime = 24, leftStrength = 0;
    if(m >= a){
        while(leftTime > 0){
            while(leftTime > 0 && m + leftStrength >= a){
                leftStrength -= a;
                maxWork += b;
                leftTime -= 1;
            }
            while(leftTime > 0 && m + leftStrength < a && leftStrength < 0){
                leftStrength += c;
                leftStrength = min(leftStrength, 0);
                leftTime -= 1;
            }
        }
    }

    // output
    cout << maxWork;

	return 0;
}