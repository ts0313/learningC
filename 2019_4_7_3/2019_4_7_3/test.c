//实现一个函数，可以左旋字符串中的k个字符
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void move(char *arr, int count) {
	int i = 0;
	char tmp = arr[0];
	for (i; i < count - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	arr[i] = tmp;
	--count;
}

void leftMove(char *arr, int size, int count) {
	count %= size;
	while (count--) {
		move(arr, size);
	}
}

int main() {
	char arr[] = "ABCDEF";
	printf("%s\n", arr);
	int count = 0;
	printf("请输入左旋的位数: ");
	scanf("%d", &count);
	int size = sizeof(arr) / sizeof(arr[0]) - 1;
	leftMove(arr, size, count);
	printf("左旋后: %s\n", arr);
	system("pause");
	return 0;
}