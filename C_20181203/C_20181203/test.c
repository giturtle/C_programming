//�����������α�����ֵ��������ֵ�����ݽ��н�����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int main() {
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = a;
	a = b;
	b = c;
	printf("%d %d", a, b);
	system("pause");
	return 0;
}



//����������ʱ����������������������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d", a, b);
	system("pause");
	return 0;
}



//���10����������ֵ
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int i = 0;
	int arr[10];
	int Maximum = arr[0];

	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}for (i = 1; i < 10; i++) {
		if (arr[i] > Maximum) {
			Maximum = arr[i];
		}
	}
	printf("10���������ֵΪ��\n");
	printf("%d\n", Maximum);
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int main() {
	int arr[] = { 1, 2, 3, 5, 4, 6, 7, 8, 0, 10 };
	int max = arr[0];
	for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}printf("%d\n", max);
	system("pause");
	return 0;
}

ð������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int a[10] = { 0 };
	for (i = 0; i < 10; i++)
	{
		printf("��%d����:\n", i + 1);
		scanf("%d", &a[i]);
	}
	//ð������ ��С����
	for (i = 0; i < 10; i++)
	{
		for (j = i; j < 10; j++)
		{
			if (a[i] > a[j])
			{
				tmp = a[j];
				a[j] = a[i];
				a[i] = tmp;
			}
		}
	}
	printf("��Сֵ:%d  ���ֵ:%d\n", a[0], a[9]);
	system("pause");
	return 0;
}





//�����������Ӵ�С���
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Max(float a, float b, float c) {
	float d = 0; float e = 0; float f = 0;
	if (a < b)
	{
		d = b;
		b = a;
		a = d;
	}
	if (a < c)
	{
		e = c;
		c = a;
		a = e;
	}
	if (b < c)
	{
		f = c;
		c = b;
		b = f;
		printf("�������ִӴ��С��˳���� %5.2f>%5.2f>%5.2f\n", a, b, c);
	}
}
int main() {
	Max(1, 2, 3);
	system("pause");
	return 0;
}



//�������������Լ��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Max(int a, int b) {
	int num;
	if (a < b) {
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
		while (a%b != 0) {
			num = a % b;
			a = b;
			b = num;
		}
		printf("���Լ��Ϊ��%d\n", num);
	}
	else if (a == b)
		printf("���Լ��Ϊ��%d\n", a);
	else if (a > b) {
		while (a%b != 0) {
			num = a % b;
			a = b;
			b = num;
		}
		printf("���Լ��Ϊ��%d\n", num);
	}
}
int main() {
	int a, b;
	printf("����������ֵ��\n");
	scanf("%d %d", &a, &b);
	Max(a, b);
	system("pause");
	return 0;
}


//������ͬԪ�ظ�����Ԫ�齻��Ԫ��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int i = 0;
	int len = 5;
	int arr1[5], arr2[5];
	printf("����������1��5�����֣�");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr1[i]);
	}
	printf("------------------------------\n");
	printf("����������2��5�����֣�");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr2[i]);
	}
	int tmp = 0;
	//int len1  = sizeof(arr1) / sizeof(arr1[0]);
	//int len2 = sizeof(arr1) / sizeof(arr1[0]);//�������鳤��
	//if (len1 != len2)
	//	printf("�������鲻һ���� �ش�\n");
	//

	for (i = 0; i < len; i++)
	{
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}printf("����������1Ϊ\n");
	for (i = 0; i < len; i++)
	{
		printf("%d", arr1[i]);
	}
	printf("\n");
	printf("����������2Ϊ\n");
	for (i = 0; i < len; i++)
	{
		printf("%d", arr2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}





//����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ��
#include<stdio.h>
#include<stdlib.h>
int main() {
	double a = 0.0, b = 0.0;
	double  sum = a + b;
	for (int i = 1; i <= 100; i++) {
		if (i % 2) {
			a = 1.0 / i;
			sum += a;
		}
		else {
			b = -1.0 / i;
			sum += b;
		}
	}
	printf("%lf\n", sum);
	system("pause");
	return 0;
}






//��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��
#include<stdio.h>
#include<stdlib.h>
int main() {
	int i = 1, count = 0;
	for (i; i < 100; i++) {
		if (i % 10 == 9) {
			count++;
		}
		if (i / 10 == 9) {
			count++;
		}

	}printf("%d\n", count);
	system("pause");
	return 0;
}
//������Σ���������λ����ұ���һλ�������ⲻ��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a = 0;//����
	int b = 0;//�ո���
	int c = 0;//����*��
	for (a = 0; a <= 6; a++) {
		for (b = 0; b <= 6 - a; b++) {
			printf(" ");
		}
		for (c = 1; c <= 2 * a + 1; c++) {
			printf("*");
		}
		printf("\n");
	}
	for (a = 1; a <= 6; a++) {
		for (b = 1; b <= a + 1; b++) {
			printf(" ");
		}for (c = 1; c <= 13 - 2 * a; c++) {
			printf("*");
		}printf("\n");
	}//��Ϊa=0;a<=5;a++��c<11-2a����һЩ�������еط��ظ���
	system("pause");
	return 0;
}
//[����]���������ͷ
//�������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a = 0;//����
	int b = 0;//�ո���
	int c = 0;//����*��
	for (a = 0; a <= 6; a++) {
		for (b = 0; b < 6 - a; b++) {
			printf(" ");
		}
		for (c = 1; c <= 2 * a + 1; c++) {
			printf("*");
		}
		printf("\n");
	}
	for (a = 1; a <= 6; a++) {
		for (b = 1; b <= a; b++) {
			printf(" ");
		}for (c = 1; c <= 13 - 2 * a; c++) {
			printf("*");
		}printf("\n");
	}
	system("pause");
	return 0;
}







//���0~999֮���ˮ�ɻ���
#include<stdio.h>
#include<stdlib.h>
int main() {
	for (int i = 100; i <= 999; i++)
	{
		int a = i / 100, b = i % 100 / 10, c = i % 100 % 10;
		if (a*a*a + c * c*c + b * b*b == i)
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}





//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	double Sn = 0, a = 0, t = 0;
	printf("������һ�����֣�");
	scanf("%d", &a);
	for (int i = 1; i <= 5; i++) {
		t = t * 10 + a;
		Sn += t;
	}
	printf("%d\n", Sn);
	system("pause");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int createnum(int a, int n) {
	if (a > 9 || a <= 0 || n <= 0) {
		return 0;
	}
	int num = 0;
	for (int i = 0; i < n; ++i) {
		num += a * (int)pow(10, i);
	}return num;
}
int main() {
	int sum = 0, a = 1;
	for (int i = 1; i <= 5; ++i) {
		sum += createnum(a, i);
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}
