//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {			//�ǵݹ�
	int sum=1;
	for (n; n>0; --n) {
		sum *= n;
	}
	return sum;
}

int factorial2(int n) {			//�ݹ�
	if (n <= 1) {
		return 1;
	}
	else {
		return n * factorial2(n - 1);
	}
}

int main() {
	int n;
	printf("������n: ");
	scanf("%d", &n);
	printf("%d\n", factorial(n));		//�ǵݹ�
	printf("%d\n", factorial2(n));		//�ݹ�
	system("pause");
	return 0;
}