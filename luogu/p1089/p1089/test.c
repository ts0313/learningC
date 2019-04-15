//P1089 ½ò½òµÄ´¢Ðî¼Æ»®
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int spend, get = 0, deposit = 0;
	for (int i = 1; i <= 12; ++i) {
		scanf("%d", &spend);
		get -= spend - 300;
		if (get < 0) {
			printf("-%d", i);
			break;
		}
		else {
			deposit += get / 100;
			get %= 100;
		}
	}
	printf("%d", 120 * deposit + get);
	system("pause");
	return 0;
}