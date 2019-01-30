#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//输入3个学生2门成绩，分别用函数实现下列功能：
//1. 计算每个学生的平均分
//2. 计算每门课的平均分
//3. 找出所有6个分数中最高的分数所对应的学生和课程
#define STUDENT 3
#define COURSE 2
void avg_student(double (*stu)[2]) {
	double sum = 0; 
	for(int i = 0;i < STUDENT;i++){
		sum = stu[i][0] + stu[i][1];
		printf("第%d个学生的平均成绩为：%5.2lf\n", i + 1, sum / COURSE);
	}
}

void avg_course(double(*stu)[2]) {
	double sum = 0;
	for (int j = 0; j < COURSE; j++) {
		sum = stu[0][j] + stu[1][j] + stu[2][j];
		printf("第%d门课程的平均成绩为：%5.2lf\n", j + 1, sum / STUDENT);
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
	printf("最高分的成绩是第%d位学生的第%d门课程，最高分为%5.2lf\n", x + 1, y + 1, max);
}

int main() {
	double stu[3][2];
	int i, j;
	for (i = 0; i < STUDENT; i++) {
		for (j = 0; j < COURSE; j++) {
			printf("请输入第%d个学生的第%d门成绩：\n", i + 1, j + 1);
			scanf("%lf", &stu[i][j]);
		}
	}
	avg_student(stu);	//计算每个学生的平均分
	printf("\n");
	avg_course(stu);	//计算每门课的平均分
	printf("\n");
	Found(stu);			//找出所有6个分数中最高的分数所对应的学生和课程
	system("pause");
	return 0;
}




//用递归方法求n阶勒让德多项式的值
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
	return -1;		//异常处理
}

int main() {
	double val;
	int n;
	printf("请输入x的值：\n");
	scanf("%lf", &val);
	printf("请输入阶数n的值：\n");
	scanf("%d", &n);
	printf("%5.2lf\n",Lrd(n, val));
	system("pause");
	return 0;
}



//用牛顿迭代法求根，方程为ax^3 + bx^2 + cx + d = 0，系数a，b，c，d的值依次为1，2，3，4
//由主函数输入，求 x 在 1 附近的一个实根，求出根后由主函数输出

double Newton(double a, double b, double c, double d)
{
	double x1 = 1, x, f, f1;
	//迭代
	do{
		x = x1;
		f = ((a*x + b)*x + c)*x + d;//原函数
		f1 = (3 * a*x + 2 * b)*x + c;//求导之后的函数
		x1 = x - f / f1;
	} while (fabs(x1 - x) >= 0.00000001);
	return x1;
}

int main()
{
	double a, b, c, d;
	printf("输入方程系数:\n");
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	printf("方程近似根root = %5.3lf\n", Newton(a, b, c, d));
	system("pause");
	return 0;
}



//写一个函数，用起泡法对输入的10个字符按由小到大的顺序排列
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
	printf("输入一个包含10个字符的字符串:\n");
	gets(arr);
	Sort(arr);
	for (int i = 0; arr[i] != '\0'; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}