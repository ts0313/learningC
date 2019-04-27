//P1909 ÂòÇ¦±Ê
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, n, m, _num, _money, num, money = 0;
	scanf("%d", &num);
	for (i = 0; i < 3; ++i) {
		scanf("%d %d", &_num, &_money);
		n = _num;
		m = _money;
		while (_num < num) {
			_num *= 2;
			_money *= 2;
		}
		while (_num > num) {
			_num -= n;
			_money -= m;
		}
		while (_num < num) {
			_num += n;
			_money += m;
		}
		if (_money < money || money == 0) {
			money = _money;
		}
	}
	printf("%d\n", money);
	system("pause");
	return 0;
}