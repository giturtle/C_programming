#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//��һ�������е�ֵ����������´��
//����ԭ��˳����8,6,5,4,1
//Ҫ���Ϊ 1,4,5,6,8
#define N 5
int main() {
	int a[5], i, temp;
	printf("����������:\n");
	for (i = 0; i < N; ++i) {
		scanf("%d", &a[i]);
	}
	printf("����Ϊ:\n");
	for (i = 0; i < N; ++i) {
		printf("%5d", a[i]);
	}
	for (i = 0; i < N / 2; ++i) {
		temp = a[i];
		a[i] = a[N - i - 1];
		a[N - i - 1] = temp;
	}
	printf("\n���������Ϊ:\n");
	for (i = 0; i < N; ++i) {
		printf("%5d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}



//����һ�����ź��������,������һ������
//Ҫ��ԭ������Ĺ��ɽ�������������
int main() {
	int i, j,num;
	int a[11] = { 1,4,6,9,13,16,19,28,40,100 };
	//������ΪҪ����Ԫ��,������ǰ�趨��һλ������,Խ�籣��
	printf("����Ϊ:\n");
	for (i = 0; i < 10; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("��������Ҫ���������:\n");
	scanf("%d", &num);

	i = 0;
	while (a[i] < num && i < 10) {
		i++;
	}
	for (j = 9; j >= i; j--) {
		a[j + 1] = a[j];
	}
	a[i] = num;
	printf("��������Ϊ:\n");
	for (i = 0; i < 11; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}



//��һ��3 �� 3����Խ��ߵ�Ԫ��֮��
int main() {
	int i, j, a[3][3], sum = 0;
	printf("������һ��3 �� 3����:\n");
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			if (i == j) {
				sum += a[i][j];
			}
		}
	}
	printf("�Խ���Ԫ��֮��Ϊ:%d\n", sum);
	system("pause");
	return 0;
}



//��ѡ�񷨶�10����������
int main() {
	int i, j, temp, min, a[11];
	printf("     ������10����:     \n\n");
	for (i = 1; i <= 10; ++i) {
		printf("�������%d����:\n", i);
		scanf("%d", &a[i]);
	}
	printf("\n");
	printf("��������:\n");
	for (i = 1; i <= 10; ++i) {
		printf("%5d", a[i]);
	}
	printf("\n");
	//����������
	for (i = 1; i <= 10; ++i) {
		min = i;
		for (j = i + 1; j <= 10; ++j) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	printf("�������Ч��:\n");
	for (i = 1; i <= 10; ++i) {
		printf("%5d", a[i]);
	}

	system("pause");
	return 0;
}




//��ɸѡ����100���ڵ�����
int main() {
	int i, j, count;
	int a[100];
	for (i = 1; i <= 100; ++i) {
		a[i] = i;
	}
	for (i = 2; i < sqrt(100); ++i) {
		//���j�ܱ�i���� �������� a[j]��Ϊ 0;
		for (j = i + 1; j <= 100; ++j) {
			if (a[i] != 0 && a[j] != 0) {
				if (a[j] % a[i] == 0) {
					a[j] = 0;
				}
			}
		}
	}
	printf("\n");
	for (i = 2, count = 0; i < 100; ++i) {
		if (a[i] != 0) {
			printf("%5d ", a[i]);
			count++;
		}
		if (count == 10) {
			printf("\n");
			count = 0;
		}
	}
	system("pause");
	return 0;
}