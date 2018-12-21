#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//编程求一个整数任意次方的最后3位数,即求x ^ y的最后三位数
//要求x,y从键盘输入
int main() {
	int x, y, temp = 1;
	printf("请输入x和y:\n");
	scanf("%d %d", &x, &y);
	for (int i = 1; i <= y; ++i) {
		temp = temp * x;
	}
	printf("最后三位数是:%d\n", temp % 1000);
	system("pause");
	return 0;
}



//爱因斯坦的阶梯问题
//假设有一阶梯,每步跨2阶,最后余1阶.每步跨3阶,最后余2阶
//每步跨5阶最后余4阶.每步跨6阶,最后余5阶;
//只有每步跨7阶时,正好到达阶梯顶,请问共有多少阶梯?
int main() {
	int jie = 1;
	while (jie) {
		if ((jie % 2 == 1) &&
			(jie % 3 == 2) &&
			(jie % 5 == 4) &&
			(jie % 6 == 5) &&
			(jie % 7 == 0)) {
			printf("%d\n", jie);
			break;	//break了会打印最小的结果,但只要是119的倍数都满足题意
		}
		jie++;
	}
	system("pause");
	return 0;
}



//百鸡问题:100元钱买100只鸡,公鸡1只5元钱,母鸡1只3元钱,小鸡1元钱3只.
//求100元能买多少公鸡/母鸡/小鸡各几只?
#define shuliang 100
int main() {
	int gongji, muji;
	double xiaoji;
	gongji = 5;
	muji = 3;
	xiaoji = 1.0 / 3;
	for (int i = 0; i <= 20; ++i) {
		for (int j = 0; j <= 100 / 3.0; ++j) {
			for (int k = 0; k <= 300; ++k) {
				if (k % 3 != 0)
					continue;
				if ((i*gongji + j * muji + k/3.0 == 100)
				&& (i + j + k == shuliang)){
					printf("%d %d %d\n", i,j,k);
				}
			}
		}
	}
	system("pause");
	return 0;
}

//另一种解析
int main() {
	int cocks, hens, chicks;
	cocks = 0;
	while (cocks <= 20) {
		hens = 0;
		while (hens <= 33) {
			chicks = 100.0 - cocks - hens;
			if (5.0*cocks + 3.0*hens + chicks / 3.0 == 100.0) {
				printf("%d %d %d\n", cocks, hens, chicks);
			}
			hens++;
		}
		cocks++;
	}
	system("pause");
	return 0;
}



//打印菱形
#define N 6
int main() {
	int i, j;
	for (i = 1; i <= N; ++i) {
		//先打印空格
		for (j = 1; j <= N - i; ++j) {
			printf(" ");
		}
		//再打印星号 *
		for (j = 1; j <= (2 * i) - 1; ++j) {
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i <= N - 1; ++i) {
		for (j = 1; j <= i; ++j) {
			printf(" ");
		}
		for (j = 1; j <= (2 * N - 1) - 2 * i; ++j) {
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}



//用二分法求2x^3 - 4x^2 + 3x - 6 = 0在(-10,10)之间的根
int main() {
	double x0, x1, x2, fx0, fx1, fx2;
	do {
		printf("请输入 x1 与 x2 的值:\n");
		scanf("%lf %lf", &x1, &x2);
		fx1 = 2 * pow(x1, 3) - 4 * pow(x1, 2) + 3 * x1 - 6;
		fx2 = 2 * pow(x2, 3) - 4 * pow(x2, 2) + 3 * x2 - 6;
	} while (fx1 * fx2 > 0);
	//保证在指定范围内有根,必须使两端点处的函数值相反
	do {
		x0 = (x1 + x2) / 2;	//取中点x0
		fx0 = 2 * pow(x0, 3) - 4 * pow(x0, 2) + 3 * x0 - 6;
		//求出 x0 的函数值
		if (fx0 * fx1 < 0) {	//若fx0和fx1符号相反
			x2 = x0;
			fx2 = fx0;
		}
		else {	//若fx0与fx2符号相反
			x1 = x0;
			fx1 = fx0;
		}
	} while (fabs(fx0) >= 1e-5);
	//判断 x0 处函数值是否足够逼近0值
	printf("x = %6.2lf\n", x0);
	system("pause");
	return 0;
}



//猴子吃桃问题,猴子第一天摘下若干个桃,当即吃了一半,还不过瘾,又多吃了一个
//第二天早上又将剩下的桃子吃掉了一半,又多吃了一个
//以后每天早上都吃了前一天剩下的一半零一个
//到第10天早上想再吃,就只剩一个桃子了.
//求第一天共摘了多少个桃子
int main() {
	int taozi = 1;
	for (int i = 10; i > 1; --i) {
		taozi = 2 * (taozi + 1);
	}
	printf("第一天摘了%d个桃子.\n", taozi);
	system("pause");
	return 0;
}


//修改问题:  求1到20的阶乘之和
int main() {
	int i, j;
	double sum = 0, temp = 1;
	for (i = 1; i <= 20; ++i) {
		for (j = 1; j <= i; ++j) {
			temp = temp * j;
		}
		sum += temp;
		temp = 1;
	}
	printf("1~20的阶乘之和为:%lf\n", sum);
	system("pause");
	return 0;
}



//修改篮球自由落体问题
int main() {
	double meters = 100, height = meters / 2.0;
	//meters计算第一次着地,没开始反弹
	//height计算反弹的高度
	for (int i = 2; i <= 10; ++i) {
		meters = meters + 2 * height;
		//两次着地之间的距离为2*height;
		height /= 2.0;
		//for循环中这两句不可调换位置!!
	}
	printf("10次后反弹高度为:%lf\n", height);
	printf("10次落地时,共经过%lf米\n", meters);
	system("pause");
	return 0;
}
