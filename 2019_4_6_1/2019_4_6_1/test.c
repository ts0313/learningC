//编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。

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