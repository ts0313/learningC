//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�

#include <stdio.h>
#include <stdlib.h>

int main() {
	int criminal;
	for (criminal = 'A'; criminal <= 'D'; ++criminal) {
		if (((criminal != 'A') + (criminal == 'C') + (criminal == 'D') + (criminal != 'D')) == 3) {
			printf("������: %c\n", criminal);
		}
	}
	system("pause");
	return 0;
}