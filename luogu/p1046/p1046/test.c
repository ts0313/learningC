//P1046 ÌÕÌÕÕªÆ»¹û
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, x, count = 0, a[10] = { 0 };
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &n);
		a[i] = n;
	}
	scanf("%d", &x);
	for (int i = 0; i < 10; ++i) {
		if (x + 30 >= a[i]) {
			count++;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}