//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ���
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leftMove(char *left, char *right) {
	while (*right != '\0') {
		*left = *left ^ *right;
		*right = *left ^ *right;
		*left = *left ^ *right;
		++left;
		++right;
	}
}

int findStr(char *str, char *str1) {
	int i = strlen(str);
	while (i--) {
		if (strcmp(str, str1) == 0) {
			return 1;
		}
		else {
			leftMove(str, str+1);
		}
	}
	return 0;
}

int main() {
	char str[100];
	char str1[100];

	printf("������һ���ַ���: ");
	scanf("%s", &str);
	printf("��������Ҫ�жϵ��ַ���: ");
	scanf("%s", &str1);
	printf("%d\n", findStr(str, str1));
	system("pause");
	return 0;
}