//Ä£ÄâÊµÏÖmemmove
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void* mymemmove(void* dest, const void* src, size_t n){
	char * d = (char*)dest;
	const char * s = (const char*)src;

	if (s > d){
		while (n--)
			*d++ = *s++;
	}
	else if (s < d){
		d = d + n - 1;
		s = s + n - 1;
		while (n--)
			*d-- = *s--;
	}

	return dest;
}

int main() {
	char arr[10] = "abcdefg";
	char arr1[10] = "wow";
	char *p;
	p = mymemmove(arr, arr1, 2);
	printf("%s\n", p);
	system("pause");
	return 0;
}