//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
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
	printf("������˷��ھ��������������: ");
	scanf("%d", &n);
	multip(n);
	system("pause");
	return 0;
}