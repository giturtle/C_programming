#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>




//输入一行字符，找出其中大写字母，小写字母，空格，数字以及其他字符数目
void Found(char* a) {
	int dx = 0, xx = 0, kg = 0, sz = 0, qt = 0;
	while (*a != '\0') {
		if (*a >= 'A' && *a <= 'Z') {
			dx++;
		}
		else if (*a >= 'a' && *a <= 'z') {
			xx++;
		}
		else if (*a > '0' && *a <= '9') {
			sz++;
		}
		else if (*a == ' ') {
			kg++;
		}
		else {
			qt++;
		}
		a++;
	}
	printf("大写字母：%d个\n", dx);
	printf("小写字母：%d个\n", xx);
	printf("数字：%d个\n", sz);
	printf("空格：%d个\n", kg);
	printf("其他字符：%d个\n", qt);
}
int main() {
	char arr[100];
	printf("请输入一行字符：\n");
	gets(arr);
	Found(arr);
	system("pause");
	return 0;
}


//写一函数，求一个字符串长度，在main函数中输入字符串，并输出其长度
int my_strlen(char str[]) {
	int count = 0;
	while(*str != '\0'){
		count++;
		str++;
	}
	return count;
}
int main() {
	char str[20];
	printf("请输入字符串：\n");
	scanf("%s",&str);
	printf("%d\n",my_strlen(str));
	system("pause");
	return 0;
}




//输入10个整数，将其中最小的数与第一个数对换，最大的数与最后一个数字对换
//写三个函数，输入10个数，进行处理，输出10个数
void input(int arr[10]) {
	printf("输入10个整数：\n");
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
}

void transform(int arr[10]) {
	int *max, *min, *p, *arr_end;
	arr_end = arr + 10;
	max = min = arr;//存放的都是地址
	for (p = arr + 1; p < arr_end; p++) {
		if (*p > *max)
			max = p;
		else if (*p < *min)
			min = p;
	}
	*p = arr[0]; arr[0] = *min; *min = *p;//最小数与第一个数交换
	*p = arr[9]; arr[9] = *max; *max = *p;//最大数与最后一个数交换
}

void output(int arr[10]) {
	int *p;
	for (p = arr; p <= arr + 9; p++) {
		printf("%3d", *p);
	}
}
int main() {
	int arr[10];
	input(arr);
	transform(arr);
	output(arr);
	system("pause");
	return 0;
}