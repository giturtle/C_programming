#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//��������Ԫ��
int main() {
	void inv(int arr[], int n);
	int i, a[10] = { 3,7,9,11,0,6,7,5,4,2 };
	printf("ԭ����Ϊ:\n");
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	inv(a, 10);
	printf("����֮�������:\n");
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

void inv(int x[], int n) {
	int temp, i, j, m = (n - 1) / 2;
	for (i = 0; i <= m; i++) {
		j = n - 1 - i;
		temp = x[i];
		x[i] = x[j];
		x[j] = temp;
	}
	printf("\n");
}

//����ָ��
int main() {
	void inv(int *arr, int n);
	int i = 0, a[10];
	printf("��������Ԫ��:\n");
	while (i < 10) {
		scanf("%d", &a[i++]);
	}
	i = 0;
	printf("ԭ����Ϊ:\n");
	while (i < 10) {
		printf("%d ", a[i++]);
	}
	int *p = a;
	printf("\n");
	i = 0;
	inv(p, 10);
	printf("���������Ϊ:\n");
	while (i < 10) {
		printf("%d ", a[i++]);
	}
	system("pause");
	return 0;
}

void inv(int *x, int n) {			//��ָ��
	int temp;
	int *j = x + (n - 1);			//βָ��
	int *m = x + ((n - 1) / 2);		//�м��ָ��
	for (; x <= m; x++, j--) {
		temp = *x;
		*x = *j;
		*j = temp;
	}
}