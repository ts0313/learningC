//调整数组使奇数全部都位于偶数前面

#include <stdio.h>
#include <stdlib.h>

void Sequence(int arr[], int len) {
	int i, j;
	for (i = 0; i < len; ++i) {
		if (arr[i] % 2 == 0) {
			for (j = i + 1; j < len; ++j) {
				if (arr[j] % 2 == 1) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					break;
				}
			}
		}
		printf("%d ", arr[i]);
	}
}

int main() {
	int len;
	int arr[] = { 1,2,4,5,6,9,12,15 };
	len = sizeof(arr) / sizeof(arr[0]);
	Sequence(arr, len);
	system("pause");
	return 0;
}