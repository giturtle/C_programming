#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//编程找出1~99之间的全部同构数
//同构数是这样一组数:它出现在平方数的右边
//例如:5是25右边的数,25是625右边的数,5和25都是同构数

//问题内核
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

//方法二
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

//方法三
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


//(题设有歧义)
//每个苹果0.8元,第一天买2个苹果
//第二天开始,每天买前一天的2倍
//直到购买的苹果个数达到不超过100的最大值
//编写程序求每天平均花多少钱?
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



//编写程序,从键盘输入6名学生的5门成绩,分别统计出每个学生的平均成绩
#define M 6
#define N 5
int main() {
	double grade, sum = 0;
	int count = 0;
	printf("请输入%d名学生的%d门成绩:\n", M, N);
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%lf", &grade);
			sum += grade;
		}
		printf("第%d位学生的平均成绩为:%5.2lf\n",++count, sum / N);
		sum = 0;
	}
	system("pause");
	return 0;
}