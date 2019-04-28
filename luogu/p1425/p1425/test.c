//小鱼给自己的游泳时间做了精确的计时（本题中的计时都按24小时制计算），
//它发现自己从a时b分一直游泳到当天的c时d分，请你帮小鱼计算一下，
//它这天一共游了多少时间呢？
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int ret = (c * 60 + d) - (a * 60 + b);
	a = ret / 60;
	b = ret % 60;
	printf("%d %d", a, b);
	system("pause");
	return 0;
}