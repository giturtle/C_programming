#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



//输入一个字符串，内有数字和非数字字符，将其中连续的数组作为一个整数，依次存放到一数组a中，统计共有多少整数并输出
void Count(char *str, char *num) {
	int count = 0;
	int i = 0;
	while (*str != '\0') {
		if (*str >= '0' && *str <= '9') {
			num[i++] = *str;
			if (*(str + 1) < '0' || *(str + 1) > '9') {
				num[i] = ';';	//设置间隔符';'，通过strtok拆分
				i++;
			}
			str++;
		}
		else
			str++;
	}
	num[i] = '\0';
	printf("字符串中数字的有:\n");
	char * pch;
	pch = strtok(num, ";");
	while (pch != NULL){
		printf("%s\n", pch);
		pch = strtok(NULL, ";");
	}
}
int main() {
	char str[50];
	char num[50];
	printf("输入字符串:\n");
	gets(str);
	Count(str, num);
	system("pause");
	return 0;
}