//ʵ��һ�������ж�year�ǲ�������
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
	printf("���������: ");
	scanf("%d", &x);
	if (leap_year(x) == 1) {
		printf("����! ");
	}
	else {
		printf("��������! ");
	}
	system("pause");
	return 0;
}