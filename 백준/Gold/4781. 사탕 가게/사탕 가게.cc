/**
DATE : 230421
#dp
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int calPerCost[10001] = {0};

  while (1) {
    int n;
    double m;
    cin >> n >> m;
    const int SIZE = (int)(m * 100 + 0.5);
    if (!n)
      break;
    memset(calPerCost, 0, sizeof(calPerCost));
    vector<pair<int, int>> candies(n);
    for (int i = 0; i < n; i++) {
      double p;
      cin >> candies[i].first >> p;
      candies[i].second = (int)(p * 100 + 0.5);
    }

    // solving
    for (int j = 0; j < n; j++) {
      int currCal = candies[j].first, currCost = candies[j].second;
      if (currCost <= SIZE) {
        calPerCost[currCost] =
            max(calPerCost[currCost], calPerCost[0] + currCal);
      }
    }
    for (int i = 1; i < SIZE; i++) {
      for (int j = 0; j < n; j++) {
        int currCal = candies[j].first, currCost = candies[j].second;
        if (i + currCost <= SIZE && calPerCost[i]) {
          calPerCost[i + currCost] =
              max(calPerCost[i + currCost], calPerCost[i] + currCal);
        }
      }
    }

    int maxVal = 0;
    for (int i = SIZE; i > -1; i--) {
      maxVal = max(maxVal, calPerCost[i]);
    }
    cout << maxVal << "\n";

	}
  return 0;
}