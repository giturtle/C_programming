#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//�ҳ������ַ��������
void max_string(char str[][20]) {
	int i = 0;
	char arr[20];
	if (strcmp(str[0], str[1]) > 0) {
		strcmp(arr, str[0]);
	}
	else 
		strcmp(arr, str[1]);
	if (strcmp(str[2], arr) > 0) {
		strcmp(arr, str[2]);
	}
	puts(arr);
	//������
}
int main() {
	char b[3][20];
	printf("�����������ַ�����\n");
	for (int i = 0; i < 3; i++) {
		gets(b[i]);
	}
	max_string(b);
	system("pause");
	return 0;
}


//��������е������СԪ���Լ�����Ԫ�صľ�ֵ
double average(int n, double arr[]) {
	int i;
	double sum,max,min;
	max = min = sum = arr[0];
	for (i = 1; i < n; i++) {
		sum += arr[i];
		if (max < arr[i]) {
			max = arr[i];
		}
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	printf("\n���:%5.2lf,��С%5.2lf\n", max, min);
	return sum/n;
}

int main() {
	int i;
	double number[10];
	printf("����10�����֣�\n");
	for (i = 0; i < 10; i++) {
		scanf("%lf", &number[i]);
	}
	printf("ƽ��ֵΪ��%5.2lf\n", average(10, number));
	system("pause");
	return 0;
}