#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//����ҳ�1~99֮���ȫ��ͬ����
//ͬ����������һ����:��������ƽ�������ұ�
//����:5��25�ұߵ���,25��625�ұߵ���,5��25����ͬ����

//�����ں�
int main() {
	int num, number = 1;
	for (int i = 1; i <= 99; ++i) {
		num = i * i;
		int count = 0;
		while (num) {
			count++;
			num /= 10;
		}
		if (count <= 2) {
			number = 10;
		}
		else {
			number = 100;
		}
		if (i == i*i % number) {
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}

//������
int main() {
	for (int i = 1; i < 100; i++) {
		if (i*i % 10 == i
			|| i * i % 100 == i) {
			printf("%3d", i);
		}
	}
	system("pause");
	return 0;
}

//������
int main() {
	for (int i = 1; i < 100; i++) {
		if (i * i % 10 == i)
			printf("%3d", i);
		else if (i * i % 100 == i)
			printf("%3d", i);
	}
	system("pause");
	return 0;
}


//(����������)
//ÿ��ƻ��0.8Ԫ,��һ����2��ƻ��
//�ڶ��쿪ʼ,ÿ����ǰһ���2��
//ֱ�������ƻ�������ﵽ������100�����ֵ
//��д������ÿ��ƽ��������Ǯ?
int main() {
	int days = 1,count = 2;
	while (count <= 100) {
		count *= 2;
		if (count <= 100) {
			days++;
		}
		else {
			count /= 2;
			break;
		}
	}
	printf("%d %d\n", days, count);
	printf("%5.2lf\n", 0.8 * count / days);
	system("pause");
	return 0;
}
int main() {
	int day = 0, buy = 2;
	double sum = 0, avg;
	do {
		sum += 0.8*buy;
		day++;
		buy *= 2;
	} while (buy <= 100);
	avg = sum / day;
	printf("%lf", avg);
	system("pause");
	return 0;
}



//��д����,�Ӽ�������6��ѧ����5�ųɼ�,�ֱ�ͳ�Ƴ�ÿ��ѧ����ƽ���ɼ�
#define M 6
#define N 5
int main() {
	double grade, sum = 0;
	int count = 0;
	printf("������%d��ѧ����%d�ųɼ�:\n", M, N);
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%lf", &grade);
			sum += grade;
		}
		printf("��%dλѧ����ƽ���ɼ�Ϊ:%5.2lf\n",++count, sum / N);
		sum = 0;
	}
	system("pause");
	return 0;
}