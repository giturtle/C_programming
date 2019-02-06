#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


////****************** �ַ����зֺ��� strtok ******************
//����strtok���з�װ��ʹstrtokʹ���������Ӽ�

int Split(char *input, const char *split_char,char *output[]) {
	int output_index = 0;
	char *p = strtok(input, split_char);
	while (p != NULL) {
		output[output_index++] = p;
		p = strtok(NULL, split_char);
	}
	return output_index;	//�����з�token����
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
