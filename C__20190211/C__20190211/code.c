#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


////将一个5×5的矩阵中最大元素放在中心，4个角分别放4个最小的元素(顺序为从左到右，从上到下依次从小到大存放)
////写一个函数实现，用main函数调用

void sort(int *a) {
	int i, j, m1, m2, m3, m4, m5, temp;
	//最大元素
	for (i = 0, j = 0, m1 = a[12]; i < 25; i++)
		if (a[i] > m1) {
			m1 = a[i];
			j = i;
		}
	temp = a[12], a[12] = a[j], a[j] = temp;

	//四角元素
	for (i = 0, j = 0, m2 = *a; i < 25; i++)
		if (a[i] < m2) {
			m2 = a[i];
			j = i;
		}
	temp = *a, *a = a[j], a[j] = temp;
	for (i = 0, j = 0, m3 = *(a + 4); i < 25; i++) {
		if (i == 0) continue;
		else if (*(a + i) < m3) {
			m3 = *(a + i);
			j = i;
		}
	}
	temp = *(a + 4), *(a + 4) = *(a + j), *(a + j) = temp;
	for (i = 0, j = 0, m4 = *(a + 20); i < 25; i++) {
		if (i == 0 || i == 4) continue;
		else if (*(a + i) < m4) {
			m4 = *(a + i);
			j = i;
		}
	}
	temp = *(a + 20), *(a + 20) = *(a + j), *(a + j) = temp;
	for (i = 0, j = 0, m5 = *(a + 24); i < 25; i++) {
		if (i == 0 || i == 4 || i == 20) continue;
		else if (*(a + i) < m5) {
			m5 = *(a + i);
			j = i;
		}
	}
	temp = *(a + 24), *(a + 24) = *(a + j), *(a + j) = temp;
}

//void input(int *a){
//	int *p;
//	for (p = a, printf("请输入数组: "); p < a + 25; scanf("%d", p++));
//}
void input(int *a) {
	int i;
	for (i = 0,printf("请输入数组: "); i < 25; a++,i++) {
		scanf("%d", a);
	}
}

void print(int *a){
	int *p, i;
	for (p = a, i = 0, printf("处理后数组为:\n"); p < a + 25; printf("%5d ", *p++), i++)
		if (i && (i % 5) == 0) printf("\n");
	printf("\n");
}

int main(){
	int *arr;
	arr = (int *)calloc(5, 5 * sizeof(int));
	input(arr);
	sort(arr);
	print(arr);
	system("pause");
	return 0;
}



//#define M 3
//void Func(int arr[M][M]) {
//	int max = arr[0][0], min[4];
//	int i,j, row = 0, col = 0;
//	for (i = 0; i < M; ++i) {
//		for (j = 0; j < M; ++j) {
//			if (arr[i][j] > max) {
//				max = arr[i][j];
//				row = i;
//				col = j;
//			}
//		}
//	}
//	int temp = arr[row][col];
//	arr[row][col] = arr[M / 2][M / 2];
//	arr[M / 2][M / 2] = temp;
//
//	min[0] = arr[0][0];
//	min[1] = arr[0][1];
//	min[2] = arr[0][2];
//	min[3] = arr[1][0];
//	for (i = 0; i < M; ++i) {
//		for(j = 0; j < M ;++j){
//			for (int k = 0; k < 4; ++k) {
//				if (arr[i][j] < min[k]) {
//					min[k] = arr[i][j];
//				}
//			}
//		}
//	}
//}
//int main() {
//	int arr[M][M];
//	printf("请输入%d×%d矩阵的元素:\n", M, M);
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < M; ++j) {
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	printf("\n原数组为:\n");
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < M; ++j) {
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	Func(arr);
//	printf("\n处理后数组为:\n");
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < M; ++j) {
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}



////写一个函数，将一个3×3整型矩阵转置
//void Transform(int arr[][3]) {
//	for (int i = 0; i < 3; ++i) {
//		for (int j = i; j < 3; ++j) {
//			int temp = arr[i][j];
//			arr[i][j] = arr[j][i];
//			arr[j][i] = temp;
//		}
//	}
//}
//int main() {
//	int arr[3][3];
//	printf("请输入3×3矩阵的元素:\n");
//	for (int i = 0; i < 3; ++i) {
//		for (int j = 0; j < 3; ++j) {
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	Transform(arr);
//	for (int i = 0; i < 3; ++i) {
//		for (int j = 0; j < 3; ++j) {
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	system("pause");
//	return 0;
//}


////写一个函数，将一个3×4整型矩阵转置
//#define N 3
//#define M 4
//int main() {
//	int i, j;
//	int a[N][M], b[M][N];
//	printf("please input the value of array:\n");
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < M; j++)
//		{
//			printf("a[%d][%d]=", i, j);
//			scanf("%d", &a[i][j]);
//		}
//	}
//	printf("output array a:\n");
//	for (i = 0; i < N; i++)//输出数组a,并为数组b赋值 
//	{
//		for (j = 0; j < M; j++)
//		{
//			printf("%3d", a[i][j]);
//			b[j][i] = a[i][j];
//		}
//		printf("\n");
//	}
//	printf("\noutput array b:\n");
//	for (i = 0; i < M; i++)
//	{
//		for (j = 0; j < N; j++)
//			printf("%3d", b[i][j]);
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}



////输入一行文字，找出其中大写字母，小写字母，空格，数字以及其他字符各有多少
//int array[5];
//void Count(char *arr) {
//	assert(*arr != NULL);
//	while (*arr != '\0') {
//		if (*arr >= 'a' && *arr <= 'z') {
//			array[0]++;
//		}
//		else if (*arr >= 'A' && *arr <= 'Z') {
//			array[1]++;
//		}
//		else if (*arr >= '0' && *arr <= '9') {
//			array[2]++;
//		}
//		else if (*arr == ' ') {
//			array[3]++;
//		}
//		else
//			array[4]++;
//		arr++;
//	}
//}	
//int main() {
//	char str[100];
//	printf("请输入一行文字:\n");
//	gets(str);
//	Count(str);
//	printf("小写字母个数:%d\n", array[0]);
//	printf("大写字母个数:%d\n", array[1]);
//	printf("数字个数:%d\n", array[2]);
//	printf("空格个数:%d\n", array[3]);
//	printf("其他字符个数:%d\n", array[4]);
//	system("pause");
//	return 0;
//}



////有一字符串，包含n个字符，写一个函数，将此字符串中第m个字符开始的全部字符复制称为另一个字符串
//char *Func(char *arr, int m) {
//	assert(arr != NULL);
//	while (m--) {
//		arr++;
//	}
//	return arr;
//}
//int main() {
//	char str[] = "onetwothree";
//	int m;
//	printf("输入m值:\n");
//	//int size = sizeof(str) / sizeof(str[0]);
//	int size = strlen(str);
//	while (1) {
//		scanf("%d", &m);
//		if ((m > size) || (m < 0)) {
//			printf("输入值有误！请重新输入:\n");
//			continue;
//		}
//		else
//			break;
//	}
//	printf("%s\n",Func(str, m));
//	system("pause");
//	return 0;
//}



////写一函数，求一个字符串的长度，在main函数中输入字符串，并输出其长度
//size_t stringlength(char *arr) {
//	assert(arr != NULL);
//	size_t count = 0;
//	while (*arr++ != '\0') {
//		count++;
//	}
//	return count;
//}
//int main() {
//	char str[50];
//	printf("输入字符串:\n");
//	gets(str);
//	printf("字符串长度:%lu\n", stringlength(str));
//	system("pause");
//	return 0;
//}