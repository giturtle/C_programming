#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//ͨ�����������ַ�,�ж���Ϊ����/����/��д��ĸ/Сд��ĸ/������ĸ��һ��
int main() {
	char ch;
	printf("�������ַ�:\n");
	scanf("%c", &ch);
	if (ch < 32)	//^z
		printf("\n�ַ�Ϊ: �����ַ�\n");
	else if ((ch >= 'A') && (ch <= 'Z')) {
		printf("\n�ַ�Ϊ: ��д��ĸ\n");
	}
	else if ((ch >= 'a') && (ch <= 'z')) {
		printf("\n�ַ�Ϊ: Сд��ĸ\n");
	}
	else if ((ch >= '0') && (ch <= '9')) {
		printf("\n�ַ�Ϊ: ����\n");
	}
	else
		printf("\n�ַ�Ϊ: �����ַ�\n");
	system("pause");
	return 0;
}



//��д�򵥼���������
//�����û�����������������������,��ʾ��ƽ��
//�����������( +,-,*,/ )
int main() {
	int a, b;
	char ysf;
	printf("�����������������Ͳ�����:\n");
	scanf("%d %d %c", &a, &b, &ysf);
	switch (ysf) {
	case '+':printf("\n%d + %d = %d\n", a, b, a + b); break;
	case '-':printf("\n%d - %d = %d\n", a, b, a - b); break;
	case '*':printf("\n%d * %d = %d\n", a, b, a * b); break;
	case '/':printf("\n%d / %d = %d\n", a, b, a / b); break;
	}
	system("pause");
	return 0;
}



//���Ʋ˵�����,����Ļ����ʾʱ���,�����û���ѡ��,��ʾ��ͬ���ʺ���Ϣ.
int main() {
	int ch;
	printf("*******ʱ���*******\n");
	printf("\t1.morning\n");
	printf("\t2.afternoon\n");
	printf("\t3.night\n\n");
	printf("���ѡ����:\n");
	scanf("%d", &ch);
	switch (ch) {
	case 1:
		printf("Good morning!\n");
		break;
	case 2:
		printf("Good afternoon!\n");
		break;
	case 3:
		printf("Good night!\n");
		break;
	}
	system("pause");
	return 0;
}


//������ݺ��·�,������ж�����.
int main() {
	int year, month, day;
	printf("��������ݺ��·�:\n");
	scanf("%d %d", &year, &month);
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		day = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day = 30;
		break;
	case 2:
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
			day = 29;
		}
		else {
			day = 28;
		}
		break;
	default:
		printf("�������,����������!\n");
		day = 0;
	}
	printf("\n%d��%d�� �� %d ��.\n", year, month, day);
	system("pause");
	return 0;
}



//��֪����������ȡ��ͬ���޵���Ϣ����
//������ı��������,����ʱ�ܴ����еõ��ı�Ϣ��
//��Ϣ = ���� �� ��Ϣ���� �� 12 �� �������
int main() {
	unsigned money, year;
	double lixi;
	printf("�����������������:\n");
	scanf("%u %u", &money, &year);
	switch (year) {
	case 1: lixi = money * 0.0063 * 12 * 1;
	case 2: lixi = money * 0.0066 * 12 * 1;
	case 3: 
	case 4:	lixi = money * 0.0069 * 12 * 1;
	case 5:	
	case 6: 
	case 7: lixi = money * 0.0075 * 12 * 1;
	case 8: lixi = money * 0.0084 * 12 * 1;
	}
	printf("��Ϣ��Ϊ:%8.2lfԪ\n", money + lixi);
	system("pause");
	return 0;
}



//���,Ҫ������������a,b,��a^2 + b^2����100,�����a^2 + b^2��λ��������
//�������������֮��
int main() {
	unsigned a = 0, b = 0;
	printf("����������������:\n");
	scanf("%u %u", &a, &b);
	if (pow(a,2) + pow(b,2) > 100) {
		int num = (a*a + b * b) / 100;
		printf("%d\n", num);
	}
	else {
		printf("%d\n", a + b);
	}
	system("pause");
	return 0;
}



//����ж�������������Ƿ����5����7��������
//����,�����yes
//����,���no
int main() {
	unsigned i;
	printf("������������:\n");
	while (1) {
		scanf("%u", &i);
		if (i <= 0) {
			printf("�������,����������!\n");
			continue;
		}
		else
			break;
	}
	if ((i % 5 == 0) && (i % 7 == 0)) {
		printf("\nyes!\n");
	}
	else {
		printf("\nno\n");
	}
	system("pause");
	return 0;
}



//��һ��������5λ��������,Ҫ��:
//1.������Ǽ�λ��
//2.�ֱ��ӡ��ÿһλ����
//3.�������ӡ����λ����,��ԭ��321,Ӧ���123
void print(int num) {
	if (num > 9) {
		print(num / 10);
	}
	printf("%d\n", num % 10);
}
int main() {
	unsigned num,num_copy;
	int count = 0;
	printf("������һ��������5λ��������:\n");
	scanf("%u", &num);
	num_copy = num;
	//1.������Ǽ�λ��
	while (num_copy) {
		count++;
		num_copy /= 10;
	}
	printf("��������� %d λ��.\n\n",count);

	//2.�ֱ��ӡ��ÿһλ����
	printf("����ÿһλΪ:\n");
	print(num);
	printf("\n");

	//3.�������ӡ����λ����,��ԭ��321,Ӧ���123
	printf("����֮��Ϊ:\n");
	for (int i = 1; i <= count; ++i) {
		printf("%d", num % 10);
		num /= 10;
	}
	system("pause");
	return 0;
}



//����һ�ٷ��Ƴɼ�,Ҫ������ɼ��ȼ�'A','B','C','D','E'.
//90�ּ�����Ϊ'A',80-89Ϊ'B',70-79Ϊ'C',60-69Ϊ'D',60������Ϊ'E'
int main() {
	double score;
	printf("������һ�ٷ��Ƴɼ�:\n");
	scanf("%lf", &score);
	if (score >= 90) {
		printf("A");
	}
	else if (score >= 80) {
		printf("B");
	}
	else if (score >= 70) {
		printf("C");
	}
	else if (score >= 60) {
		printf("D");
	}
	else {
		printf("E");
	}
	system("pause");
	return 0;
}



//��һ�ֶκ���y,дһ������,����x,���yֵ
int main() {
	double x , y;
	printf("������ x ֵ:\n");
	scanf("%lf", &x);
	if (x < 1) {
		y = x;
	}
	else if (x < 10) {
		y = 2 * x - 1;
	}
	else {
		y = 3 * x - 11;
	}
	printf("y = %4.2f\n", y);
	system("pause");
	return 0;
}



//��3������a b c,�ɼ�������,�������������
//--------����1----------
int main() {
	int a, b, c, temp;
	printf("��������������:\n");
	scanf("%d %d %d", &a, &b, &c);
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	else if (a < c) {
		temp = a;
		a = c;
		c = temp;
	}
	printf("�����Ϊ:%d\n",a);
	system("pause");
	return 0;
}

//---------����2--------
int main() {
	int a, b, c, temp1,temp2;
	printf("��������������:\n");
	scanf("%d %d %d", &a, &b, &c);
	temp1 = (a > b) ? a : b;
	temp2 = (a > c) ? a : c;
	printf("\n�����Ϊ:%d\n", (temp1 > temp2) ? temp1:temp2);
	system("pause");
	return 0;
}

//-------������(���)-----
int main() {
	int a, b, c, temp, max;
	printf("��������������:\n");
	scanf("%d %d %d", &a, &b, &c);
	temp = (a > b) ? a : b;
	max = (temp > c) ? temp : c;
	printf("�����Ϊ:%d\n", max);
	system("pause");
	return 0;
}