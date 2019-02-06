#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


////****************** 字符串切分函数 strtok ******************
//基于strtok进行封装，使strtok使用起来更加简单

int Split(char *input, const char *split_char,char *output[]) {
	int output_index = 0;
	char *p = strtok(input, split_char);
	while (p != NULL) {
		output[output_index++] = p;
		p = strtok(NULL, split_char);
	}
	return output_index;	//返回切分token块数
}

 
int main() {
	char str[] = "ls -l /";
	char *output[10] = { 0 };
	int n = Split(str, " ", output);
	for (int i = 0; i < n; ++i) {
		printf("%s\n", output[i]);
	}
	system("pause");
	return 0;
}
