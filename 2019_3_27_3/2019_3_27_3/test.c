//创建一个数组
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
#include <stdio.h>
#include <stdlib.h>


void init(int arr[], int size) {				//初始化数组
	for (int i = 0; i < size; ++i) {
		arr[i] = i;
	}
}
void empty(int arr[], int size) {			//清空数组
	for (int i = 0; i < size; ++i) {
		arr[i] = 0;
	}
}
void reverse(int arr[], int size) {			//完成数组的逆置
	int left = 0;
	int right = size - 1;
	while (left < right) {
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
void printarry(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d", arr[i]);
	}
	printf("\n");
}
int main() {
	
	int arr[8] ;
	int size= sizeof(arr) / sizeof(arr[0]);
	init(arr, size);
	printarry(arr, size);
	reverse(arr, size);
	printarry(arr, size);
	empty(arr, size);
	printarry(arr, size);
	system("pause"); 
	return 0;
}
