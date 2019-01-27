#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//��������ʹ����ȫ����λ��ż��ǰ�档
//����һ���������飬ʵ��һ�������������������������ֵ�˳��:
//ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
void Sort(int *left, int *right) {
	while (left < right) {
		if (*left % 2 == 0 && *right % 2 == 1) {
			int temp = *left;
			*left = *right;
			*right = temp;
			continue;
		}
		if (*left % 2 == 0) {
			right--;
			continue;
		}	
		if (*right % 2 == 1) {
			left++;
			continue;
		}
		left++;
		right--;
	}
}

int main() {
	int arr[] = { 1,3,4,5,2,7,6,9,8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int *left = arr;
	int *right = left + size - 1;
	printf("ԭ����Ϊ:\n");
	for (int i = 0; i < size; i++) {
		printf("%2d", arr[i]);
	}
	printf("\n");
	Sort(left, right);
	printf("����������Ϊ:\n");
	for (int i = 0; i < size; i++) {
		printf("%2d", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}



//дһ������ʹ�����һ���ַ������շ����ţ������������������ַ���
void Sort1(char *start,char *end) {
	assert(start != NULL);
	assert(end != NULL);
	while (start < end) {
		int temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

int main() {
	char arr[20];
	printf("������һ���ַ���:\n");
	gets(arr);
	char *start = arr;
	char *end = arr + strlen(arr) - 1;
	Sort1(start,end);
	printf("��������ַ���:\n");
	puts(arr);
	system("pause");
	return 0;
}


//дһ�������������ַ������ӣ�Ҳ����ģ��ʵ��strcat
void my_strcat(char arr1[], char arr2[]) {
	int i = 0,j = 0;
	while (arr1[i] != '\0') {
		i++;
	}
	while (arr2[j] != '\0') {
		arr1[i++] = arr2[j++];
	}
	arr1[i] = '\0';
}

int main() {
	char a[20];
	char b[10];
	printf("��ֱ�����һ�������ַ���:\n");
	gets(a);
	gets(b);
	my_strcat(a, b);
	printf("�������ַ���:\n");
	puts(a);
	system("pause");
	return 0;
}


//дһ��������һ���ַ�����Ԫ����ĸ���Ƶ���һ���ַ���Ȼ�����
void Func(char *str,char yuanyin[]) {
	int i = 0;
	while (*str != '\0') {
		if (*str != 'A' && *str != 'E' && *str != 'I' && *str != 'O' && *str != 'U'
			&& *str != 'a' && *str != 'e' && *str != 'i' && *str != 'o' && *str != 'u') {
			str++;
		}
		else {
			yuanyin[i] = *str;
			i++;
			str++;
		}
	}
	yuanyin[i] = '\0';
}

int main() {
	char str[20];
	char yuanyin[10];
	int i = 0;
	printf("������һ���ַ���:\n");
	gets(str);
	Func(str, yuanyin);
	printf("���Ƶ�����һ���ַ���Ϊ:\n");
	puts(yuanyin);
	/*while (yuanyin[i] != '\0') {
		printf("%c", yuanyin[i]);
		i++;
	}
	printf("\n");*/
	system("pause");
	return 0;
}