#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//�õݹ鷨��һ������ת�����ַ���
//����:����483,Ӧ����ַ���"483". n��λ����ȷ��,���������������
void print(int num) {
	if (num > 9) {
		print(num / 10);
	}
	printf("%c", num % 10 + '0');
}
int main() {
	int num = 0;
	printf("������һ������:\n");
	scanf("%d", &num);
	if (num < 0) {
		printf("-");
		num = -num;
	}
	print(num);
	system("pause");
	return 0;
}


//����һ���ַ�,�ֱ�ͳ�Ƴ����е�Ӣ����ĸ/�ո�/���ֺ������ַ��ĸ���
void count(char* str) {
	int yy = 0, kg = 0, sz = 0, qt = 0;
	while (*str) {
		if ((*str >= 'a' && *str <= 'z')||(*str >= 'A' && *str <= 'Z')) {
			yy++;
		}
		else if (*str == ' ') {
			kg++;
		}
		else if (*str >= '0' && *str <= '9') {
			sz++;
		}
		else {
			qt++;
		}
		str++;
	}
	printf("Ӣ����ĸ:%d\n", yy);
	printf("����:%d\n", sz);
	printf("�ո�:%d\n", kg);
	printf("�����ַ�:%d\n",qt);
}
int main() {
	char str[100];
	printf("������һ���ַ�:\n");
	gets(str);
	count(str);
	system("pause");
	return 0;
}


//[��û����]
//����10��ѧ����5�ſγ̵ĳɼ�,�ֱ��ú�����:
//1. ÿ��ѧ����ƽ����
//2. ÿ�ſγ̵�ƽ����
//3. �ҳ���ߵķ�������Ӧ��ѧ���Ϳγ�
#define N 10
#define M 5

//ѧ��ƽ���ֺ���
double stu_avg(double* a) {
	int i = 0; double stu[], average;
	for (; i < M; i++) {
		stu[i] = *a;
		a++;
	}
	average = sum / M;
	return average;
}

//�γ�ƽ���ֺ���

int main() {
	double a[N][M];
	double stu[N];
	double course[M];
	//����ѧ���ɼ�
	for (int i = 0; i < N; i++) {
		printf("�������%3d��ѧ����%d���ɼ�:\n", i + 1, M);
		for (int j = 0; j < M; j++) {
			scanf("%lf", &a[i][j]);
		}
	}
	//����ѧ��ƽ���ֺ���,����ѧ��ƽ����
	//���ÿγ�ƽ���ֺ���,����γ�ƽ����

	//��������������
	printf("\n��� �γ�1 �γ�2 �γ�3 �γ�4 �γ�5 ƽ����\n");
	for (int i = 0; i < N; i++) {
		printf("No.%d", i + 1);
		for (int j = 0; j < M; j++) {
			printf("%8.2lf", a[i][j]);
		}
		printf("%8.2lf", stu[i]);
	}
	printf("%lf", stu_avg(a));
	system("pause");
	return 0;
}