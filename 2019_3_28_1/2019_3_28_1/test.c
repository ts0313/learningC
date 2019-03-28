//递归和非递归分别实现求第n个斐波那契数
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Fib(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	int last2 = 1;
	int last1 = 1;
	int cur = 0;
	for (int i = 3; i <= n; ++i) {
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}

int Fib2(int n, int last2, int last1) {
	if (n == 1) {
		return last2;
	}
	return Fib2(n - 1, last1, last1 + last2);
}


int main() {
	int n;
	printf("请输入n\n");
	scanf("%d", &n);
	printf("ret=%d\n", Fib2(n,1,1));
	system("pause");
	return 0;
}