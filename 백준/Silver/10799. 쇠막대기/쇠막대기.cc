#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    string str;
    cin >> str;

    ll ironPlaced = 0, ans = 0;
    for(int i = 0; i < str.length(); i++){
        char c = str[i];
        if(c == '(' && i < str.length() - 1 && str[i + 1] == ')'){
            // 레이져인 경우
            ans += ironPlaced;
            i++;
        }else if(c == '('){
            ironPlaced++;
        }else{
            ironPlaced--;
            ans++;
        }
    }

    cout << ans;

	return 0;
}