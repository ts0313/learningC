//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Ժȶ�����ˮ��
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int empty;
	int num = 0;
	printf("������Ǯ��:");
	scanf("%d", &i);
	empty = i;
	while (empty >= 1) {
		empty += num;
		i += empty / 2;
		num = empty % 2;
		empty /= 2;
	}
	printf("���Ի�ȡ %d ƿ��ˮ\n", i);
	system("pause");
	return 0;
}