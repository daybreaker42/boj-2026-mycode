#define _CRT_SERURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int num;
	int a, b;
	scanf("%d", &num);
	while(num > 0){
		num--;
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
}