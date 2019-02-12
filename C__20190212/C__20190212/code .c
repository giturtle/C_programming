#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>





//��n������������ʱ���������У��ú���ʵ��
void Sort(int *arr,int size) {
	for (int i = size - 1; i >= 0; --i) {
		printf("%3d", *(arr + i));
	}
	printf("\n");
}
int main() {
	int arr[5] = { 1,2,3,4,5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Sort(arr,size);
	system("pause");
	return 0;
}


//дһ���þ����󶨻��ֵ�ͨ�ú���
float integral(float(*p)(float), float a, float b, int n) {
	int i;
	float x, h, s;
	h = (b - a) / n;
	x = a;
	s = 0;
	for (i = 1; i <= n; i++) {
		x = x + h;
		s = s + (*p)(x) * h;
	}
	return s;
}

float fsin(float x) {
	return sin(x);
}

float fcos(float x) {
	return cos(x);
}

float fexp(float x) {
	return exp(x);
}

int main() {
	float a1, b1, a2, b2, a3, b3, (*p)(float), c;
	int n = 20;
	scanf("%f %f", &a1, &b1);
	scanf("%f %f", &a2, &b2);
	scanf("%f %f", &a3, &b3);

	p = fsin;
	c = integral(p, a1, b1, n);
	printf("The integral of sin(x) is:%f\n", c);
	p = fcos;
	c = integral(p, a2, b2, n);
	printf("The integral of cos(x) is:%f\n", c);
	p = fexp;
	c = integral(p, a3, b3, n);
	printf("The integral of exp(x) is:%f\n", c);
	return 0;
}





//��������������10���ȳ����ַ���������һ���������������������������10������õ��ַ���

#define N 3
void Sort(char arr[N][20]) {
//void sort(char(*p)[20]) {		//��Ч�Ķ��巽ʽ
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
	printf("������%d���ȳ����ַ���:\n",N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", str[i]);
	}

	printf("\n������ַ�����С����Ϊ:\n");
	for (int i = 0; i < N; ++i) {
		printf("%s\n", str[i]);
	}
	//Sort(str);
	sort(str);
	printf("\n�������ַ�����С����Ϊ:\n");
	for (int i = 0; i < N; ++i) {
		printf("%s\n", str[i]);
	}
	system("pause");
	return 0;
}