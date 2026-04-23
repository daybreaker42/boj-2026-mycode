#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    stack<int> s;
    int building_num = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        while(!s.empty() && s.top() >= y){
            if(s.top() > y) building_num++;
            s.pop();
        }
        if(y > 0) s.push(y); 
    }

    while(!s.empty()){
        building_num++;
        s.pop();
    }

    cout << building_num;

	return 0;
}

/* comment 



*/