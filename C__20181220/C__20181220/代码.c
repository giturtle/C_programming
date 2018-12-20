#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//一球从100m高度自由落下,每次落地后反跳回原来高度的一半,再落下
//求它在10次落地时,共经过了多少米?第10次反弹多高?
int main() {
	double height = 100,meters = 0;
	for (int i = 1; i <= 10; ++i) {
		height /= 2.0;
		meters = 100 + meters + 2 * height;
	}
	printf("10次后反弹高度为:%d\n", height);
	printf("10次落地时,共经过%d米\n", meters);
	system("pause");
	return 0;
}



//一分数序列:2/1 + 3/2 + 5/3 + ... 求出这个数列的前20项之和
int main() {
	int a = 2, b = 1,temp;
	double num , sum = 0;
	for (int i = 1; i <= 20; ++i) {
		num = (double)a / b;
		sum += num;
		temp = a;//临时变量
		a = a + b;
		b = temp;
	}
	printf("求和结果为:%lf\n", sum);
	system("pause");
	return 0;
}



//求100~499之间的水仙花数,即各位数字的立方等于本身数
int main() {
	for (int i = 100; i <= 499; ++i) {
		if (pow(i % 10, 3) + pow((i / 10) % 10, 3) + pow((i / 100) % 10, 3) == i) {
			printf("%d\n", i);
		}

	}
	system("pause");
	return 0;
}



//求1~100的k之和加上1~50的k^2之和加上1~10的1/k之和
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
	printf("求和的结果为:%6.2lf\n", sum);

	system("pause");
	return 0;
}



//求1到20的阶乘之和    (未完成待修改)
int main() {
	int i,j,sum = 0,temp = 1;
	for (i = 1; i <= 20; ++i) {
		for (j = 1; j <= i; ++j) {
			temp = temp * j;
		}
		sum += temp;
		//这样用int储存数据,会发生溢出
		//结果不正确
		temp = 1;
	}
	printf("1~20的阶乘之和为:%d\n", sum);
	system("pause");
	return 0;
}



//求Sn = a + aa + aaa + aaaa +...
//其中a是数字,例如 2 + 22 + 222 + 2222 + 22222,此时n = 5,n由键盘输入 
int main() {
	int a, n, num = 0, sum = 0;
	printf("请输入 a 与 n 的值:\n");
	scanf("%d %d", &a, &n);
	for (int i = 1; i <= n; ++i) {
		num = 10 * num + a;
		sum += num;
	}
	printf("a + aa + aaa + ... = %d", sum);
	system("pause");
	return 0;
}



//输入两个正整数m和n,求其最大公约数和最小公倍数
int main() {
	unsigned m, n, min_gb, max_gy;
	while (1) {
		printf("请输入两个正整数m和n:\n");
		scanf("%u %u", &m, &n);
		if (m <= 0) {
			printf("输入错误!\n");
			continue;
		}
		if (n <= 0) {
			printf("输入错误!\n");
			continue;
		}
		break;
	}
	max_gy = (m > n) ? n : m;
	while (max_gy) {
		if ((m % max_gy == 0) && (n % max_gy == 0)) {
			printf("最大公约数为:%d\n", max_gy);
			break;
		}
		max_gy--;
	}
	min_gb = (m > n) ? m : n;
	while (min_gb) {
		if ((min_gb % m == 0) && (min_gb % n == 0)) {
			printf("最小公倍数为:%d\n",min_gb);
			break;
		}
		min_gb++;
	}
	system("pause");
	return 0;
}