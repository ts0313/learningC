//ʹ�ú���ʵ���������Ľ���
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void exchange(int *x,int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	int a, b;
	printf("������������: ");
	scanf("%d %d", &a, &b);
	exchange(&a, &b);
	printf("%d %d", a, b);
	system("pause");
	return 0;
}