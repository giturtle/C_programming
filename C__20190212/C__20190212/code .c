#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//在主函数中输入10个等长的字符串，用另一个函数进行排序，在主函数输出这10个排序好的字符串

#define N 10
void Sort(char arr[N][20]) {
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
	Sort(str);
	printf("\n处理后的字符串从小到大为:\n");
	for (int i = 0; i < N; ++i) {
		printf("%s\n", str[i]);
	}
	system("pause");
	return 0;
}