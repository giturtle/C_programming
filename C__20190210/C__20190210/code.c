#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//有n个人围成一圈，顺序排号。从第一个人开始报数，1-3，凡是报到3的人推出圈子，问最后留下的是原来第几号的那位

int main(){
	int n, i, k, m, a[100];
	int *p;
	p = a;
	printf("请输入人数：");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		a[i] = i + 1;
	i = 0; k = 0; m = 0;
	while (m < n - 1){
		if (a[i] != 0) k++;
		if (k == 3){
			a[i] = 0;
			k = 0;
			m++;
		}
		i++;
		if (i == n) i = 0;
	}
	while (!(*p)) p++;
	printf("最后留下的是原来第%d号的那位\n", *p);
	system("pause");
	return 0;
}

//#define N 50
//int main() {
//	int n[N];
//	printf("输入 n 的大小:\n");
//	scanf("%d", &n);
//	for(int i)
//	int *p = &n[2];
//	system("pause");
//	return 0;
//}


//输入10个整数，将其中最小的数与第一个数对换，把最大的数与最后一个数对换。
//写三个函数：输入10个数，进行处理，输出10个数
int *input(int *arr) {
	printf("请输入10个整数:\n");
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &arr[i]);
	}
	return arr;
}

void print(int *arr) {
	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}
}

void reverse(int *arr) {
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < 10; ++i) {
		if (arr[i] > max) {
			max = i;
		}
		if (arr[i] < min) {
			min = i;
		}
	}
	int temp;
	temp = arr[0];
	arr[0] = arr[min];
	arr[min] = temp;

	temp = arr[9];
	arr[9] = arr[max];
	arr[max] = temp;
}

int main() {
	int arr[10];
	input(arr);
	reverse(arr);
	print(arr);
	print("\n");
	system("pause");
	return 0;
}


//输入三个字符串，由小到大输出
int main() {
	char a[100], b[100], c[100];
	char *a_ptr = a;
	char *b_ptr = b;
	char *c_ptr = c;
	printf("请输入字符串1:\n");
	gets(a);
	printf("请输入字符串2:\n");
	gets(b);
	printf("请输入字符串3:\n");
	gets(c);
	printf("从小到大的字符串顺序：\n");
	if (*a_ptr > *b_ptr){
		if (*a_ptr > *c_ptr){
			if (*b_ptr > *c_ptr){
				puts(c); puts(b); puts(a);
			}
			else{
				puts(b); puts(c); puts(a);
			}
		}
		else{
			puts(b); puts(a); puts(c);
		}
	}
	else{
		if (*b_ptr > *c_ptr){
			if (*a_ptr > *c_ptr){
				puts(c); puts(a); puts(b);
			}
			else{
				puts(a); puts(c); puts(b);
			}
		}
		else{
			puts(a); puts(b); puts(c);
		}
	}
	system("pause");
	return 0;
}