#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//�����һ����������η������3λ��,����x ^ y�������λ��
//Ҫ��x,y�Ӽ�������
int main() {
	int x, y, temp = 1;
	printf("������x��y:\n");
	scanf("%d %d", &x, &y);
	for (int i = 1; i <= y; ++i) {
		temp = temp * x;
	}
	printf("�����λ����:%d\n", temp % 1000);
	system("pause");
	return 0;
}



//����˹̹�Ľ�������
//������һ����,ÿ����2��,�����1��.ÿ����3��,�����2��
//ÿ����5�������4��.ÿ����6��,�����5��;
//ֻ��ÿ����7��ʱ,���õ�����ݶ�,���ʹ��ж��ٽ���?
int main() {
	int jie = 1;
	while (jie) {
		if ((jie % 2 == 1) &&
			(jie % 3 == 2) &&
			(jie % 5 == 4) &&
			(jie % 6 == 5) &&
			(jie % 7 == 0)) {
			printf("%d\n", jie);
			break;	//break�˻��ӡ��С�Ľ��,��ֻҪ��119�ı�������������
		}
		jie++;
	}
	system("pause");
	return 0;
}



//�ټ�����:100ԪǮ��100ֻ��,����1ֻ5ԪǮ,ĸ��1ֻ3ԪǮ,С��1ԪǮ3ֻ.
//��100Ԫ������ٹ���/ĸ��/С������ֻ?
#define shuliang 100
int main() {
	int gongji, muji;
	double xiaoji;
	gongji = 5;
	muji = 3;
	xiaoji = 1.0 / 3;
	for (int i = 0; i <= 20; ++i) {
		for (int j = 0; j <= 100 / 3.0; ++j) {
			for (int k = 0; k <= 300; ++k) {
				if (k % 3 != 0)
					continue;
				if ((i*gongji + j * muji + k/3.0 == 100)
				&& (i + j + k == shuliang)){
					printf("%d %d %d\n", i,j,k);
				}
			}
		}
	}
	system("pause");
	return 0;
}

//��һ�ֽ���
int main() {
	int cocks, hens, chicks;
	cocks = 0;
	while (cocks <= 20) {
		hens = 0;
		while (hens <= 33) {
			chicks = 100.0 - cocks - hens;
			if (5.0*cocks + 3.0*hens + chicks / 3.0 == 100.0) {
				printf("%d %d %d\n", cocks, hens, chicks);
			}
			hens++;
		}
		cocks++;
	}
	system("pause");
	return 0;
}



//��ӡ����
#define N 6
int main() {
	int i, j;
	for (i = 1; i <= N; ++i) {
		//�ȴ�ӡ�ո�
		for (j = 1; j <= N - i; ++j) {
			printf(" ");
		}
		//�ٴ�ӡ�Ǻ� *
		for (j = 1; j <= (2 * i) - 1; ++j) {
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i <= N - 1; ++i) {
		for (j = 1; j <= i; ++j) {
			printf(" ");
		}
		for (j = 1; j <= (2 * N - 1) - 2 * i; ++j) {
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}



//�ö��ַ���2x^3 - 4x^2 + 3x - 6 = 0��(-10,10)֮��ĸ�
int main() {
	double x0, x1, x2, fx0, fx1, fx2;
	do {
		printf("������ x1 �� x2 ��ֵ:\n");
		scanf("%lf %lf", &x1, &x2);
		fx1 = 2 * pow(x1, 3) - 4 * pow(x1, 2) + 3 * x1 - 6;
		fx2 = 2 * pow(x2, 3) - 4 * pow(x2, 2) + 3 * x2 - 6;
	} while (fx1 * fx2 > 0);
	//��֤��ָ����Χ���и�,����ʹ���˵㴦�ĺ���ֵ�෴
	do {
		x0 = (x1 + x2) / 2;	//ȡ�е�x0
		fx0 = 2 * pow(x0, 3) - 4 * pow(x0, 2) + 3 * x0 - 6;
		//��� x0 �ĺ���ֵ
		if (fx0 * fx1 < 0) {	//��fx0��fx1�����෴
			x2 = x0;
			fx2 = fx0;
		}
		else {	//��fx0��fx2�����෴
			x1 = x0;
			fx1 = fx0;
		}
	} while (fabs(fx0) >= 1e-5);
	//�ж� x0 ������ֵ�Ƿ��㹻�ƽ�0ֵ
	printf("x = %6.2lf\n", x0);
	system("pause");
	return 0;
}



//���ӳ�������,���ӵ�һ��ժ�����ɸ���,��������һ��,�������,�ֶ����һ��
//�ڶ��������ֽ�ʣ�µ����ӳԵ���һ��,�ֶ����һ��
//�Ժ�ÿ�����϶�����ǰһ��ʣ�µ�һ����һ��
//����10���������ٳ�,��ֻʣһ��������.
//���һ�칲ժ�˶��ٸ�����
int main() {
	int taozi = 1;
	for (int i = 10; i > 1; --i) {
		taozi = 2 * (taozi + 1);
	}
	printf("��һ��ժ��%d������.\n", taozi);
	system("pause");
	return 0;
}


//�޸�����:  ��1��20�Ľ׳�֮��
int main() {
	int i, j;
	double sum = 0, temp = 1;
	for (i = 1; i <= 20; ++i) {
		for (j = 1; j <= i; ++j) {
			temp = temp * j;
		}
		sum += temp;
		temp = 1;
	}
	printf("1~20�Ľ׳�֮��Ϊ:%lf\n", sum);
	system("pause");
	return 0;
}



//�޸�����������������
int main() {
	double meters = 100, height = meters / 2.0;
	//meters�����һ���ŵ�,û��ʼ����
	//height���㷴���ĸ߶�
	for (int i = 2; i <= 10; ++i) {
		meters = meters + 2 * height;
		//�����ŵ�֮��ľ���Ϊ2*height;
		height /= 2.0;
		//forѭ���������䲻�ɵ���λ��!!
	}
	printf("10�κ󷴵��߶�Ϊ:%lf\n", height);
	printf("10�����ʱ,������%lf��\n", meters);
	system("pause");
	return 0;
}
