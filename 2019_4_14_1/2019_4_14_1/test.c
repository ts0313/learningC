//Ä£ÄâÊµÏÖmemcpy
#include <stdio.h>
#include <stdlib.h>

void *mymemcpy(void *str, const void *dst, size_t count) {
	void *ret = str;
	while (--count) {
		*(char*)str = *(char*)dst;
		str = (char*)str + 1;
		dst = (char*)dst + 1;
	}
	return ret;
}

int main() {
	char str[] = "abcdefghigklmn";
	char dst[] = "hello world";
	void *ret = mymemcpy(str, dst, 9);
	printf("%s\n", (char*)ret);
	system("pause");
	return 0;
}