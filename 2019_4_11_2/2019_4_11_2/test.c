//Ä£ÄâÊµÏÖstrcpy 
#include <stdio.h>
#include <stdlib.h>

char *Strcpy(char *dest, const char *str) {
	char *ret = dest;
	while (*dest++ = *str++) {
		;
	}
	return ret;
}

int main() {
	char arr1[64] = { 0 };
	char arr2[] = "Hello World";
	Strcpy(arr1, arr2);
	printf("%s\n", arr1);
	system("pause");
	return 0;
}