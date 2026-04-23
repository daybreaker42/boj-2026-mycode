#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    // freopen("../../input.txt", "r", stdin);
    fastio
    int n, m;
    cin >> n >> m;
    vector<string> idx_to_name;
    idx_to_name.reserve(n);
    map<string, int> name_to_idx;
    for (int i = 0; i < n; i++){
        string name;
        cin >> name;
        idx_to_name.push_back(name);
        name_to_idx[name] = i;
    }

    // solving
    for (int i = 0; i < m; i++){
        string input;
        cin >> input;
        if(('a' <= input[0] && input[0] <= 'z') || ('A' <= input[0] && input[0] <= 'Z')){
            // name input
            cout << name_to_idx[input] + 1 << "\n";
        }else{
            cout << idx_to_name[stoi(input) - 1] << "\n";
        }
    }
    
    
    return 0;
}