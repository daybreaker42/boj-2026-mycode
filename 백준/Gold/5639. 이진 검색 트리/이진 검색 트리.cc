#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000000
using namespace std;

struct node{
    int left = 0;
    int right = 0;
};

// const bool debug = false;
vector<node> tree(SIZE);

void postOrder(int curr){
    int left = tree[curr].left, right = tree[curr].right;
    if(left > 0) postOrder(left); // 근데 계속 커지고 n = 10000이면 curr는 얼마까지 증가?
    if(right > 0) postOrder(right);
    cout << curr << "\n";
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);  // 이거 해야함
    int val, root = -1;
    stack<int> s;    // {nodeIdx} 저장
    while(cin >> val){
        if(root < 0) {
            // 루트 노드
            root = val;
            s.push(val);
        }else{
            int t = s.top();
            if(val < t){
                // 숫자가 작음 - 왼쪽 노드
                tree[t].left = val;
                s.push(val);
            }else{
                // 숫자가 큼 - 오른쪽 노드
                s.pop();
                while(!s.empty() && s.top() < val){
                    t = s.top();
                    s.pop();
                }
                tree[t].right = val;
                s.push(val);
            }   
        }
    }

    // solving
    postOrder(root);

	return 0;
}