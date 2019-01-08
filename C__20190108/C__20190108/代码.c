#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


//编写程序将“China”翻译成密码，密码规律：
//用原来的字母后面第四个字母代替原来的字母，用赋值的方法和putchar方法输出5个字符
int main() {
	char a,b,c,d,e;
	printf("请输入密码:\n");
	a = getchar();
	b = getchar();
	c = getchar();
	d = getchar();
	e = getchar();
	putchar(a + 4);
	putchar(b + 4);
	putchar(c + 4);
	putchar(d + 4);
	putchar(d + 4);
	printf("\n");
	system("pause");
	return 0;
}


int main() {
	//char c1,c2;
	//int c1, c2;
	c1 = 197;
	c2 = 198;
	printf("c1 = %c,\t c2 = %c\n", c1, c2);
	printf("c1 = %d,\t c2 = %d\n", c1, c2);
	system("pause");
	return 0;
}


//购房从银行贷款d，准备每月还款额为p，月利率为r，计算多少月能够还清
//设d为300000元，p为6000元，r为1%，对求得的月份取小数点后一位，对第二位按四舍五入处理
int main() {
	double m, p = 6000, d = 300000, r = 0.01;
	m = log10(p / (p - d * r)) / log10(1 + r);
	printf("%5.1lf个月\n", m);
	system("pause");
	return 0;
}


//假如我国国民生产总值的年增长率为9%，计算10年后我国的国民生产总值
//与现在相比，增长了多少百分比。 p = (1 + r) ^ n
#define increase 0.09
int main() {
	double p;
	p = pow(1 + increase,10);
	printf("增长了%7.4lf%%", p);
	system("pause");
	return 0;
}


int main() {
	double  a, b, c,delta_sqrt,delta, num,root1, root2;
	printf("y = ax^2 + bx + c\n请输入a,b,c的值:\n");;
	scanf("%lf %lf %lf", &a, &b, &c);
	delta = b * b - 4 * a * c;
	if (delta < 0) {
		printf("此方程无根！\n");
	}
	else {
		delta_sqrt = sqrt(delta) / (2.0 * a);
		num = -b / (2.0 * a);
		root1 = num + delta_sqrt;
		root2 = num - delta_sqrt;
		printf("%5.2lf %5.2lf", root1, root2);
	}
	system("pause");
	return 0;
}