//��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

unsigned int reverse_bit(unsigned int value) {
	int i = 0;
	int bit = 0;
	unsigned int result = 0;
	for (i; i < 32; ++i) {
		bit = value & 1;
		value >>= 1;
		result += (bit << (31 - i));
	}
	return result;
}

int main() {
	unsigned int value;
	scanf("%u", &value);
	printf("%u\n", reverse_bit(value));
	system("pause");
	return 0;
}