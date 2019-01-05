#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//求两个数m和n的最大公约数
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


//将100~200之间素数输出
函数解法
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
非函数解法
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


//判断一个数能否同时被3 和5整除
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


//有三个数字，要求按大小顺序讲它们输出
int main() {
	double a, b, c, temp;
	printf("请输入三个数a,b,c：\n");
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
	printf("大小顺序：%5.2lf %5.2lf %5.2lf\n", a, b, c);
	system("pause");
	return 0;
}


依次将10个数输入，要求输出其中最大的数
#define M 10
int main() {
	int num, input, j = 1;
	for (int i = 0; i < M; i++) {
		printf("请输入第%d个数：\n", i + 1);
		scanf("%d", &input);
		while (j) {
			num = input;
			j--;
		}
		num = input > num ? input : num;
	}
	printf("最大数为：%d\n", num);
	system("pause");
	return 0;
}
int main() {
	int arr[10];
	printf("输入10个数：\n");
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



//有两个瓶子A和B，分别盛放醋和酱油，要求将他们互换
int main() {
	int A = 1, B = 2;

	//①
	int temp;
	temp = A;
	A = B;
	B = temp;

	//②
	B = A + B;
	A = B - A;
	B = B - A;

	//③
	A = A ^ B;
	B = A ^ B;
	A = A ^ B;

	printf("%d %d", A, B);
	system("pause");
	return 0;
}
