#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


//给出年月日，求出该日是该年的第几天

//一
int sum_day(int month, int day)
{
	int day_tab[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int i;
	for (i = 1; i < month; i++)
		day += day_tab[i];      /* 累加所在月之前天数 */
	return day;
}                         /* 函数leap:判断是否为闰年 */
int leap(int year){
	int leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	return leap;
}

//二
int Print(int year,int month,int day) {
	int month_list[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 1; i < month; i++) {
		day += month_list[i];
	}
	if (((year % 4 == 0) && (year % 100 != 0))
		|| (year % 400 == 0)) {
		day += 1;
	}
	return day;
}

int main() {
	int year, month, day;
	printf("请输入年、月、日:\n");
	scanf("%d %d %d", &year, &month, &day);
	printf("%d/%d/%d ", year, month, day);
	printf("是该年的第%d天.\n", Print(year, month, day));

	int sum;
	sum = sum_day(month, day);
	if (leap(year) && month >= 3)
	sum = sum + 1;
	printf("is the %dth day in this year.\n", sum);
	system("pause");
	return 0;
}



void Transform_1(int num) {
	if (num > 9) {
		Transform_1(num / 10);
	}
	printf("%c ", num % 10 + '0');
}

//用递归法将一个整数n转换成字符串，n位数不确定
int main() {
	int val = 0;
	printf("请输入一个数字:\n");
	scanf("%d", &val);
	Transform_1(val);
	printf("\n");
	system("pause");
	return 0;
}



//写一个函数，输入十六进制数，输出十进制数

//**********************************************************
void xtod(int x) {
	printf("%d\n", x);
}

int main(){
	int i;
	scanf("%x", &i);
	xtod(i);
	return 0;
}
//**********************************************************

int Transform(char val[],int wei) {
	int sum = 0;
	for (int i = wei - 1; i >= 0; i--) {
		if (val[i] >= '0' && val[i] <= '9') {
			//num += (a[i] - '0')*pow(16, n - 1 - i);
			sum += (val[i] - '0')* (int)pow(16, wei - 1 - i);
		}
		else if (val[i] >= 'A' && val[i] <= 'Z') {
			sum += (10 + (val[i] - 'A')) * (int)pow(16, wei - 1 - i);
		}
		else if (val[i] >= 'a' && val[i] <= 'z') {
			sum += (10 + (val[i] - 'a')) * (int)pow(16, wei - 1 - i);
		}
	}
	return sum;
}
int main() {
	char num[20];
	printf("请输入一个十六进制数字：\n");
	scanf("%s", num);
	int wei = strlen(num);
	printf("转换后的十进制数为:%d\n", Transform(num,wei));
	system("pause");
	return 0;
}



//写几个函数：
//1. 输入10个职工的姓名和职工号
//2. 按职工号由小到大顺序排序，姓名顺序也随之调整
//3. 按照输入一个职工号，折半查找找出该职工的姓名
//	从主函数输入要查找的职工号，输出该职工该姓名
#define PEOPLE 4
void input(char str[][20],int num[]) {
	for (int i = 0; i < PEOPLE; i++) {
		printf("请输入%d个职工的姓名:\n",i+1);
		scanf("%s", str[i]);
		printf("请输入第%d个职工的职工号:\n", i + 1);
		scanf("%d", num);
		printf("\n");
	}
}

void Sort(char str[][20], int num[]) {
	//↓错误   ？？？
	for (int bound = 0; bound < PEOPLE; ++bound) {
		for (int cur = PEOPLE - 1; cur > bound; --cur) {
			if (num[cur - 1] > num[cur]) {
				int temp = num[cur - 1];
				num[cur - 1] = num[cur];
				num[cur] = temp;
				char tmp[20];
				strcpy(tmp, str[cur - 1]);
				strcpy(str[cur - 1], str[cur]);
				strcpy(str[cur],tmp);
			}
		}
	}
	//↓正确
	for (int i = 0; i < PEOPLE; i++) {
		for (int j = i + 1; j < PEOPLE; j++) {
			if (num[i] > num[j]) {
				int temp = num[i];
				num[i] = num[j];
				num[j] = temp;
				char tmp[20];
				strcpy(tmp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], tmp);
			}
		}
	}
}
int main() {
	char name[4][20];
	int num[20];
	input(name,num);
	for (int i = 0; i < 4; i++) {
		printf("%s\n", name[i]);
	}
	printf("\n");
	Sort(name, num);
	//Found(name, num);
	for (int i = 0; i < 4; i++) {
		printf("%s\n", name[i]);
	}

	system("pause");
	return 0;
}



//输入3个学生2门成绩，分别用函数实现下列功能：
//4. 计算平均分方差

void var(double stu[][2]) {
	int i, j, k;
	double temp[3],sum = 0;
	double var, x1 = 0, x2 = 0;
	for (i = 0,k = 0; i < 3; i++,k++) {
		for (j = 0; j < 2; j++) {
			sum += stu[i][j];
		}
		temp[k] = sum / 2;
	}
	for (i = 0; i < 3; i++) {
		x1 += pow(temp[i], 2);
		x1 += temp[i];
	}
	var = x1 / 2 - pow(x2 / 2, 2);
	printf("平均值的方差为:%5.2lf\n", var);
}

int main() {
	double stu[3][2];
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			printf("请输入第%d个学生的第%d门成绩：\n", i + 1, j + 1);
			scanf("%lf", &stu[i][j]);
		}
	}
	var(stu);
	system("pause");
	return 0;
}

