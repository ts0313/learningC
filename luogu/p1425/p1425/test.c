//С����Լ�����Ӿʱ�����˾�ȷ�ļ�ʱ�������еļ�ʱ����24Сʱ�Ƽ��㣩��
//�������Լ���aʱb��һֱ��Ӿ�������cʱd�֣������С�����һ�£�
//������һ�����˶���ʱ���أ�
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