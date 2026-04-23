#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100
using namespace std;

// struct
struct Point{
    long double x, y;
};

// globals
Point points[SIZE];
long double dist[SIZE][SIZE] = {0};
int parent[SIZE] = {0};

// functions
long double distance(Point a, Point b);
int find(int n);
bool _union(int v, int w);

int main() {
	fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }
    
    // solving
    long double ans = 0;
    priority_queue<pair<long double, pair<int, int>>> pq;
    for (int i = 0; i < n; i++){
        parent[i] = i;
    }
    

    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            dist[i][j] = distance(points[i], points[j]);
            pq.push({-dist[i][j], {i, j}});
        }
    }
    
    while(!pq.empty()){
        pair<long double, pair<int, int>> top = pq.top();
        pq.pop();
        long double cost = -top.first;
        int v = top.second.first, w = top.second.second;
        if(_union(v, w)){
            ans += cost;
        }
    }

    // output
    cout << ans;
	return 0;
}

long double distance(Point a, Point b){
    return sqrtl((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}
bool _union(int v, int w){
    int rv = find(v), rw = find(w);
    if(rv == rw) return false;
    
    parent[rw] = parent[rv] = min(rv, rw);
    return true;
}