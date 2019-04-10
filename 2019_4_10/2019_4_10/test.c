//一个数组中只有两个数字是出现一次， 其他所有数字都出现了两次，找出这两个数字
#include <stdio.h>
#include <stdlib.h>

void find_num(int arr[], int len) {
	int i = 0;
	int ret = 0;
	int pos = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < len; ++i) {
		ret ^= arr[i];
	}
	for (i = 0; i < 32; ++i) {
		if (i == ((ret >> i) & 1)) {
			pos = i;
			break;
		}
	}
	for (i = 0; i < len; ++i) {
		if (1 == ((arr[i] >> pos) & 1)) {
			x ^= arr[i];
		}
		else {
			y ^= arr[i];
		}
	}
	printf("x=%d,y=%d\n", x, y);
}

int main() {
	int arr[] = { 1,2,3,4,5,6,4,3,2,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	find_num(arr, size);
	system("pause");
	return 0;
}