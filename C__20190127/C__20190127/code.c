#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//调整数组使奇数全部都位于偶数前面。
//输入一个整数数组，实现一个函数，来调整该数组中数字的顺序:
//使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。
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
	printf("原数组为:\n");
	for (int i = 0; i < size; i++) {
		printf("%2d", arr[i]);
	}
	printf("\n");
	Sort(left, right);
	printf("调整后数组为:\n");
	for (int i = 0; i < size; i++) {
		printf("%2d", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}



//写一个函数使输入的一个字符串按照反序存放，在主函数输入和输出字符串
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
	printf("请输入一个字符串:\n");
	gets(arr);
	char *start = arr;
	char *end = arr + strlen(arr) - 1;
	Sort1(start,end);
	printf("调整后的字符串:\n");
	puts(arr);
	system("pause");
	return 0;
}


//写一个函数将两个字符串连接，也就是模拟实现strcat
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
	printf("请分别输入一个两个字符串:\n");
	gets(a);
	gets(b);
	my_strcat(a, b);
	printf("调整后字符串:\n");
	puts(a);
	system("pause");
	return 0;
}


//写一个函数将一个字符串的元音字母复制到另一个字符串然后输出
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
	printf("请输入一个字符串:\n");
	gets(str);
	Func(str, yuanyin);
	printf("复制到的另一个字符串为:\n");
	puts(yuanyin);
	/*while (yuanyin[i] != '\0') {
		printf("%c", yuanyin[i]);
		i++;
	}
	printf("\n");*/
	system("pause");
	return 0;
}