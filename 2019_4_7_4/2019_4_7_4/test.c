//判断一个字符串是否为另外一个字符串旋转之后的字符串
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

	printf("请输入一段字符串: ");
	scanf("%s", &str);
	printf("请输入需要判断的字符串: ");
	scanf("%s", &str1);
	printf("%d\n", findStr(str, str1));
	system("pause");
	return 0;
}