//编写一个函数实现n^k，使用递归实现
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int power(int n, int k) {
	if (k <= 0) {
		return 1;
	}
	else {
		return n * power(n, k - 1);
	}
}
int main() {
	int n, k;
	printf("输入n和k\n");
	scanf("%d%d", &n, &k);
	printf("%d\n", power(n, k));
	system("pause");
	return 0;
}