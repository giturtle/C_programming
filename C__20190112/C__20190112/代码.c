#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>





标准 <冒泡排序>
void Swap(int *x,int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void BubbleSort(int* arr,int size) {
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			if (arr[cur - 1] > arr[cur]) {
				Swap(&arr[cur - 1], &arr[cur]);
				//交换二者数值，不使用函数直接交换也是可以的
			}
		}
	}
}
int main() {
	int arr[10] = { 1,3,4,6,5,2,8,7,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr,size);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%3d", arr[i]);
	}
	system("pause");
	return 0;
}