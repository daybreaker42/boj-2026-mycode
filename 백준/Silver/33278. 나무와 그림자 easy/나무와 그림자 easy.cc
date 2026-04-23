#include <bits/stdc++.h>
#define SIZE 300000
#define ll long long
using namespace std;

pair<int, int> tree[SIZE];          // {x, h}
int shadows[SIZE];               // 2.4MB정도

int main(){
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        int x, h;
        cin >> x >> h;
        tree[i] = {x, h};
    }

    // solving
    ll ans = 0;
    sort(tree, tree + n);   // x 오름차순대로 정렬
    for(int i = 0; i < n - 1; i++){
        int tree_idx = i + 1, curr_x = tree[i].first, curr_h = tree[i].second;
        while(tree_idx < n){
            int next_x = tree[tree_idx].first, next_h = tree[tree_idx].second;
            int next_shadow = min(next_h, max(0, curr_h - (next_x - curr_x) * t));       // max 걸리는경우 - 하나도 안가려짐, min 걸리는경우 - 전체가 가려지고도 남음
            if(next_shadow == 0) break;                 // 그림자가 닿지 않는 나무가 나왔을 때
            if(shadows[tree_idx] <= next_shadow){
                shadows[tree_idx] = next_shadow;
            }else{
                break;                                  // 이전 나무의 그림자에 가려져버릴때
            }
            tree_idx++;
        }
    }

    for(int i = 0; i < n; i++){
        ans += shadows[i];
    }
    
    
    cout << ans;
    
    // cout << "\n";
    // for(int i = 0; i < n; i++){
    //     cout << shadows[i] << " ";
    // }
    // cout << "\n";    
    return 0;
}