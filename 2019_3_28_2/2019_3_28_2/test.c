//��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int power(int n, int k) {
	if (k <= 0) {
		return 1;
	}
	else {
		return n * power(n, k - 1);
	}
}
int main() {
	int n, k;
	printf("����n��k\n");
	scanf("%d%d", &n, &k);
	printf("%d\n", power(n, k));
	system("pause");
	return 0;
}