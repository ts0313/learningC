//P1424 小鱼的航程(改进版)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	long int x, n;
	scanf("%ld%ld", &x, &n);
	long int count = n / 7 * 5;
	int ret = n % 7;
	if (ret > 0) {
		if (ret + x == 7 || x ==7) {
			ret -= 1;
		}
		else if (x >= 8) {
			ret -= 2;
		}
	}
	printf("%ld\n", (count + ret) * 250);
	system("pause");
	return 0;
}