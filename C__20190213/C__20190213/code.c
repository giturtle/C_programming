#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



//����һ���ַ������������ֺͷ������ַ���������������������Ϊһ�����������δ�ŵ�һ����a�У�ͳ�ƹ��ж������������
void Count(char *str, char *num) {
	int count = 0;
	int i = 0;
	while (*str != '\0') {
		if (*str >= '0' && *str <= '9') {
			num[i++] = *str;
			if (*(str + 1) < '0' || *(str + 1) > '9') {
				num[i] = ';';	//���ü����';'��ͨ��strtok���
				i++;
			}
			str++;
		}
		else
			str++;
	}
	num[i] = '\0';
	printf("�ַ��������ֵ���:\n");
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
	printf("�����ַ���:\n");
	gets(str);
	Count(str, num);
	system("pause");
	return 0;
}