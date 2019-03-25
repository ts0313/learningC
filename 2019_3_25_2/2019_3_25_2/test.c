#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int maxline = 7;
	int i;
	for (i = 1; i <= maxline; ++i) {
		int j = 0;
		for (j = 1; j <= (2 * i - 1); ++j) {
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i < maxline; ++i) {
		int j;
		for (j = 1; j <= (2 * (maxline - i) - 1); ++j) {
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}