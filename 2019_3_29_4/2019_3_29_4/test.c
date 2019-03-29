//递归方式实现打印一个整数的每一位
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Print(int n) {
	if (n > 9) {
		Print(n / 10);
	}
	printf("%d ", n % 10);
}

int main() {
	int n;
	printf("请输入n: ");
	scanf("%d", &n);
	Print(n);
	system("pause");
	return 0;
}