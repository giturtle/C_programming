#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>


int main() {
	char i, j, k;
	//i��A�Ķ��֣�j��B�Ķ��֣�k��C�Ķ���
	for (i = 'X'; i <= 'Z'; i++)
	{
		for (j = 'X'; j <= 'Z'; j++)
		{
			for (k = 'X'; k <= 'Z'; k++)
			{
				if (i != k && j != k && i != j)
				{
					if (i != 'X' && k != 'X' && k != 'Z')
					{
						printf("A����%c\nB����%c\nC����%c\n", i, j, k);
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}


//���
#define n 5
int main() {
	int a, Sn = 0,t = 0;
	printf("������a��ֵ:\n");
	scanf("%d",&a);
	for (int i = 0; i < n; i++) {
		t = t * 10+a;
		Sn += t;
	}
	printf("%d\n", Sn);
	system("pause");
	return 0;
}

//��������m��n���Լ������С������
int main() {
	int m, n;
	int gongyue, gongbei, max,min;
	printf("��������������m��n:\n");
	scanf("%d %d", &m, &n);
	int ll = 1, key = 1;
	for (int i = 1; i <= (n < m ? n : m); i++) {
		if (m % i == 0 && n % i == 0) {
			gongyue = i;
			if (ll) {
				max = gongyue;
				ll--;
			}
			if (max < gongyue) {
				max = gongyue;
			}
		}
	}
	gongbei= m > n ? m : n;
	while (1) {
		if (gongbei % m == 0 && gongbei % n == 0) {
			min = gongbei;
			break;
		}
		gongbei++;
	}
	printf("���Լ��Ϊ:%d\n", max);
	printf("��С������Ϊ:%d\n", min);
	system("pause");
	return 0;
}


int main() {
	char arr[20] = { 0 };
	system("shutdown -s -t 6000");
	while (1) {
		printf("���Լ����ػ���������롰i am pig����ȡ���ػ��������룺\n");
		gets(arr);
		if (!strcmp(arr,"i am pig")) {
			system("shutdown -a");
			printf("�õ�\n");
			break;
		}
	}
	system("pause");
	return 0;
}



//������
int main() {
	char c;
	c = getchar();
	while (c != '\n') {
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
			if ((c >= 'W' && c <= 'Z') || (c >= 'w' && c <= 'z')) {
				c = c - 'A' - 'a';
			}
			else {
				c = c + 4;
			}
		}
		putchar(c);
		c = getchar();//�ڶ��ַ������
	}
	printf("\n");
	system("pause");
	return 0;
}


//�ж����� 100 ~ 200
int main() {
	int i, j, m = 0;
	for (i = 101; i <= 200; i += 2) {
		for (j = 2; j <= (int)sqrt(i); j++){
			if (i % j == 0) {
				break;
			}
		}
		if (j >= (int)sqrt(i) + 1) {
			//ȫ���� >= ��������� == ���Ѿ���������
			printf("%4d", i);
			m++;
		}
		if (m == 10) {
			printf("\n");
			m = 0;
		}
	}
	system("pause");
	return 0;
}