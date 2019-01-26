#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//��������ʹ����ȫ����λ��ż��ǰ�档
//����һ���������飬ʵ��һ�������������������������ֵ�˳��:
//ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
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
	printf("ԭ����Ϊ:\n");
	for (int i = 0; i < size; i++) {
		printf("%2d", arr[i]);
	}
	printf("\n");
	Sort(left, right);
	printf("����������Ϊ:\n");
	for (int i = 0; i < size; i++) {
		printf("%2d", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


