//班主任给小玉一个任务，到文具店里买尽量多的签字笔。
//已知一只签字笔的价格是1元9角，而班主任给小玉的钱是a元b角，
//小玉想知道，她最多能买多少只签字笔呢。
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", (a * 10 + b) / 19);
	system("pause");
	return 0;
}