#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//��������m��n�����Լ��
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	int max = m > n ? n : m;
	for (int i = 1; i <= n; i++) {
		if (m % i == 0 && n % i == 0) {
			max = i;
		}
	}
	printf("%d\n", max);
	system("pause");
	return 0;
}


//��100~200֮���������
�����ⷨ
int Isprime(int num) {
	for (int i = 2; i <= (int)sqrt(num); i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	for (int i = 100; i <= 200; i++) {
		if (Isprime(i))
		{
			printf("%5d", i);
		}
	}
	system("pause");
	return 0;
}
�Ǻ����ⷨ
int main() {
	for (int i = 100; i <= 200; i++) {
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				break;
			}
			else if (j > sqrt(i)-1) {
				printf("%5d", i);
			}
		}
	}
	system("pause");
	return 0;
}


//�ж�һ�����ܷ�ͬʱ��3 ��5����
int main() {
	int num;
	scanf("%d", &num);
	if (num % 3 == 0 && num % 5 == 0) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}
	system("pause");
	return 0;
}


//���������֣�Ҫ�󰴴�С˳���������
int main() {
	double a, b, c, temp;
	printf("������������a,b,c��\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a < c) {
		temp = a;
		a = c;
		c = temp;
	}
	else if (b < c) {
		temp = b;
		b = c;
		c = temp;
	}
	printf("��С˳��%5.2lf %5.2lf %5.2lf\n", a, b, c);
	system("pause");
	return 0;
}


���ν�10�������룬Ҫ���������������
#define M 10
int main() {
	int num, input, j = 1;
	for (int i = 0; i < M; i++) {
		printf("�������%d������\n", i + 1);
		scanf("%d", &input);
		while (j) {
			num = input;
			j--;
		}
		num = input > num ? input : num;
	}
	printf("�����Ϊ��%d\n", num);
	system("pause");
	return 0;
}
int main() {
	int arr[10];
	printf("����10������\n");
	for (int i = 0; i < M; i++) {
		scanf("%d", &arr[i]);
	}
	int max = arr[0];
	for (int i = 1; i < 10; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	printf("%d\n", max);
	system("pause");
	return 0;
}



//������ƿ��A��B���ֱ�ʢ�Ŵ׺ͽ��ͣ�Ҫ�����ǻ���
int main() {
	int A = 1, B = 2;

	//��
	int temp;
	temp = A;
	A = B;
	B = temp;

	//��
	B = A + B;
	A = B - A;
	B = B - A;

	//��
	A = A ^ B;
	B = A ^ B;
	A = A ^ B;

	printf("%d %d", A, B);
	system("pause");
	return 0;
}
