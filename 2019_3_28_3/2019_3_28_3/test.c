//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int DigitSum(int n) {
	int i = 0;
	int sum = 0;
	if (n != 0) {
		i = n % 10;
		n = n / 10;
		sum = i + DigitSum(n);
	}
	return sum;
}
int main() {
	int n;
	printf("������n\n");
	scanf("%d", &n);
	printf("�����������֮��Ϊ:%d\n", DigitSum(n));
	system("pause");
	return 0;
}