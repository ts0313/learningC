//求出0～999之间的所有“水仙花数”并输出
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int a, b, c;
	int i = 100;
	for (i; i < 1000; ++i) {
		a = i % 10;
		b = (i / 10) % 10;
		c = (i / 100) % 10;
		if (i == a * a*a + b * b*b + c * c*c) {
			printf("%d \n", i);
		}

	}
	system("pause");
	return 0;
}