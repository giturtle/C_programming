#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//strncpy

char *Strncpy(char * dest, const char * src, size_t n) {
	assert(dest != NULL);
	assert(src != NULL);
	size_t i = 0;
	for (; i < n; ++i) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}
int main() {
	char dest[20] = "12345";
	char src[6] = "67890";
	printf("%s\n", Strncpy(dest, src, 4));
	system("pause");
	return 0;
}


//strncat

char* Strncat(char* dest, const char* str, size_t n){
	assert(dest != NULL);
	assert(str != NULL);
	char *ret = dest;	//创建ret指针储存dest指针的初始位置
	while (*dest) {
		dest++;
	}
	while (n--) {
		if (!(*dest++ = *str++)) {	//指针str指向'\0'时才进行if内逻辑
			return ret;
		}
	}
	*dest = '\0';
	return ret;
}

int main() {
	char dest[20] = "iam";
	char src[10] = "pig";
	printf("%s\n", Strncat(dest, src, 3));
	system("pause");
	return 0;
}


//strncmp

int Strncmp(const char * str1, const char * str2, size_t num) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (num--) {
		if (*str1 > *str2) {
			break;
		}
		else if (*str1 < *str2) {
			break;
		}
		else {
			str1++;
			str2++;
		}
	}
	if (*str1 > *str2) {
		return 1;
	}
	else if (*str1 < *str2) {
		return -1;
	}
	else{
		return 0;
	}
}

int my_strncmp(const char* str1, const char* str2, size_t count)
{
	if (!count)//如果count=0， 直接返回零
	{
		return 0;
	}
	while (--count && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int main() {
	char str1[20] = "abcde";
	char str2[20] = "abcde";
	printf("%d\n", Strncmp(str1, str2, 3));
	system("pause");
	return 0;
}