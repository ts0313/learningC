//Ä£ÄâÊµÏÖstrcat 
#include <stdio.h>
#include <stdlib.h>

char *Strcat(char *dest, const char *src) {
	int i = 0;
	for (; dest[i] != '\0'; ++i);
	for (int j = 0; src[j] != '\0'; ++i, ++j) {
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return dest;
}

int main() {
	char str1[1024] = "aaa";
	char str2[1024] = "bbb";
	Strcat(str1, str2);
	printf("%s\n", str1);
	printf("%s\n", str2);
	system("pause");
	return 0;
}