//�ݹ�ͷǵݹ�ֱ�ʵ��strlen 
#include <stdio.h>
#include <stdlib.h>

int strlen1(char * string) {		//�ǵݹ�
	int count = 0;
	while (*string != '\0') {
		++count;
		++string;
	}
	return count;
}

int strlen2(char * string) {		//�ݹ�
	if (*string != '\0') {
		return 1 + strlen2(string + 1);
	}
	else {
		return 0;
	}
}
int main() {
	char string[] = "xswlhahaha";
	printf("%d\n", strlen1(string));
	printf("%d\n", strlen2(string));
	system("pause");
	return 0;
}