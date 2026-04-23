#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
// globals
int ans = 0, removeNode;
// functions
void dfs(int n, vector<vector<int>> &children);

int main() {
	fastio;
    int n, root;
    cin >> n;
    vector<int> childNum(n);
    vector<vector<int>> children(n);
    for (int i = 0; i < n; i++){
        int child;
        cin >> child;
        if(child >= 0){
            children[child].push_back(i);
        }else{
            root = i;
        }
    }
    cin >> removeNode;
    // solving
    dfs(root, children);

    // output
    cout << ans;
	return 0;
}

void dfs(int n, vector<vector<int>> &children){
    if(n == removeNode) return;
    if(children[n].size() == 0
    || (children[n].size() == 1 && children[n][0] == removeNode)){
        ans += 1;
    }
    
    for (int i = 0; i < children[n].size(); i++){
        int child = children[n][i];
        dfs(child, children);
    }
    return;
}