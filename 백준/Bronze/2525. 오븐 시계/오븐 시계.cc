#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
	fastio;
    int hour, min, delta;
    cin >> hour >> min >> delta;
    int dHour = delta / 60;
    int dMin = delta % 60;
    min += dMin;
    if(min >= 60){
        min %= 60;
        hour++;
    }
    hour += dHour;
    if(hour >= 24){
        hour %= 24;
    }
    cout << hour << " " << min;

	return 0;
}