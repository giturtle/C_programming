#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//��������������10���ȳ����ַ���������һ���������������������������10������õ��ַ���

#define N 10
void Sort(char arr[N][20]) {
	char temp[20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			if (strcmp(arr[j], arr[j + 1]) > 0) {
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], temp);
			}
		}
	}
}

int main() {
	char str[N][20];
	printf("������%d���ȳ����ַ���:\n",N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", str[i]);
	}

	printf("\n������ַ�����С����Ϊ:\n");
	for (int i = 0; i < N; ++i) {
		printf("%s\n", str[i]);
	}
	Sort(str);
	printf("\n�������ַ�����С����Ϊ:\n");
	for (int i = 0; i < N; ++i) {
		printf("%s\n", str[i]);
	}
	system("pause");
	return 0;
}