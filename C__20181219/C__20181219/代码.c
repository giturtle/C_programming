#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//通过键盘输入字符,判断其为控制/数字/大写字母/小写字母/其他字母哪一类
int main() {
	char ch;
	printf("请输入字符:\n");
	scanf("%c", &ch);
	if (ch < 32)	//^z
		printf("\n字符为: 控制字符\n");
	else if ((ch >= 'A') && (ch <= 'Z')) {
		printf("\n字符为: 大写字母\n");
	}
	else if ((ch >= 'a') && (ch <= 'z')) {
		printf("\n字符为: 小写字母\n");
	}
	else if ((ch >= '0') && (ch <= '9')) {
		printf("\n字符为: 数字\n");
	}
	else
		printf("\n字符为: 其他字符\n");
	system("pause");
	return 0;
}



//编写简单计算器程序
//根据用户输入的两个操作数和运算符,显示算计结果
//该运算符包括( +,-,*,/ )
int main() {
	int a, b;
	char ysf;
	printf("请输入两个操作数和操作符:\n");
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



//编制菜单程序,在屏幕上显示时间表,根据用户的选择,显示不同的问候信息.
int main() {
	int ch;
	printf("*******时间表*******\n");
	printf("\t1.morning\n");
	printf("\t2.afternoon\n");
	printf("\t3.night\n\n");
	printf("你的选择是:\n");
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


//输入年份和月份,求该月有多少天.
int main() {
	int year, month, day;
	printf("请输入年份和月份:\n");
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
		printf("输入错误,请重新输入!\n");
		day = 0;
	}
	printf("\n%d年%d月 有 %d 天.\n", year, month, day);
	system("pause");
	return 0;
}



//已知银行整存整取存款不同期限的月息利率
//输入存款的本金和年限,求到期时能从银行得到的本息和
//利息 = 本金 × 月息利率 × 12 × 存款年限
int main() {
	unsigned money, year;
	double lixi;
	printf("请输入存款数额和年限:\n");
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
	printf("本息和为:%8.2lf元\n", money + lixi);
	system("pause");
	return 0;
}



//编程,要求输入正整数a,b,若a^2 + b^2大于100,则输出a^2 + b^2百位以上数字
//否则输出二数字之和
int main() {
	unsigned a = 0, b = 0;
	printf("请输入两个正整数:\n");
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



//编程判断输入的正整数是否既是5又是7的整数倍
//若是,则输出yes
//否则,输出no
int main() {
	unsigned i;
	printf("请输入正整数:\n");
	while (1) {
		scanf("%u", &i);
		if (i <= 0) {
			printf("输入错误,请重新输入!\n");
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



//给一个不多于5位的正整数,要求:
//1.求出它是几位数
//2.分别打印出每一位数字
//3.按逆序打印出各位数字,如原数321,应输出123
void print(int num) {
	if (num > 9) {
		print(num / 10);
	}
	printf("%d\n", num % 10);
}
int main() {
	unsigned num,num_copy;
	int count = 0;
	printf("请输入一个不多于5位的正整数:\n");
	scanf("%u", &num);
	num_copy = num;
	//1.求出它是几位数
	while (num_copy) {
		count++;
		num_copy /= 10;
	}
	printf("这个数字是 %d 位数.\n\n",count);

	//2.分别打印出每一位数字
	printf("它的每一位为:\n");
	print(num);
	printf("\n");

	//3.按逆序打印出各位数字,如原数321,应输出123
	printf("逆序之后为:\n");
	for (int i = 1; i <= count; ++i) {
		printf("%d", num % 10);
		num /= 10;
	}
	system("pause");
	return 0;
}



//给出一百分制成绩,要求输入成绩等级'A','B','C','D','E'.
//90分及以上为'A',80-89为'B',70-79为'C',60-69为'D',60分以下为'E'
int main() {
	double score;
	printf("请输入一百分制成绩:\n");
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



//有一分段函数y,写一个程序,输入x,输出y值
int main() {
	double x , y;
	printf("请输入 x 值:\n");
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



//有3个整数a b c,由键盘输入,输出其中最大的数
//--------方案1----------
int main() {
	int a, b, c, temp;
	printf("请输入三个整数:\n");
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
	printf("最大数为:%d\n",a);
	system("pause");
	return 0;
}

//---------方案2--------
int main() {
	int a, b, c, temp1,temp2;
	printf("请输入三个整数:\n");
	scanf("%d %d %d", &a, &b, &c);
	temp1 = (a > b) ? a : b;
	temp2 = (a > c) ? a : c;
	printf("\n最大数为:%d\n", (temp1 > temp2) ? temp1:temp2);
	system("pause");
	return 0;
}

//-------方案三(最简)-----
int main() {
	int a, b, c, temp, max;
	printf("请输入三个整数:\n");
	scanf("%d %d %d", &a, &b, &c);
	temp = (a > b) ? a : b;
	max = (temp > c) ? temp : c;
	printf("最大数为:%d\n", max);
	system("pause");
	return 0;
}