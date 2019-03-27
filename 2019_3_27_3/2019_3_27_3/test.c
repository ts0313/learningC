//����һ������
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
#include <stdio.h>
#include <stdlib.h>


void init(int arr[], int size) {				//��ʼ������
	for (int i = 0; i < size; ++i) {
		arr[i] = i;
	}
}
void empty(int arr[], int size) {			//�������
	for (int i = 0; i < size; ++i) {
		arr[i] = 0;
	}
}
void reverse(int arr[], int size) {			//������������
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
