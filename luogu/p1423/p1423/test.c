//P1423 –°”Ò‘⁄”Œ”æ
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	double m;
	scanf("%lf", &m);
	int num = 1;
	double a = 2, b = 2;
	while (b < m) {
		b += a * 0.98;
		a *= 0.98;
		++num;
	}
	printf("%d\n", num);
	system("pause");
	return 0;
}