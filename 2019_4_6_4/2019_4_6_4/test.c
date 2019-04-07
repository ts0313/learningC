//有一个字符数组的内容为:"student a am i",
//请你将数组的内容改为"i am a student".
//要求：
//不能使用库函数。
//只能开辟有限个空间

#include <stdio.h>
#include <stdlib.h>

void reverse(char *left, char *right) {
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void reverse_str(char arr[], int size) {
	char *left = arr;
	char *right = arr + size - 1;
	char *start = arr;
	char *end = arr;
	reverse(left, right);
	while (*end != '\0') {
		while ((*end != ' ') && (*end != '\0')) {
			++end;
		}
		reverse(start, end - 1);
		if (*end != '\0') {
			start = end + 1;
			end = start;
		}
	}
}

int main() {
	char arr[] = "student a am i";
	int size = sizeof(arr) / sizeof(arr[0])-1;
	reverse_str(arr, size);
	printf("%s\n", arr);
	system("pause");
	return 0;
}