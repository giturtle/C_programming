#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����һ����ά����,�ú������ĳ�������ֵ,Ҳ����ĳ������Сֵ
//ÿ�����ֵ����һ��������,Ȼ�������������������ֵ
#define M 5
#define N 5
int maxi(int c[], int d, int e) {
	int j, max;
	max = c[d][0];
	for (j = 0; j < e; j++) {
		if (c[d][j] > max) {
			max = c[d][j];
		}
	}
	return max;
}
int maxj(int c[], int e) {
	int i, max;
	max = c[0];
	for (i = 0; i < e; ++i) {
		if (c[i] > max) {
			max = c[i];
		}
	}
	return max;
}
int main() {
	int a[M][N],b[N];
	int m, n, i, j;
	printf("����������:\n");
	scanf("%d", &m);
	printf("����������:\n");
	scanf("%d", &n);
	printf("����������:\n");
	for (i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; ++i) {
		b[i] = maxi(a, i, m);
	}
	printf("%d")
	system("pause");
	return 0;
}



//��һ��������ʵ��ʹ�����������һ���ַ�����������
//���������н������������ַ���

//-------���� 1 ---------
void reverse(char* str) {
	char temp;
	char* start = str;
	char* end = str + strlen(str) - 1;
	while (start < end) {
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
int main() {
	char str[100];
	printf("�����ַ���:\n");
	scanf("%s", &str);
	reverse(str);
	printf("����֮����ַ���Ϊ:%s\n", str);
	system("pause");
	return 0;
}

//------- ���� 2 --------
void reverse_2(char str[]) {
	unsigned i, j;
	char temp;
	for (i = 0, j = strlen(str); i < strlen(str) / 2; i++, j--) {
		temp = str[i];
		str[i] = str[j - 1];
		str[j - 1] = temp;
	}
}
int main() {
	char str[100];
	printf("�����ַ���:\n");
	scanf("%s", &str);
	reverse_2(str);
	printf("����֮����ַ���Ϊ:%s\n", str);
	system("pause");
	return 0;
}


//(�β���ʵ�� ��Ҫ�������!)   (δ���)
//�������ַ�����������,��Ҫ��strcat����
int main() {
	void my_strcat(char a[], char b[]);
	char a1[100], a2[100];
	printf("�������һ���ַ���:\n");
	scanf("%s", &a1);
	printf("������ڶ����ַ���:\n");
	scanf("%s", &a2);
	my_strcat(a1, a2);
	printf("%s", a1);
	system("pause");
	return 0;
}
void my_strcat(char a[],char b[]) {
	int i = 0, j = 0;
	while (a[i] != '\0')	i++;
	while (b[j] != '\0')	a[i++] =b[j++];
	a[j] = '\0';
}



//����������Ƶķ�������10��ѧ��1�ſγɼ���ƽ����
double avg(double grade[]) {
	int i; double average, sum = grade[0];
	for (i = 1; i < 10; i++) {
		sum += grade[i];
	}
	average = sum / 10;
	return average;
}
int main() {
	double score[10], average;
	int i;
	printf("������10��ѧ���ĳɼ�:\n");
	for (i = 0; i < 10; i++) {
		scanf("%lf", &score[i]);
	}
	average = avg(score);
	printf("\nƽ���ɼ�Ϊ:%5.2lf\n", average);
	system("pause");
	return 0;
}