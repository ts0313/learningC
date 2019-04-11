//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以喝多少汽水。
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int empty;
	int num = 0;
	printf("请输入钱数:");
	scanf("%d", &i);
	empty = i;
	while (empty >= 1) {
		empty += num;
		i += empty / 2;
		num = empty % 2;
		empty /= 2;
	}
	printf("可以换取 %d 瓶汽水\n", i);
	system("pause");
	return 0;
}