//ʵ��һ�����������������ַ����е�k���ַ�
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
	printf("������������λ��: ");
	scanf("%d", &count);
	int size = sizeof(arr) / sizeof(arr[0]) - 1;
	leftMove(arr, size, count);
	printf("������: %s\n", arr);
	system("pause");
	return 0;
}