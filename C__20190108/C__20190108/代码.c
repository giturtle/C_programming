#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


//��д���򽫡�China����������룬������ɣ�
//��ԭ������ĸ������ĸ���ĸ����ԭ������ĸ���ø�ֵ�ķ�����putchar�������5���ַ�
int main() {
	char a,b,c,d,e;
	printf("����������:\n");
	a = getchar();
	b = getchar();
	c = getchar();
	d = getchar();
	e = getchar();
	putchar(a + 4);
	putchar(b + 4);
	putchar(c + 4);
	putchar(d + 4);
	putchar(d + 4);
	printf("\n");
	system("pause");
	return 0;
}


int main() {
	//char c1,c2;
	//int c1, c2;
	c1 = 197;
	c2 = 198;
	printf("c1 = %c,\t c2 = %c\n", c1, c2);
	printf("c1 = %d,\t c2 = %d\n", c1, c2);
	system("pause");
	return 0;
}


//���������д���d��׼��ÿ�»����Ϊp��������Ϊr������������ܹ�����
//��dΪ300000Ԫ��pΪ6000Ԫ��rΪ1%������õ��·�ȡС�����һλ���Եڶ�λ���������봦��
int main() {
	double m, p = 6000, d = 300000, r = 0.01;
	m = log10(p / (p - d * r)) / log10(1 + r);
	printf("%5.1lf����\n", m);
	system("pause");
	return 0;
}


//�����ҹ�����������ֵ����������Ϊ9%������10����ҹ��Ĺ���������ֵ
//��������ȣ������˶��ٰٷֱȡ� p = (1 + r) ^ n
#define increase 0.09
int main() {
	double p;
	p = pow(1 + increase,10);
	printf("������%7.4lf%%", p);
	system("pause");
	return 0;
}


int main() {
	double  a, b, c,delta_sqrt,delta, num,root1, root2;
	printf("y = ax^2 + bx + c\n������a,b,c��ֵ:\n");;
	scanf("%lf %lf %lf", &a, &b, &c);
	delta = b * b - 4 * a * c;
	if (delta < 0) {
		printf("�˷����޸���\n");
	}
	else {
		delta_sqrt = sqrt(delta) / (2.0 * a);
		num = -b / (2.0 * a);
		root1 = num + delta_sqrt;
		root2 = num - delta_sqrt;
		printf("%5.2lf %5.2lf", root1, root2);
	}
	system("pause");
	return 0;
}