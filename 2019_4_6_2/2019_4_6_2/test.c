//��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a;
	int b;
	printf("������a b��ֵ: ");
	scanf("%d%d", &a, &b);
	printf("%d\n", (a - ((a - b) >> 1)));
	system("pause");
	return 0;
}