#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//һ���100m�߶���������,ÿ����غ�����ԭ���߶ȵ�һ��,������
//������10�����ʱ,�������˶�����?��10�η������?
int main() {
	double height = 100,meters = 0;
	for (int i = 1; i <= 10; ++i) {
		height /= 2.0;
		meters = 100 + meters + 2 * height;
	}
	printf("10�κ󷴵��߶�Ϊ:%d\n", height);
	printf("10�����ʱ,������%d��\n", meters);
	system("pause");
	return 0;
}



//һ��������:2/1 + 3/2 + 5/3 + ... ���������е�ǰ20��֮��
int main() {
	int a = 2, b = 1,temp;
	double num , sum = 0;
	for (int i = 1; i <= 20; ++i) {
		num = (double)a / b;
		sum += num;
		temp = a;//��ʱ����
		a = a + b;
		b = temp;
	}
	printf("��ͽ��Ϊ:%lf\n", sum);
	system("pause");
	return 0;
}



//��100~499֮���ˮ�ɻ���,����λ���ֵ��������ڱ�����
int main() {
	for (int i = 100; i <= 499; ++i) {
		if (pow(i % 10, 3) + pow((i / 10) % 10, 3) + pow((i / 100) % 10, 3) == i) {
			printf("%d\n", i);
		}

	}
	system("pause");
	return 0;
}



//��1~100��k֮�ͼ���1~50��k^2֮�ͼ���1~10��1/k֮��
int main() {
	double sum = 0;
	int i;
	for (i = 1; i <= 100; ++i) {
		sum += i;
	}
	for (i = 1; i <= 50; ++i) {
		sum += i * i;
	}
	for (i = 1; i <= 10; ++i) {
		sum += 1.0 / i;
	}
	printf("��͵Ľ��Ϊ:%6.2lf\n", sum);

	system("pause");
	return 0;
}



//��1��20�Ľ׳�֮��    (δ��ɴ��޸�)
int main() {
	int i,j,sum = 0,temp = 1;
	for (i = 1; i <= 20; ++i) {
		for (j = 1; j <= i; ++j) {
			temp = temp * j;
		}
		sum += temp;
		//������int��������,�ᷢ�����
		//�������ȷ
		temp = 1;
	}
	printf("1~20�Ľ׳�֮��Ϊ:%d\n", sum);
	system("pause");
	return 0;
}



//��Sn = a + aa + aaa + aaaa +...
//����a������,���� 2 + 22 + 222 + 2222 + 22222,��ʱn = 5,n�ɼ������� 
int main() {
	int a, n, num = 0, sum = 0;
	printf("������ a �� n ��ֵ:\n");
	scanf("%d %d", &a, &n);
	for (int i = 1; i <= n; ++i) {
		num = 10 * num + a;
		sum += num;
	}
	printf("a + aa + aaa + ... = %d", sum);
	system("pause");
	return 0;
}



//��������������m��n,�������Լ������С������
int main() {
	unsigned m, n, min_gb, max_gy;
	while (1) {
		printf("����������������m��n:\n");
		scanf("%u %u", &m, &n);
		if (m <= 0) {
			printf("�������!\n");
			continue;
		}
		if (n <= 0) {
			printf("�������!\n");
			continue;
		}
		break;
	}
	max_gy = (m > n) ? n : m;
	while (max_gy) {
		if ((m % max_gy == 0) && (n % max_gy == 0)) {
			printf("���Լ��Ϊ:%d\n", max_gy);
			break;
		}
		max_gy--;
	}
	min_gb = (m > n) ? m : n;
	while (min_gb) {
		if ((min_gb % m == 0) && (min_gb % n == 0)) {
			printf("��С������Ϊ:%d\n",min_gb);
			break;
		}
		min_gb++;
	}
	system("pause");
	return 0;
}