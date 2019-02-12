#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>





//将n个数按照输入时的逆序排列，用函数实现
void Sort(int *arr,int size) {
	for (int i = size - 1; i >= 0; --i) {
		printf("%3d", *(arr + i));
	}
	printf("\n");
}
int main() {
	int arr[5] = { 1,2,3,4,5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Sort(arr,size);
	system("pause");
	return 0;
}


//写一个用矩阵法求定积分的通用函数
float integral(float(*p)(float), float a, float b, int n) {
	int i;
	float x, h, s;
	h = (b - a) / n;
	x = a;
	s = 0;
	for (i = 1; i <= n; i++) {
		x = x + h;
		s = s + (*p)(x) * h;
	}
	return s;
}

float fsin(float x) {
	return sin(x);
}

float fcos(float x) {
	return cos(x);
}

float fexp(float x) {
	return exp(x);
}

int main() {
	float a1, b1, a2, b2, a3, b3, (*p)(float), c;
	int n = 20;
	scanf("%f %f", &a1, &b1);
	scanf("%f %f", &a2, &b2);
	scanf("%f %f", &a3, &b3);

	p = fsin;
	c = integral(p, a1, b1, n);
	printf("The integral of sin(x) is:%f\n", c);
	p = fcos;
	c = integral(p, a2, b2, n);
	printf("The integral of cos(x) is:%f\n", c);
	p = fexp;
	c = integral(p, a3, b3, n);
	printf("The integral of exp(x) is:%f\n", c);
	return 0;
}





//在主函数中输入10个等长的字符串，用另一个函数进行排序，在主函数输出这10个排序好的字符串

#define N 3
void Sort(char arr[N][20]) {
//void sort(char(*p)[20]) {		//等效的定义方式
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
	printf("请输入%d个等长的字符串:\n",N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", str[i]);
	}

	printf("\n输入的字符串从小到大为:\n");
	for (int i = 0; i < N; ++i) {
		printf("%s\n", str[i]);
	}
	//Sort(str);
	sort(str);
	printf("\n处理后的字符串从小到大为:\n");
	for (int i = 0; i < N; ++i) {
		printf("%s\n", str[i]);
	}
	system("pause");
	return 0;
}