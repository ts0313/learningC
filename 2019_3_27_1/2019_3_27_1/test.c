//使用函数实现两个数的交换
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
	printf("请输入两个数: ");
	scanf("%d %d", &a, &b);
	exchange(&a, &b);
	printf("%d %d", a, b);
	system("pause");
	return 0;
}