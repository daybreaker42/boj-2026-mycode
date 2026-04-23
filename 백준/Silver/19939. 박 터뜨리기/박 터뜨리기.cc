/**
DATE : 230424~
#그리디, 수학

수학으로 풀고있는데, 계속 틀림..

*/

#include <bits/stdc++.h>
#define fastIO                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
using namespace std;

int main() {
  fastIO;
  int n, k;
  cin >> n >> k;

  if (n < k * (k + 1) / 2) {
    cout << -1;
  } else {
    // sol3)
    int tmp = n - k * (k + 1) / 2;
    tmp %= k;
		if(tmp == 0){
			cout << k - 1;	
		}else{
			cout << k;
		}
    
  }

  return 0;
}