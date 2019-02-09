#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




//输入3个整数，按由小到大的顺序输出
int main() {
	int a, b, c;
	int *a_ptr = &a;
	int *b_ptr = &b;
	int *c_ptr = &c;
	printf("请输入三个整数：\n");
	scanf("%d %d %d", a_ptr,b_ptr,c_ptr);
	if (*a_ptr > *b_ptr) {
		int temp = *a_ptr;
		*a_ptr = *b_ptr;
		*b_ptr = temp;
	}
	if (*a_ptr > *c_ptr) {
		int temp = *a_ptr;
		*a_ptr = *c_ptr;
		*c_ptr = temp;
	}
	if (*b_ptr > *c_ptr) {
		int temp = *b_ptr;
		*b_ptr = *c_ptr;
		*c_ptr = temp;
	}
	printf("由小到大的顺序为：%d %d %d\n", *a_ptr, *b_ptr, *c_ptr);
	system("pause");
	return 0;
}