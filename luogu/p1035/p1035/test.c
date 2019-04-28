//P1035 级数求和
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int k;
	double ret = 0;
	scanf("%d", &k);
	for (int n = 1; n < 1024 * 1024; ++n) {
		ret = ret + 1.0 / n;
		if (ret > k) {
			printf("%d\n", n);
			break;
		}
	}
	system("pause");
	return 0;
}