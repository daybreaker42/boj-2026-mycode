#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    while(t-- > 0){
        string str;
        cin >> str;
        // check VPS
        stack<char> s;
        bool isVPS = true;
        for(char c : str){
            if(c == '('){
                s.push(c);
            }else{
                if(!s.empty()){
                    s.pop();
                }else{
                    isVPS = false;
                    break;
                }
            }
        }

        if(isVPS && s.empty()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

	return 0;
}