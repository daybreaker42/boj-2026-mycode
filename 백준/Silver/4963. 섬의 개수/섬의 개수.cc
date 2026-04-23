#include <iostream>
#include <vector>

using namespace std;

const vector<pair<int, int>> delta = {
    {1, 0},
    {1, 1},
    {0, 1},
    {-1, 1},
    {-1, 0},
    {-1, -1},
    {0, -1},
    {1, -1}
};

void dfs(int i, int j, int h, int w, vector<vector<bool>>& isLand, vector<vector<bool>>& visited);

int main(){
    // freopen("../../input.txt", "r", stdin);
    while(true){
        int w, h;
        cin >> w >> h;
        if(w == 0 && h == 0) return 0;
        vector<vector<bool>> isLand(h, vector<bool>(w));
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        for (int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                int temp; // int 타입으로 임시 변수를 선언합니다.
                cin >> temp; // int 타입으로 입력을 받습니다.
                isLand[i][j] = temp; // bool 타입으로 변환하여 저장합니다.
            }
        }
        // solving
        int ans = 0;
        for (int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(!visited[i][j] && isLand[i][j]){
                    dfs(i, j, h, w, isLand, visited);
                    ans++;
                }
            }
        }

        // output
        cout << ans << "\n";
    }
    return 0;
}

void dfs(int i, int j, int h, int w, vector<vector<bool>>& isLand, vector<vector<bool>>& visited){
    visited[i][j] = true;
    for(const pair<int, int>& k : delta){
        int nx = j + k.first, ny = i + k.second;
        if(0 <= nx && nx < w && 0 <= ny && ny < h && !visited[ny][nx] && isLand[ny][nx]){
            dfs(ny, nx, h, w, isLand, visited);
        }
    }
    return;
}