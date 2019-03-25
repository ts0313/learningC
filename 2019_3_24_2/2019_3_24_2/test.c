//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int a = 0;
	int i = 0;
	int num = 0;
	int sum = 0;
	printf("请输入一个一位数的正整数:");
	scanf("%d", &num);
	for (i; i < 5; ++i) {
		a = a * 10 + num;
		sum = sum + a;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}