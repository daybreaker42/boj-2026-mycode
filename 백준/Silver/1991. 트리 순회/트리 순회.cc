/**
DATE : 230417
#tree, 트리 탐색
*/

#include <bits/stdc++.h>
using namespace std;

map<char, pair<char, char>> tree;

void preOrder(char i);
void inOrder(char i);
void postOrder(char i);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    char in1, in2, in3;
    cin >> in1 >> in2 >> in3;
    tree[in1] = {in2, in3};
  }

  // solving
  preOrder('A');
  cout << "\n";
  inOrder('A');
  cout << "\n";
  postOrder('A');
  cout << "\n";
  return 0;
}

void preOrder(char i) {
	cout << i;
	if(tree[i].first != '.') preOrder(tree[i].first);
	if(tree[i].second != '.') preOrder(tree[i].second);
	return;
}
void inOrder(char i) {
	if(tree[i].first != '.') inOrder(tree[i].first);
	cout << i;
	if(tree[i].second != '.') inOrder(tree[i].second);
	return;
}
void postOrder(char i) {
	if(tree[i].first != '.') postOrder(tree[i].first);
	if(tree[i].second != '.') postOrder(tree[i].second);
	cout << i;
	return;
}