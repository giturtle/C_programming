#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//int int_cmp(const void * p1, const void * p2){
//	return (*(int *)p1 > *(int *)p2);
//}
//
//int main(){
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	int i = 0;
//
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
void int_cmp(const void *p1, const void *p2) {
	return (*(int *)p1 > *(int *)p2);
}


void _swap(void *p1,void *p2,int size){
	int i = 0;
	for (; i < size; i++) {
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}

void bubble(void *base, int count, int size, int(*cmp)(void *, void *)){
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (cmp((char *)base + j * size, (char *)base + (j + 1)*size) > 0)
			{
				_swap((char *)base + j * size, (char *)base + (j + 1)*size, size);
			}
		}
	}
}
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	//char *arr[] = {"aaaa","dddd","cccc","bbbb"};
	int i = 0;
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

//一般逻辑：
void Bubble_Sort(int *str,int size) {
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			if (str[cur] < str[cur - 1]) {
				int temp = str[cur];
				str[cur] = str[cur - 1];
				str[cur - 1] = temp;
			}
		}
	}
}
//回调函数处理：
typedef int(*T)(int, int);
//参数中引入了一个函数指针，这个函数指针描述了排序规则

//此处这样约定，cmp传两个参数，如果符合排序要求，返回1。不符合时，返回0。
void BubbleSort(int *str, int size,T cmp) {
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			if (cmp(str[cur - 1],str[cur]) == 0) {
				int temp = str[cur];
				str[cur] = str[cur - 1];
				str[cur - 1] = temp;
			}
		}
	}
}
int Less(int x, int y) {
	return x < y ? 1 : 0;
}
int Greater(int x, int y) {
	return x > y ? 1 : 0;
}
int Abs(int x, int y) {
	return abs(x) < abs(y) ? 1 : 0;
}
int main() {
	int arr[10] = { 1,6,5,4,-3,7,8,-9,2,0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//升序排序
	BubbleSort(arr, size, Abs);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}



//表驱动/转移表
int add(int a, int b) {		//加法函数
	return a + b;
}

int sub(int a, int b) {		//减法函数
	return a - b;
}

int mul(int a, int b) {		//乘法函数
	return a * b;
}

int divd(int a, int b) {		//除法函数
	return a / b;
}

int main() {
	int x, y;
	int input = 1;
	int ret = 0;
	int(*p[5])(int, int) = { 0, add, sub, mul, divd }; //转移表
	while (input) {
		printf("*************************\n");
		printf("  1:add           2:sub  \n");
		printf("  3:mul           4:div  \n");
		printf("*************************\n");
		printf("请选择：");
		scanf("%d", &input);
		if ((input <= 4 && input >= 1)) {
			printf("输入操作数：");
			scanf("%d %d", &x, &y);
			ret = (*p[input])(x, y);
		}
		else
			printf("输入有误\n");
		printf("ret = %d\n", ret);
	}
	system("pause");
	return 0;
}



int Func() {
	printf("hehe\n");
	return 10;
}
int main() {
	printf("%p\n", Func);
	printf("%p\n", &Func);
	printf("%p\n", Func());

	printf("%p\n", *Func);
	printf("%p\n", (*Func)());
	//定义了一个指针变量p，p的类型是int(*)()的函数指针类型
	//与数组指针int(*)[]区分，所以建议使用时进行类型重定义，使代码简单直观
	int (*p)() = Func;
	//此时定义了一个类型的别名 T；
	typedef int(*T)();
	T p2 = Func;
	system("pause");
	return 0;
}
