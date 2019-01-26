#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
		left++;
		right--;
	}
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8 };
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


