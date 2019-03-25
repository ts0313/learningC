//编写代码模拟三次密码输入的场景
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char password[6] = { 0 };
	for (int i = 0; i < 3; ++i) {
		printf("请输入密码: \n");
		scanf("%s",  password);
		if (strcmp(password, "1234ts") == 0) {
			printf("密码输入正确! \n");
			system("pause");
			break;
		}
		else {
			printf("密码输入错误,请重新输入! \n");
		}
	}
	printf("退出程序! \n");
	system("pause");
	return 0;
}