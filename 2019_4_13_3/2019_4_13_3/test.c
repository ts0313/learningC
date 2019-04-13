//Ä£ÄâÊµÏÖstrcmp
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int mystrcmp(const char *src, const char *dst) {
	int ret = 0;
	assert(src != NULL);
	assert(dst != NULL);
	while (!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst) {
		++src;
		++dst;
	}
	if (ret < 0) {
		ret = -1;
	}
	else if (ret > 0) {
		ret = 1;
	}
	return  ret;
}

int main() {
	char str1[1024] = { 1,2,3,4,5 };
	char str2[1024] = { 1,2,3,4,5 };
	int ret = mystrcmp(str1, str2);
	printf("%d\n", ret);
	system("pause");
	return 0;
}