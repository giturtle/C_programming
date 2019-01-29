#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>




//编写一个函数，由实参传来一个字符串，统计此字符串中字母、数字、空格和其他字符的个数
//在主函数中输入字符串以及输出上述的结果
void Count(char *str,int arr[]) {
	while (*str != '\0') {
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
			arr[0]++;
		}
		else if (*str >= '0' && *str <= '9') {
			arr[1]++;
		}
		else if (*str == ' ') {
			arr[2]++;
		}
		else {
			arr[3]++;
		}
		str++;
	}
}

int main() {
	char str[50];
	int arr[4] = { 0 };
	printf("请输入一个字符串:\n");
	gets(str);
	Count(str,arr);
	printf("字符串中字母，数字，空格，其他字符个数如下:\n");
	for (int i = 0; i < 4; i++) {
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}


const char *arr[] = {
	"hehe",
	"haha",
	"xixi"
};


int main()
{
	int arr[10] = { 0 };
	printf("arr = %p\n", arr);
	printf("&arr = %p\n", &arr);
	printf("arr+1 = %p\n", arr + 1);
	printf("&arr+1 = %p\n", &arr + 1);
	system("pause");
	return 0;
}


int main() {
	char str1[] = "This is a C string.";
	char str2[] = "This is a C string.";
	char *str3 = "This is a C string.";
	char *str4 = "This is a C string.";

	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");

	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");
	system("pause");
	return 0;
}



//写一个函数，用起泡法对输入的10个字符按照由小到大的顺序排列
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
	printf("请输入10个字符:\n");
	gets(arr);
	printf("这10个字符为:\n");
	for (int i = 0; i < 10; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
	From_Small_To_Big(arr);
	int size = (int)sizeof(arr) / sizeof(arr[0]);
	//BubbleSort(arr, size);
	printf("调整后的字符为:\n");
	for (int i = 0; i < 10; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}





//写一个函数，输入一个4位数字，要求输出这4个数字字符，但每两个数字字符间空一个空格
//输入 1990，输出 1 9 9 0
void Func(int num) {
	assert(num >= 0);
	if (num > 9) {
		Func(num / 10);
	}
	printf("%d ", num % 10);
}
int main() {
	int num;
	printf("请输入一个四位数字:\n");
	while (1) {
		scanf("%d", &num);
		if (num < 0)
			printf("输入数字有误，请重新输入!\n");
		else
			break;
	}
	Func(num);
	system("pause");
	return 0;
}