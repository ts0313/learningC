//��дһ������,����/��/��ĸ�ʽ�����û����������,
//���������յĸ�ʽ������ʾ����

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int month, day, year;
	printf("Enter a date (mm/dd/yyyy) : ");
	scanf("%d/%d/%d", &month, &day, &year);
	printf("You entered the date: %d%.2d%.2d\n", year, month, day);
	system("pause");
	return 0;
}