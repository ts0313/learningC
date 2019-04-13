//Ä£ÄâÊµÏÖstrchr
#include <stdio.h>
#include <stdlib.h>

char *mystrchr(char *s, char c) {
	while (*s != '\0' && *s != c) {
		++s;
	}
	return *s == c ? s : NULL;
}

int main() {
	char str[] = "helloworld";
	char *p;
	p = mystrchr(str, 'w');
	printf("%s", p);
	system("pause");
	return 0;
}