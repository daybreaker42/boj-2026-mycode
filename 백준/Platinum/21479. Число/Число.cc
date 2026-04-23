/**
DATE : 230416
#그리디
*/

#include <bits/stdc++.h>
using namespace std;

bool compare(string i, string j) { 
	return (i + j) > (j + i); 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string strInput, ans;
  vector<string> stringArr;
  while (1) {
    cin >> strInput;
    if (cin.eof())
      break;
    stringArr.push_back(strInput);
  }
	
  sort(stringArr.begin(), stringArr.end(), compare);
  for (string s : stringArr) {
    for (char c : s) {
      cout << c;
    }
  }
  return 0;
}