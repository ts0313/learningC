//P1008 ������
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;
	for (a = 123; a < 333; ++a) {
		b = a * 2;
		c = a * 3;
		if ((a / 100 + a / 10 % 10 + a % 10 +
			b / 100 + b / 10 % 10 + b % 10 +
			c / 100 + c / 10 % 10 + c % 10 ==
			1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9) &&
			((a / 100) * (a / 10 % 10) * (a % 10) *
			(b / 100) * (b / 10 % 10) * (b % 10) *
				(c / 100) * (c / 10 % 10) * (c % 10)) ==
				(1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9)) {
			printf("%d %d %d\n", a, b, c);
		}
	}
	system("pause");
	return 0;
}