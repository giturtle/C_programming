#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//дһ�������������ݷ��������10���ַ�������С�����˳������
void From_Small_To_Big(char str[]) {
	for (int i = 0; i < 10; i++) {
		char ch = str[i];
		for (int j = i; j < 10; j++) {
			if (str[j] < ch){
				int temp = str[j];
				str[j] = str[i];
				str[i] = temp;
				ch = str[j];
			}
		}
		str++;
	}
}
void BubbleSort(char* arr, int size) {
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			if (arr[cur - 1] > arr[cur]) {
				int temp;
				temp = arr[cur];
				arr[cur] = arr[cur - 1];
				arr[cur - 1] = temp;
			}
		}
	}
}
int main() {
	char arr[10];
	printf("������10���ַ�:\n");
	gets(arr);
	printf("��10���ַ�Ϊ:\n");
	for (int i = 0; i < 10; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
	From_Small_To_Big(arr);
	int size = (int)sizeof(arr) / sizeof(arr[0]);
	//BubbleSort(arr, size);
	printf("��������ַ�Ϊ:\n");
	for (int i = 0; i < 10; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}



////��дһ����������ʵ�δ���һ���ַ�����ͳ�ƴ��ַ�������ĸ�����֡��ո�������ַ��ĸ���
////���������������ַ����Լ���������Ľ��
//void Count(char *str,int arr[]) {
//	while (*str != '\0') {
//		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
//			arr[0]++;
//		}
//		else if (*str >= '0' && *str <= '9') {
//			arr[1]++;
//		}
//		else if (*str == ' ') {
//			arr[2]++;
//		}
//		else {
//			arr[3]++;
//		}
//		str++;
//	}
//}
//
//int main() {
//	char str[50];
//	int arr[4] = { 0 };
//	printf("������һ���ַ���:\n");
//	gets(str);
//	Count(str,arr);
//	printf("�ַ�������ĸ�����֣��ո������ַ���������:\n");
//	for (int i = 0; i < 4; i++) {
//		printf("%d\n", arr[i]);
//	}
//	system("pause");
//	return 0;
//}



////дһ������������һ��4λ���֣�Ҫ�������4�������ַ�����ÿ���������ַ����һ���ո�
////���� 1990����� 1 9 9 0
//void Func(int num) {
//	assert(num >= 0);
//	if (num > 9) {
//		Func(num / 10);
//	}
//	printf("%d ", num % 10);
//}
//int main() {
//	int num;
//	printf("������һ����λ����:\n");
//	while (1) {
//		scanf("%d", &num);
//		if (num < 0)
//			printf("����������������������!\n");
//		else
//			break;
//	}
//	Func(num);
//	system("pause");
//	return 0;
//}