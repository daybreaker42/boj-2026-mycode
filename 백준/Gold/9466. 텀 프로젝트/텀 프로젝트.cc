#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NUM 100000
using namespace std;

const bool debug = false;
bool visited[NUM] = {0};
// bool temp_visited[NUM] = {0};
int selection[NUM] = {0};

void check_group(int current, queue<int> &temp_queue);

int main() {
	fastio;
    int t;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        int n;
        cin >> n;
        // vector<int> selection(n);
        
        for(int i = 0; i < n; i++){
            cin >> selection[i];
            selection[i] -= 1;
        }

        // solving
        int ans = n;
        
        // vector<bool> visited(n, 0);
        fill(visited, visited + n, 0);
        for(int i = 0; i < n; i++){
            if(debug){
                cout << "case - " << i << "\n";
            }
            if(!visited[i]){
                queue<int> temp_queue = {};
                // vector<bool> temp_visited(n, 0);
                // vector<int> temp_queue = {};
                // fill(temp_visited, temp_visited + n, 0);
                check_group(i, temp_queue);
                // 사이클이 만들어졌고, 시작점으로 돌아온 경우
                ans -= temp_queue.size();
                while(!temp_queue.empty()){
                    visited[temp_queue.front()] = true;
                    temp_queue.pop();
                }
                visited[i] = true;
            }
            if(debug){
                cout << "visited - ";
                for(int i = 0; i < n; i++){
                    cout << visited[i] << " ";
                }
                cout << "\n";
                cout << "ans - " << ans << "\n\n";
            }
        }

        // for(int i = 0; i < n; i++){
        //     if(!visited[i]) ans++;
        // }
        cout << ans << "\n";
    }

	return 0;
}

void check_group(int current, queue<int> &temp_queue){
    int next = selection[current];
    temp_queue.push(current);
    // temp_visited[current] = true;
    visited[current] = true;
    if(debug){
        cout << "start - " << temp_queue.front() << " curr - " << current << "\n";
    }
    
    if(visited[next]){
        // 다른 순환 고리 안에 갇힌거라면 -> 해당 순환 고리 반환
        while(!temp_queue.empty() && temp_queue.front() != next){
            temp_queue.pop();
        }
        return;
    }

    // if(visited[next]){
    //     // 중간에 이미 방문했던 사이클 만났을 경우 - return
    //     temp_queue = {};
    //     return;
    // }

    check_group(next, temp_queue);
    return;
}