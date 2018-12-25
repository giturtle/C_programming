#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//用递归法将一个整数转换成字符串
//例如:输入483,应输出字符串"483". n的位数不确定,可以是任意的整数
void print(int num) {
	if (num > 9) {
		print(num / 10);
	}
	printf("%c", num % 10 + '0');
}
int main() {
	int num = 0;
	printf("请输入一个整数:\n");
	scanf("%d", &num);
	if (num < 0) {
		printf("-");
		num = -num;
	}
	print(num);
	system("pause");
	return 0;
}


//输入一行字符,分别统计出其中的英语字母/空格/数字和其他字符的个数
void count(char* str) {
	int yy = 0, kg = 0, sz = 0, qt = 0;
	while (*str) {
		if ((*str >= 'a' && *str <= 'z')||(*str >= 'A' && *str <= 'Z')) {
			yy++;
		}
		else if (*str == ' ') {
			kg++;
		}
		else if (*str >= '0' && *str <= '9') {
			sz++;
		}
		else {
			qt++;
		}
		str++;
	}
	printf("英语字母:%d\n", yy);
	printf("数字:%d\n", sz);
	printf("空格:%d\n", kg);
	printf("其他字符:%d\n",qt);
}
int main() {
	char str[100];
	printf("请输入一行字符:\n");
	gets(str);
	count(str);
	system("pause");
	return 0;
}


//[还没做完]
//输入10个学生的5门课程的成绩,分别用函数求:
//1. 每个学生的平均分
//2. 每门课程的平均分
//3. 找出最高的分数所对应的学生和课程
#define N 10
#define M 5

//学生平均分函数
double stu_avg(double* a) {
	int i = 0; double stu[], average;
	for (; i < M; i++) {
		stu[i] = *a;
		a++;
	}
	average = sum / M;
	return average;
}

//课程平均分函数

int main() {
	double a[N][M];
	double stu[N];
	double course[M];
	//输入学生成绩
	for (int i = 0; i < N; i++) {
		printf("请输入第%3d个学生的%d个成绩:\n", i + 1, M);
		for (int j = 0; j < M; j++) {
			scanf("%lf", &a[i][j]);
		}
	}
	//调用学生平均分函数,计算学生平均分
	//调用课程平均分函数,计算课程平均分

	//输出分数与计算结果
	printf("\n序号 课程1 课程2 课程3 课程4 课程5 平均分\n");
	for (int i = 0; i < N; i++) {
		printf("No.%d", i + 1);
		for (int j = 0; j < M; j++) {
			printf("%8.2lf", a[i][j]);
		}
		printf("%8.2lf", stu[i]);
	}
	printf("%lf", stu_avg(a));
	system("pause");
	return 0;
}