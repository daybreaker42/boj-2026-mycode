// Baekjoon No. 1019 - 책 페이지 220121~220911
// Time Complexity O(logn)
// #Math
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, tmp, k, length;
	int i, j;
	unsigned long long int cnt[10] = { 0 };
	cin >> n;

	// solving
	string number = to_string(n);
	length = number.length();
	// 일의자리~ 맨 상위자리 - 1 까지
	for (i = 0; i < length - 1; i++) {
		if(number[length - 1 - i] - '0' != 0)
			cnt[0] += (n / (int)pow(10, i + 1)) * (int)pow(10, i);
		else
			cnt[0] += (n / (int)pow(10, i + 1) - 1) * (int)pow(10, i) + n % (int)pow(10, i) + 1;

		for (j = 1; j < 10; j++) {
			if (number[length - 1 - i] - '0' > j)
				cnt[j] += (n / (int)pow(10, i + 1) + 1) * (int)pow(10, i);
			else if (number[length - 1 - i] - '0' == j)
				cnt[j] += n / (int)pow(10, i + 1) * (int)pow(10, i) + n % (int)pow(10, i) + 1;
			else
				cnt[j] += (n / (int)pow(10, i + 1)) * (int)pow(10, i);
		}
	}

	i = length - 1;
	// 맨 상위자리
	for (j = 1; j < 10; j++) {
		if (number[0] - '0' > j)
			cnt[j] += (int)pow(10, i);
		if (number[0] - '0' == j) {
			cnt[j] += n % (int)pow(10, i) + 1;
		}
	}
	
	for (i = 0; i < 10; i++)
		cout << cnt[i] << " ";

	return 0;
}