#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//strlen

size_t Strlen(const char *str) {
	assert(str != NULL);
	size_t val = 0;
	while (*str) {
		val++;
		str++;
	}
	return val;
}
int main() {
	char *str = "giturtle";
	printf("%lu\n",Strlen(str));
	system("pause");
	return 0;
}



//strcpy

char* Strcpy(char *dest, const char *src) {
	assert(dest != NULL);
	assert(src != NULL);
	int i = 0;	
	for (; src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
	/*while (src[i] != '\0') {
		dest[i] = src[i];	
		i++;
	}*/
	dest[i] = '\0';
	return dest;
}

int main() {
	char dest[1024] = "niubi";
	const char src[20] = "haha";
	Strcpy(dest, src);
	printf("%s\n", dest);
	system("pause");
	return 0;
}



int Strcmp(const char * str1, const char * str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 < *str2) {
			break;
		}
		else if (*str1 > *str2) {
			break;
		}
		else {
			++str1;
			++str2;
		}
	}
	/*if (*str1 == '\0' && *str2 != '\0') {
		return -1;
	}
	if (*str1 != '\0' && *str2 == '\0') {
		return 1;
	}
	if (*str1 == '\0' && *str2 == '\0') {
		return 0;
	}*/
	if (*str1 < *str2) {
		return -1;
	}
	else if (*str1 > *str2) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	char *str1 = "woshizhu";
	char *str2 = "woshizhu";
	printf("%d\n",Strcmp(str1, str2));
	system("pause");
	return 0;
}

char *Strcat(char *dest, const char *src) {
	assert(dest != NULL);
	assert(src != NULL);
	int i = 0;
	for (; dest[i] != '\0'; ++i);
	for (int j = 0; src[j] != '\0'; ++j, ++i) {
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return dest;
}
int main() {
	char dest[30] = "woshi";
	const char src[10] = "cowboy";
	Strcat(dest, src);
	printf("%s\n",dest);
	system("pause");
	return 0;
}


