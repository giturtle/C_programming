#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//将一个数组中的值按照逆序从新存放
//例如原来顺序是8,6,5,4,1
//要求改为 1,4,5,6,8
#define N 5
int main() {
	int a[5], i, temp;
	printf("请输入数组:\n");
	for (i = 0; i < N; ++i) {
		scanf("%d", &a[i]);
	}
	printf("数组为:\n");
	for (i = 0; i < N; ++i) {
		printf("%5d", a[i]);
	}
	for (i = 0; i < N / 2; ++i) {
		temp = a[i];
		a[i] = a[N - i - 1];
		a[N - i - 1] = temp;
	}
	printf("\n逆序后数组为:\n");
	for (i = 0; i < N; ++i) {
		printf("%5d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}



//已有一个已排好序的数组,今输入一个数字
//要求按原来排序的规律将它插入数组中
int main() {
	int i, j,num;
	int a[11] = { 1,4,6,9,13,16,19,28,40,100 };
	//这里因为要插入元素,所以提前设定多一位的数组,越界保护
	printf("数组为:\n");
	for (i = 0; i < 10; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("请输入想要插入的数字:\n");
	scanf("%d", &num);

	i = 0;
	while (a[i] < num && i < 10) {
		i++;
	}
	for (j = 9; j >= i; j--) {
		a[j + 1] = a[j];
	}
	a[i] = num;
	printf("现在数组为:\n");
	for (i = 0; i < 11; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}



//求一个3 × 3矩阵对角线的元素之和
int main() {
	int i, j, a[3][3], sum = 0;
	printf("请输入一个3 × 3矩阵:\n");
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			if (i == j) {
				sum += a[i][j];
			}
		}
	}
	printf("对角线元素之和为:%d\n", sum);
	system("pause");
	return 0;
}



//用选择法对10个整数排序
int main() {
	int i, j, temp, min, a[11];
	printf("     请输入10个数:     \n\n");
	for (i = 1; i <= 10; ++i) {
		printf("请输入第%d个数:\n", i);
		scanf("%d", &a[i]);
	}
	printf("\n");
	printf("输入数字:\n");
	for (i = 1; i <= 10; ++i) {
		printf("%5d", a[i]);
	}
	printf("\n");
	//这里是排序
	for (i = 1; i <= 10; ++i) {
		min = i;
		for (j = i + 1; j <= 10; ++j) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	printf("排序完成效果:\n");
	for (i = 1; i <= 10; ++i) {
		printf("%5d", a[i]);
	}

	system("pause");
	return 0;
}




//用筛选法求100以内的素数
int main() {
	int i, j, count;
	int a[100];
	for (i = 1; i <= 100; ++i) {
		a[i] = i;
	}
	for (i = 2; i < sqrt(100); ++i) {
		//如果j能被i整除 则不是素数 a[j]置为 0;
		for (j = i + 1; j <= 100; ++j) {
			if (a[i] != 0 && a[j] != 0) {
				if (a[j] % a[i] == 0) {
					a[j] = 0;
				}
			}
		}
	}
	printf("\n");
	for (i = 2, count = 0; i < 100; ++i) {
		if (a[i] != 0) {
			printf("%5d ", a[i]);
			count++;
		}
		if (count == 10) {
			printf("\n");
			count = 0;
		}
	}
	system("pause");
	return 0;
}