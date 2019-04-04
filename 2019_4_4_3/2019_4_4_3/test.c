//在屏幕上打印杨辉三角
#include <stdio.h>
#include <stdlib.h>
#define N 8

int main() {
	int arr[N][N] = { 0 };
	int i = 0;
	for (i; i <= N; ++i) {
		int k = 0;
		for (k; k <= N - i; ++k) {
			printf("  ");
		}
		int j = 0;
		for (j; j <= i; ++j) {
			if ((0 == j) || (i == j)) {
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}