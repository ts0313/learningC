//��дһ�����򣬿���һֱ���ռ����ַ�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int ch;
	printf("�������ַ�: \n");
	scanf("%d", &ch);
	while ((ch = getchar()) != EOF) {
		if (ch >= 'a' && ch <= 'z') {
			printf("%c\n", ch - 32);
		}
		if (ch >= 'A' && ch <= 'Z') {
			printf("%c\n", ch + 32);
		}
		if (ch >= '0'&&ch <= '9') {
			continue;
		}
	}
	system("pause");
	return 0;
}