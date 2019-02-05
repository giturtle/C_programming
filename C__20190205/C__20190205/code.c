#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//****************** strstr ******************
const char *Strstr(const char *str1, const char *str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	//如果 str2 是空字符串，就不进行比较了:

	//只经过 1 次判断就完成比较（优）
	//时间复杂度 O( 1 )
	if (*str2 == '\0' || *str1 == '\0') {
		return NULL;
	}

	/*只经过 N 次判断就完成比较
	时间复杂度 O( N )
	if (strlen(*str2) == '\0' || strlen(*str1) == '\0') {
		return NULL;
	}*/
	const char *black_ptr = str1;
	while (*black_ptr != '\0') {
		const char *red_ptr = black_ptr;
		const char *sub_ptr = str2;
		while (*red_ptr != '\0' && *sub_ptr != '\0' && (*red_ptr == *sub_ptr)) {
			++red_ptr;
			++sub_ptr;
		}
		if (*sub_ptr == '\0') {
			//找到子串，返回指向str1位置的指针
			return black_ptr;
		}
		++black_ptr;
	}
	return NULL;
}

int main() {
	char str1[] = "mayamimyna";
	char str2[] = "ya";
	const char *p = Strstr(str1, str2);
	strncpy(p, "ga", 2);
	printf("%s\n", str1);
	system("pause");
	return 0;
}