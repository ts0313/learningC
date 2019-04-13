//ÊµÏÖstrstr
#include <stdio.h>
#include <stdlib.h>

char *mystrstr(char *str1, char *str2) {
	int n;
	if (*str2) {
		while (*str1) {
			for (n = 0; *(str1 + n) == *(str2 + n); ++n) {
				if (!*(str2 + n + 1)) {
					return (char*)str1;
				}
			}
			str1++;
		}
		return NULL;
	}
	else {
		return (char*)str1;
	}
}

int main() {
	char str[] = "abbcd";
	char *p;
	p = mystrstr(str, "bc");
	printf("%s", p);
	system("pause");
	return 0;
}