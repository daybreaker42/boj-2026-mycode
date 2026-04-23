#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int construct(int n) {
	int sum = n;
	string s = to_string(n);
	for (char c : s) {
		sum += c - '0';
	}
	return sum;
}

int main() {
	bool isExist = false;
	int n, res = -1;
	cin >> n;
	for (res = 0; res <= n; res++) {
		if (construct(res) == n) {
			cout << res;
			isExist = true;
			break;
		}
	}
	if (!isExist) {
		cout << 0;
	}
	return 0;
}