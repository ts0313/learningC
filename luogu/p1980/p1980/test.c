//P1980 计数问题
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int x;
	long int n, a, b, count = 0;
	scanf("%ld%d", &n, &x);
	for (int i = 1; i <= n; ++i) {
		a = i;
		while (a != 0) {
			b = a % 10;
			a = a / 10;
			if (b == x) {
				count++;
			}
		}
	}
	printf("%ld\n", count);
	system("pause");
	return 0;
}