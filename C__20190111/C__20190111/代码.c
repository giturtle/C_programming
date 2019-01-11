#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//有一个已排好序的数组，要求输入一个数后，按原来排序的规律将它插入数组中

//标准解法
int main(){
	int a[11] = { 1,4,6,9,13,16,19,28,40,100 };
	int temp, i = 0, j = 0;
	scanf("%d", &temp);
	for (i = 9; i >= 0; i--){
		if (temp < a[i]) {
			a[i + 1] = a[i];
		}
		else {
			a[i + 1] = temp;
			break;
		}
	}
	for (i = 0; i < 11; i++){
		printf("%3d", a[i]);
	}
	system("pause");
	return 0;
}

//自己做法：
//缺点：只能插入首尾元素数字之间的数字并且不能插入重复数字！否则会溢出
//而且多开辟一个数组的内存空间，浪费
//差。
int main() {
	int arr[6] = { 1,4,7,9,12 };
	int arr2[6];
	int num, i;
	printf("\n请输入插入的数字：\n");
	scanf("%d",&num);
	for (i = 0; i <= 4; i++) {
		if (num > arr[i]) {
			arr2[i] = arr[i];
		}else {
			arr2[i] = num;
			for(int j = 0; j <= 6 - i;j++) {
				arr2[i+1] = arr[i];
				i++;
			}
			break;
		}
	}
	for (i = 0; i < 6; i++) {
		printf("%3d", arr2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


//
////求一个3×3整型矩阵对角线元素之和
//int main() {
//	int arr[3][3];
//	int i,j;
//	printf("请输入3×3矩阵的元素:\n");
//	for (i = 0; i < 3; i++) {
//		for (j = 0; j < 3; j++) {
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	printf("对角线加和为:%d\n",arr[0][0]+arr[1][1]+arr[2][2]+
//		arr[0][2] + arr[2][0]);
//	system("pause");
//	return 0;
//}
//
//
////用选择法对10个整数排序
//#define number 10
//int main() {
//	int arr[10];
//	int i, j;
//	printf("请输入10个整数：\n");
//	for (i = 0; i < number; i++) {
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < number - 1; i++) {		//10个数，进行9次比较
//		for (j = 0; j < number - 1 - i; j++) {		//第一个数比较9次，依次递减
//			if (arr[j] > arr[j + 1]) {
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	printf("sorted number :");
//	for (j = 0; j < number; j++) {
//		printf("%3d", arr[j]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//
//
////用筛选法求100以内的素数
//int main() {
//	int num,i,j = 2;
//	for (i = 5; i <= 100; i += 2) {
//		for (j = 2; j <= sqrt(i); j++) {
//			if (i % j == 0)
//				break;
//			}
//		if (j >= (int)sqrt(i) + 1) {
//			printf("%3d", i);
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//
////有三个字符串，要求找出其中最大者
////不是比较长度，而是字典序大小
//int main() {
//	char arr[3][20];
//	char max[20];
//	for (int i = 0; i < 3; i++) {
//		gets(arr[i]);
//	}
//	if (strcmp(arr[0], arr[1]) > 0) {
//		strcpy(max, arr[0]);
//	}
//	else {
//		strcpy(max, arr[1]);
//	}
//	if (strcmp(arr[2],max) > 0) {
//		strcpy(max, arr[2]);
//	}
//	printf("%s\n", max);
//	system("pause");
//	return 0;
//}
//
//
//找出一行字符中有多少个单词
//int main() {
//	char str[81];
//	int i, num = 0, word = 0;
//	gets(str);
//	for (i = 0; str[i] != '\0'; i++) {
//		if (str[i] == ' ') {
//			word = 0;
//		}
//		else if (word == 0) {
//			word = 1;
//			//word 置1后在这个单词判定阶段，循环都不会进入本循环
//			//只有当到空格才会置 0 ，进行判断下一个单词
//			num++;
//		}
//	}
//	printf("%d个单词\n", num);
//	system("pause");
//	return 0;
//}
//
////构建函数
//void despace(char *s, int *i)
//{
//	while (s[*i] == ' ') (*i)++;
//}
//int main()
//{
//	int count = 0, i = 0;
//	char s[50];
//	char c;
//	gets(s);
//	while ((c = s[i]) != '\0')
//	{
//		if (c == ' ')
//		{
//			despace(s, &i);
//			count++;
//		}
//		i++;
//	}
//	count++;
//	printf("\ncount:%d", count);
//	getch();
//	return 1;
//}
//
