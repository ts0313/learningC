//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void multip(int n) {
	int i, j;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= i;++j) {
			printf("%d*%d=%d   ", i, j, i*j);
		}
		printf("\n");
	}
}

int main() {
	int n = 0;
	printf("请输入乘法口诀表的行数和列数: ");
	scanf("%d", &n);
	multip(n);
	system("pause");
	return 0;
}