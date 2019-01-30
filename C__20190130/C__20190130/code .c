#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//����3��ѧ��2�ųɼ����ֱ��ú���ʵ�����й��ܣ�
//1. ����ÿ��ѧ����ƽ����
//2. ����ÿ�ſε�ƽ����
//3. �ҳ�����6����������ߵķ�������Ӧ��ѧ���Ϳγ�
#define STUDENT 3
#define COURSE 2
void avg_student(double (*stu)[2]) {
	double sum = 0; 
	for(int i = 0;i < STUDENT;i++){
		sum = stu[i][0] + stu[i][1];
		printf("��%d��ѧ����ƽ���ɼ�Ϊ��%5.2lf\n", i + 1, sum / COURSE);
	}
}

void avg_course(double(*stu)[2]) {
	double sum = 0;
	for (int j = 0; j < COURSE; j++) {
		sum = stu[0][j] + stu[1][j] + stu[2][j];
		printf("��%d�ſγ̵�ƽ���ɼ�Ϊ��%5.2lf\n", j + 1, sum / STUDENT);
	}
}

void Found(double stu[][2]) {
	int i, j;
	int x, y;
	double max = stu[0][0];
	for (i = 0; i < STUDENT; i++) {
		for (j = 0; j < COURSE; j++) {
			if (stu[i][j] > max) {
				double temp = stu[i][j];
				stu[i][j] = max;
				max = temp;
				x = i;
				y = j;
			}
		}
	}
	printf("��߷ֵĳɼ��ǵ�%dλѧ���ĵ�%d�ſγ̣���߷�Ϊ%5.2lf\n", x + 1, y + 1, max);
}

int main() {
	double stu[3][2];
	int i, j;
	for (i = 0; i < STUDENT; i++) {
		for (j = 0; j < COURSE; j++) {
			printf("�������%d��ѧ���ĵ�%d�ųɼ���\n", i + 1, j + 1);
			scanf("%lf", &stu[i][j]);
		}
	}
	avg_student(stu);	//����ÿ��ѧ����ƽ����
	printf("\n");
	avg_course(stu);	//����ÿ�ſε�ƽ����
	printf("\n");
	Found(stu);			//�ҳ�����6����������ߵķ�������Ӧ��ѧ���Ϳγ�
	system("pause");
	return 0;
}




//�õݹ鷽����n�����õ¶���ʽ��ֵ
//P(x) = 1  (n = 0),x (n = 1),(2n - 1)*x - P<n-1>(x) - (n - 1)*P<n-2>(x)/n  (n >= 1)
double Lrd(int n, double val) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return val;
	}
	else if (n > 1) {
		return ((2 * n - 1)*val - Lrd(n - 1, val) - (n - 1)*Lrd(n - 2, val)) / n;
	}
	return -1;		//�쳣����
}

int main() {
	double val;
	int n;
	printf("������x��ֵ��\n");
	scanf("%lf", &val);
	printf("���������n��ֵ��\n");
	scanf("%d", &n);
	printf("%5.2lf\n",Lrd(n, val));
	system("pause");
	return 0;
}



//��ţ�ٵ��������������Ϊax^3 + bx^2 + cx + d = 0��ϵ��a��b��c��d��ֵ����Ϊ1��2��3��4
//�����������룬�� x �� 1 ������һ��ʵ����������������������

double Newton(double a, double b, double c, double d)
{
	double x1 = 1, x, f, f1;
	//����
	do{
		x = x1;
		f = ((a*x + b)*x + c)*x + d;//ԭ����
		f1 = (3 * a*x + 2 * b)*x + c;//��֮��ĺ���
		x1 = x - f / f1;
	} while (fabs(x1 - x) >= 0.00000001);
	return x1;
}

int main()
{
	double a, b, c, d;
	printf("���뷽��ϵ��:\n");
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	printf("���̽��Ƹ�root = %5.3lf\n", Newton(a, b, c, d));
	system("pause");
	return 0;
}



//дһ�������������ݷ��������10���ַ�����С�����˳������
void Swap(char *p, char *q) {
	char temp = *p;
	*p = *q;
	*q = temp;
}
void Sort(char *str) {
	for (int bound = 0; bound < 10; bound++) {
		for (int cur = 9; cur > bound; cur--) {
			if (str[cur - 1] > str[cur]) {
				Swap(&str[cur - 1], &str[cur]);
			}
		}
	}
}
int main() {
	char arr[20];
	printf("����һ������10���ַ����ַ���:\n");
	gets(arr);
	Sort(arr);
	for (int i = 0; arr[i] != '\0'; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}