//给定两个整形变量的值，将两个值的内容进行交换。
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int main() {
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = a;
	a = b;
	b = c;
	printf("%d %d", a, b);
	system("pause");
	return 0;
}



//不允许创建临时变量，交换两个数的内容
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d", a, b);
	system("pause");
	return 0;
}



//输出10个整数最大的值
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int i = 0;
	int arr[10];
	int Maximum = arr[0];

	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}for (i = 1; i < 10; i++) {
		if (arr[i] > Maximum) {
			Maximum = arr[i];
		}
	}
	printf("10个数中最大值为：\n");
	printf("%d\n", Maximum);
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int main() {
	int arr[] = { 1, 2, 3, 5, 4, 6, 7, 8, 0, 10 };
	int max = arr[0];
	for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}printf("%d\n", max);
	system("pause");
	return 0;
}

冒泡排序
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int a[10] = { 0 };
	for (i = 0; i < 10; i++)
	{
		printf("第%d个数:\n", i + 1);
		scanf("%d", &a[i]);
	}
	//冒泡排序 从小到大
	for (i = 0; i < 10; i++)
	{
		for (j = i; j < 10; j++)
		{
			if (a[i] > a[j])
			{
				tmp = a[j];
				a[j] = a[i];
				a[i] = tmp;
			}
		}
	}
	printf("最小值:%d  最大值:%d\n", a[0], a[9]);
	system("pause");
	return 0;
}





//将三个数按从大到小输出
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Max(float a, float b, float c) {
	float d = 0; float e = 0; float f = 0;
	if (a < b)
	{
		d = b;
		b = a;
		a = d;
	}
	if (a < c)
	{
		e = c;
		c = a;
		a = e;
	}
	if (b < c)
	{
		f = c;
		c = b;
		b = f;
		printf("三个数字从大大小的顺序是 %5.2f>%5.2f>%5.2f\n", a, b, c);
	}
}
int main() {
	Max(1, 2, 3);
	system("pause");
	return 0;
}



//求两个数的最大公约数
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Max(int a, int b) {
	int num;
	if (a < b) {
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
		while (a%b != 0) {
			num = a % b;
			a = b;
			b = num;
		}
		printf("最大公约数为：%d\n", num);
	}
	else if (a == b)
		printf("最大公约数为：%d\n", a);
	else if (a > b) {
		while (a%b != 0) {
			num = a % b;
			a = b;
			b = num;
		}
		printf("最大公约数为：%d\n", num);
	}
}
int main() {
	int a, b;
	printf("请输入两个值：\n");
	scanf("%d %d", &a, &b);
	Max(a, b);
	system("pause");
	return 0;
}


//两个相同元素个数的元组交换元素
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int i = 0;
	int len = 5;
	int arr1[5], arr2[5];
	printf("请输入数组1的5个数字：");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr1[i]);
	}
	printf("------------------------------\n");
	printf("请输入数组2的5个数字：");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr2[i]);
	}
	int tmp = 0;
	//int len1  = sizeof(arr1) / sizeof(arr1[0]);
	//int len2 = sizeof(arr1) / sizeof(arr1[0]);//计算数组长度
	//if (len1 != len2)
	//	printf("两个数组不一样长 重打！\n");
	//

	for (i = 0; i < len; i++)
	{
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}printf("调换后数组1为\n");
	for (i = 0; i < len; i++)
	{
		printf("%d", arr1[i]);
	}
	printf("\n");
	printf("调换后数组2为\n");
	for (i = 0; i < len; i++)
	{
		printf("%d", arr2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}





//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值。
#include<stdio.h>
#include<stdlib.h>
int main() {
	double a = 0.0, b = 0.0;
	double  sum = a + b;
	for (int i = 1; i <= 100; i++) {
		if (i % 2) {
			a = 1.0 / i;
			sum += a;
		}
		else {
			b = -1.0 / i;
			sum += b;
		}
	}
	printf("%lf\n", sum);
	system("pause");
	return 0;
}






//编写程序数一下 1到 100 的所有整数中出现多少次数字9。
#include<stdio.h>
#include<stdlib.h>
int main() {
	int i = 1, count = 0;
	for (i; i < 100; i++) {
		if (i % 10 == 9) {
			count++;
		}
		if (i / 10 == 9) {
			count++;
		}

	}printf("%d\n", count);
	system("pause");
	return 0;
}
//输出菱形（输出的菱形会向右边移一位，但问题不大）
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a = 0;//行数
	int b = 0;//空格数
	int c = 0;//星星*数
	for (a = 0; a <= 6; a++) {
		for (b = 0; b <= 6 - a; b++) {
			printf(" ");
		}
		for (c = 1; c <= 2 * a + 1; c++) {
			printf("*");
		}
		printf("\n");
	}
	for (a = 1; a <= 6; a++) {
		for (b = 1; b <= a + 1; b++) {
			printf(" ");
		}for (c = 1; c <= 13 - 2 * a; c++) {
			printf("*");
		}printf("\n");
	}//改为a=0;a<=5;a++和c<11-2a更好一些，不会有地方重复。
	system("pause");
	return 0;
}
//[最终]顶到了左边头
//输出菱形
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a = 0;//行数
	int b = 0;//空格数
	int c = 0;//星星*数
	for (a = 0; a <= 6; a++) {
		for (b = 0; b < 6 - a; b++) {
			printf(" ");
		}
		for (c = 1; c <= 2 * a + 1; c++) {
			printf("*");
		}
		printf("\n");
	}
	for (a = 1; a <= 6; a++) {
		for (b = 1; b <= a; b++) {
			printf(" ");
		}for (c = 1; c <= 13 - 2 * a; c++) {
			printf("*");
		}printf("\n");
	}
	system("pause");
	return 0;
}







//输出0~999之间的水仙花数
#include<stdio.h>
#include<stdlib.h>
int main() {
	for (int i = 100; i <= 999; i++)
	{
		int a = i / 100, b = i % 100 / 10, c = i % 100 % 10;
		if (a*a*a + c * c*c + b * b*b == i)
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}





//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	double Sn = 0, a = 0, t = 0;
	printf("请输入一个数字：");
	scanf("%d", &a);
	for (int i = 1; i <= 5; i++) {
		t = t * 10 + a;
		Sn += t;
	}
	printf("%d\n", Sn);
	system("pause");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int createnum(int a, int n) {
	if (a > 9 || a <= 0 || n <= 0) {
		return 0;
	}
	int num = 0;
	for (int i = 0; i < n; ++i) {
		num += a * (int)pow(10, i);
	}return num;
}
int main() {
	int sum = 0, a = 1;
	for (int i = 1; i <= 5; ++i) {
		sum += createnum(a, i);
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}
