//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩

#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[] = { 1,2,3,5,4,4,3,2,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 1; i < len; ++i) {
		arr[0] = arr[0] ^ arr[i];
	}
	printf("%d\n", arr[0]);
	system("pause");
	return 0;
}