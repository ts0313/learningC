// ����������ʱ����������������������
#include<stdio.h>
#include<stdlib.h>

int main() {
	int a, b;
	a = 1;
	b = 2;
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d", a, b);
	system("pause");
	return 0;
}
	