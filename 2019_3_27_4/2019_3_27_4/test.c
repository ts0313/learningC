//ʵ��һ���������ж�һ�����ǲ�������
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
	printf("������һ����: ");
	scanf("%d", &num);
	x = prime_num(num);
	if (x == 1) {
		printf("������\n");
	}
	else {
		printf("��������\n");
	}
	system("pause");
	return 0;
}