#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//��n����Χ��һȦ��˳���źš��ӵ�һ���˿�ʼ������1-3�����Ǳ���3�����Ƴ�Ȧ�ӣ���������µ���ԭ���ڼ��ŵ���λ
int main{
	int i, k, m, n, num[50], *p;
	printf("input number of person: n=");
	scanf("%d", &n);
	p = num;
	for (i = 0; i < n; i++)
		*(p + i) = i + 1;
	i = 0;
	k = 0;
	m = 0;
	while (m < n - 1)//m��ָ���ֵ���������Ϊ��n���ˣ����ʣ��һ���ˣ����������֣�n-1�����ˣ�����ѭ��
	{
		if (*(p + i) != 0)//�ж�����ţ�ԭ������ţ��Ƿ����
			k++;//�����û�г��֣��ͱ�������������1
		if (k == 3)//��3�ĳ���
		{
			*(p + i) = 0;//�����ֵ�����˱��
			k = 0;//ʹ���������㣬�Ա������˱���
			m++;//����������������1
		}
		i++;//��ָ����ƣ���Ȼi����ָ�룬��p+i����ָ���ˣ�����i����Ϊָ������
		if (i == n)//���ָ���Ƶ���β�����򷵻ص�ͷ��
			i = 0;
	}
	//���ϵ�ѭ������Ҫ���㣬����ľ����ҳ�����Ǹ��ˣ���������
	while (*p == 0)//���������ֻ�ж����Һŵ�ǰ��ĺţ��������Һţ��������жϺ���ġ�
	p++;
	printf("The last one is N0.%d\n", *p);
	system("pause");
	return 0;
}

//#define N 50
//int main() {
//	int n[N];
//	printf("���� n �Ĵ�С:\n");
//	scanf("%d", &n);
//	for(int i)
//	int *p = &n[2];
//	system("pause");
//	return 0;
//}


//����10����������������С�������һ�����Ի����������������һ�����Ի���
//д��������������10���������д������10����
int *input(int *arr) {
	printf("������10������:\n");
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &arr[i]);
	}
	return arr;
}

void print(int *arr) {
	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}
}

void reverse(int *arr) {
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < 10; ++i) {
		if (arr[i] > max) {
			max = i;
		}
		if (arr[i] < min) {
			min = i;
		}
	}
	int temp;
	temp = arr[0];
	arr[0] = arr[min];
	arr[min] = temp;

	temp = arr[9];
	arr[9] = arr[max];
	arr[max] = temp;
}

int main() {
	int arr[10];
	input(arr);
	reverse(arr);
	print(arr);
	print("\n");
	system("pause");
	return 0;
}


//���������ַ�������С�������
int main() {
	char a[100], b[100], c[100];
	char *a_ptr = a;
	char *b_ptr = b;
	char *c_ptr = c;
	printf("�������ַ���1:\n");
	gets(a);
	printf("�������ַ���2:\n");
	gets(b);
	printf("�������ַ���3:\n");
	gets(c);
	printf("��С������ַ���˳��\n");
	if (*a_ptr > *b_ptr) {
		if (*a_ptr > *c_ptr) {
			if (*b_ptr > *c_ptr) {
				puts(c); puts(b); puts(a);
			}
			else {
				puts(b); puts(c); puts(a);
			}
		}
		else {
			puts(b); puts(a); puts(c);
		}
	}
	else {
		if (*b_ptr > *c_ptr) {
			if (*a_ptr > *c_ptr) {
				puts(c); puts(a); puts(b);
			}
			else {
				puts(a); puts(c); puts(b);
			}
		}
		else {
			puts(a); puts(b); puts(c);
		}
	}
	system("pause");
	return 0;
}