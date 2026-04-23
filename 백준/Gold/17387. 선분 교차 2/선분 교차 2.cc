#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;
struct Point{
    ll x, y;
    bool operator<(const Point& other)const{
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
    bool operator<=(const Point& other)const{
        if(x == other.x) return y <= other.y;
        return x <= other.x;
    }
};
struct Segment{
    Point a, b;
};

// functions
int ccw(Segment s, Point p);
bool isCross(Segment s1, Segment s2);

int main() {
	fastio;
    Segment s1, s2;
    cin >> s1.a.x >> s1.a.y >> s1.b.x >> s1.b.y;
    cin >> s2.a.x >> s2.a.y >> s2.b.x >> s2.b.y;

    // solving, output
    cout << isCross(s1, s2);
	return 0;
}

int ccw(Segment s, Point p){
    Point v1, v2;
    v1.x = s.b.x - s.a.x; v1.y = s.b.y - s.a.y;
    v2.x = p.x - s.b.x; v2.y = p.y - s.b.y;
    ll result = v1.x * v2.y - v2.x * v1.y;
    return result == 0 ? 0 : result > 0 ? 1 : -1;
}
bool isCross(Segment s1, Segment s2){
    int ccwResult[4];
    ccwResult[0] = ccw(s1, s2.a);
    ccwResult[1] = ccw(s1, s2.b);
    ccwResult[2] = ccw(s2, s1.a);
    ccwResult[3] = ccw(s2, s1.b);

    if(ccwResult[0] * ccwResult[1] == 0 && ccwResult[2] * ccwResult[3] == 0){
        return min(s1.a, s1.b) <= max(s2.a, s2.b) && min(s2.a, s2.b) <= max(s1.a, s1.b);
    }else{
        return ccwResult[0] * ccwResult[1] <= 0 && ccwResult[2] * ccwResult[3] <= 0;
    }
}