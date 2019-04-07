//杨氏矩阵 
#include <stdio.h>
#include <stdlib.h>

int find_data(int arr[][5], int line, int value) {
	if ((value < arr[0][0]) || (value > arr[line - 1][4])) {
		return 0;
	}
	int lin = 0;
	int col = 4;
	while ((lin < line) && (col >= 0)) {
		if (value > arr[lin][col]) {
			++lin;
		}
		else if (value < arr[lin][col]) {
			--col;
		}
		else {
			return 1;
		}
	}
	return 0;
}

int main() {
	int arr[][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	if (find_data(arr, 3, 10)) {
		printf("找到了!\n");
	}
	else {
		printf("没找到!\n");
	}
	system("pause");
	return 0;
}