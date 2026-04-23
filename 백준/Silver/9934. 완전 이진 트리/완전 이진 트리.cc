#include <bits/stdc++.h>
#define SIZE 2048
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int visitNum = 0;
int tree[SIZE];
int sequence[SIZE];

void inorder(int n, int k) {
    bool isRangeOver = n > (1 << k) - 1;   // 현재 노드 번호가 2^k - 1보다 크면 범위 벗어난 것.
    if (isRangeOver) return;

    inorder(n * 2, k);
    tree[n] = sequence[visitNum++];
    inorder(n * 2 + 1, k);
    return;
}

int main() {
    fastio;

    // freopen("../../input.txt", "r", stdin);
    int k; cin >> k;
    for (int i = 0; i < (1 << k) - 1; i++) {
        cin >> sequence[i];
    }

    // solving
    // 중위순회 하면서 tree 초기화
    inorder(1, k);

    // output
    int level = 1;
    for(int i = 1; i < (1 << k); i++){
        cout << tree[i] << " ";
        if(i == (1 << level) - 1){
            cout << "\n";
            level++;
        }
    }

    return 0;
}