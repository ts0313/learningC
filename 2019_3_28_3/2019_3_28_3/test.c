//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int DigitSum(int n) {
	int i = 0;
	int sum = 0;
	if (n != 0) {
		i = n % 10;
		n = n / 10;
		sum = i + DigitSum(n);
	}
	return sum;
}
int main() {
	int n;
	printf("请输入n\n");
	scanf("%d", &n);
	printf("组成它的数字之和为:%d\n", DigitSum(n));
	system("pause");
	return 0;
}