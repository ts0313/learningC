//实现一个函数，判断一个数是不是素数
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int prime_num(int num) {
	int i = 0;
	for (i = 2; i < num; ++i) {
		if (num%i == 0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int x = 0;
	int num = 0;
	printf("请输入一个数: ");
	scanf("%d", &num);
	x = prime_num(num);
	if (x == 1) {
		printf("是素数\n");
	}
	else {
		printf("不是素数\n");
	}
	system("pause");
	return 0;
}