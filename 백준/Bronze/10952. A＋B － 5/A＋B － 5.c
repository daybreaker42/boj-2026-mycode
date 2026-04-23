#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int a, b, sum;
	while (1) {
		scanf("%d %d", &a, &b);
		sum = a + b;
		if (sum == 0)
			break;
		printf("%d\n", sum);
	}
}