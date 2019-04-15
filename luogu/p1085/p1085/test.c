//津津上初中了。妈妈认为津津应该更加用功学习，所以津津除了上学之外，
//还要参加妈妈为她报名的各科复习班。另外每周妈妈还会送她去学习朗诵、舞蹈和钢琴。
//但是津津如果一天上课超过八个小时就会不高兴，而且上得越久就会越不高兴。
//假设津津不会因为其它事不高兴，并且她的不高兴不会持续到第二天。
//请你帮忙检查一下津津下周的日程安排，看看下周她会不会不高兴；
//如果会的话，哪天最不高兴。

#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

int main() {
	int a[7], b[7], c[7];
	int max, t = 0, i;
	for (i = 0; i < 7; i++) {
		scanf("%d%d", &a[i], &b[i]);
		c[i] = a[i] + b[i];
	}
	max = c[0];
	for (i = 0; i < 7; i++) {
		if (c[i] > max) {
			max = c[i];
			t = i;
		}
	}
	if (max <= 8) {
		printf("0\n");
	}
	else {
		printf("%d\n", t + 1);
	}
	system("pause");
	return 0;
}