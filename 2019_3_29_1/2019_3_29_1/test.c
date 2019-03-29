// 编写一个函数 reverse_string(char * string)（递归实现）
#include <stdio.h>
#include <stdlib.h>

void reverse_string(char * string) {
	if (*string != '\0') {
		string++;
		reverse_string(string);
		printf("%c", *(string - 1));
	}

}
int main() {
	char * string = "xswl";
	reverse_string(string);
	system("pause");
	return 0;
}