//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int a = 0;
	int i = 0;
	int num = 0;
	int sum = 0;
	printf("������һ��һλ����������:");
	scanf("%d", &num);
	for (i; i < 5; ++i) {
		a = a * 10 + num;
		sum = sum + a;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}