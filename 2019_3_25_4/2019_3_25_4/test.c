//��д����ģ��������������ĳ���
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char password[6] = { 0 };
	for (int i = 0; i < 3; ++i) {
		printf("����������: \n");
		scanf("%s",  password);
		if (strcmp(password, "1234ts") == 0) {
			printf("����������ȷ! \n");
			system("pause");
			break;
		}
		else {
			printf("�����������,����������! \n");
		}
	}
	printf("�˳�����! \n");
	system("pause");
	return 0;
}