//д����������������������в�����Ҫ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int Find_num(int a[], int size, int num) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int i = (left + right) / 2;
		if (a[i] < num) {
			left = i + 1;
			continue;
		}
		else if (a[i] > num) {
			right = i - 1;
			continue;
		}
		else {
			return i;
		}
	}
	return-1;
}

int main() {
	int num = 0;
	printf("������Ҫ���ҵ�����: ");
	scanf("%d", &num);
	int a[10] = { 1,3,4,5,7,9,10,11,12,15 };
	int size = sizeof(a) / sizeof (a[0]);
	int find_num = Find_num(a, size, num);
	if (find_num == -1) {
		printf("û�в��ҵ�!\n");
	}
	else {
		printf("�ҵ���!\n");
	}
	system("pause");
	return 0;
}
