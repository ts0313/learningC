//实现一个函数判断year是不是闰年
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int leap_year(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int x;
	printf("请输入年份: ");
	scanf("%d", &x);
	if (leap_year(x) == 1) {
		printf("闰年! ");
	}
	else {
		printf("不是闰年! ");
	}
	system("pause");
	return 0;
}