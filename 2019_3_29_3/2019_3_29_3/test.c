//递归和非递归分别实现求n的阶乘
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {			//非递归
	int sum=1;
	for (n; n>0; --n) {
		sum *= n;
	}
	return sum;
}

int factorial2(int n) {			//递归
	if (n <= 1) {
		return 1;
	}
	else {
		return n * factorial2(n - 1);
	}
}

int main() {
	int n;
	printf("请输入n: ");
	scanf("%d", &n);
	printf("%d\n", factorial(n));		//非递归
	printf("%d\n", factorial2(n));		//递归
	system("pause");
	return 0;
}