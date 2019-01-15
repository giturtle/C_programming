#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//写一个函数，使给定的一个3×3的二维整型数组转置，行列互换
#define NUM 5
void transform(int arr[][NUM],int num) {
	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {	//如果此时是j = 0；就会转置两次变回原数组
			//核心是 “交换”
			int temp = arr[j][i];
			arr[j][i] = arr[i][j];
			arr[i][j] = temp;
		}
	}
}
int main() {
	int num, arr[NUM][NUM];
	printf("输入二维数组行数:\n");
	scanf("%d", &num);
	printf("输入数组元素:\n");
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	transform(arr, num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


//写一个判定素数的函数，在主函数中输入一个整数，输出是否为素数的信息
int Isprime(int num) {
	int i;
	for (i = 2; i < sqrt(num); i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	if (i >(int)sqrt(num)) {
		return 1;
	}
	//或者在这里 return 1： 代替上面if
}

int main() {
	int num;
	printf("请输入数字:\n");
	scanf("%d", &num);
	if (Isprime(num)) {
		printf("%d是素数", num);
	}
	else {
		printf("%d不是素数", num);
	}
	system("pause");
	return 0;
}


//求出方程ax^2 + bx + c = 0的根，用三个函数分别求：
//当 b^2 - 4ac > 0/ = 0/ < 0时的根并输出结果，从主函数输入a，b，c的值
void dayu(double delta, double p, double q, double a, double b, double c) {
	double x, y;
	printf("\n有两个不等的实根\n");
	x = p + q;
	y = p - q;
	printf("一根为:%5.2lf,一根为: %5.2lf", x, y);
}
void dengyu(double delta, double p, double q, double a, double b, double c) {
	printf("\n有两个相等的实根\n");
	printf("相等的实根为: %5.2lf", p);
}
void xiaoyu(double delta, double p,double q,double a,double b,double c) {
	printf("\n有两个复数根\n");
	printf("一根为: %5.2lf+%5.2lfi\n", p, sqrt(-delta) / (2 * a));
	printf("一根为: %5.2lf-%5.2lfi\n", p, sqrt(-delta) / (2 * a));
}

int main() {
	double a, b, c;
	double delta;
	printf("ax^2 + bx + c = 0\n");
	printf("请输入方程的参数a,b,c：\n");
	scanf("%lf %lf %lf", &a,&b,&c);
	double p = -b / (2 * a);
	delta = b * b - 4 * a * c;
	double q = sqrt(delta) / (2 * a);
	if (delta < 0) {
		xiaoyu(delta, p, q,a,b,c);
	}
	else if (delta == 0) {
		dengyu(delta, p, q, a, b, c);
	}
	else {
		dayu(delta, p, q, a, b, c);
	}
	system("pause");
	return 0;
}


//写两个函数，分别求两个证书的最大公约数和最小公倍数，用主函数调用这两个函数，并输出结果，两个整数有键盘输入

int Max_Gongyue(int num1, int num2) {
	int max = 1;
	for (int i = 1; i < (num1 > num2 ? num2: num1); i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			max = i;
		}
	}
	return max;
}

int Min_Gongbei(int num1,int num2) {
	int min = num1 > num2 ? num1 : num2;
	int i = min;
	while(min){
		if (i % num1 == 0 && i % num2 == 0) {
			min = i;
			break;
		}
		i++;
	}
	return min;
}

int main() {
	int num1, num2;
	printf("请输入两个数字:\n");
	scanf("%d %d", &num1, &num2);
	printf("\n两数为%d，%d\n最大公约数为:%d\n最小公倍数为:%d\n", 
		num1, num2, Max_Gongyue(num1, num2), Min_Gongbei(num1, num2));
	system("pause");
	return 0;
}



//编写一个程序，将字符数组s2中的全部字符复制到字符数组s1中
//不要用strcpy函数，复制时，'\0'也要一并复制过去，'\0'后的字符不复制
int main() {
	char s1[20];
	char s2[20];
	gets(s2);
	int i = 0, j = 0;
	for(;s2[i] != '\0';i++){
	//while(s2[i] != '\0'){   //两个条件都可以，for和while可以互相转换,此语句i要设置自增
		s1[j++] = s2[i];
	}
	s1[j] = '\0';
	printf("复制后的si数组为:\n");
	puts(s1);
	system("pause");
	return 0;
}


//编程将两个字符串s1和s2比较
//若s1>s2，输出一个正数，若s1=s2，输出0，若s1<s2，输出一个负数
//不要使用strcpy函数，两个字符串用gets函数输入
//输出的整数或负数的绝对值应是相比较的两个字符串相应字符的ASCII码的差值
int main() {
	char s1[10];
	char s2[10];
	printf("请输入字符串s1:\n");
	gets(s1);
	printf("请输入字符串s2:\n");
	gets(s2);
	int i = 0;
	for (; s1[i] != '\0' && s1[i] != '\0'; i++) {
		if (s1[i] == s2[i]) {
			continue;
		}
		else
			printf("%d\n", s1[i] - s2[i]);
	}
	if (s1[i] == '\0' || s2[i] == '\0') {
		printf("%d\n", 0);
	}
	system("pause");
	return 0;
}


//编写一个程序，将两个字符串连接起来，不要用strcat函数
int main() {
	char arr1[20] = "i am";
	char arr2[10] = " Tom!";
	int j = 0;
	int i = 0;
	while (arr1[i] != '\0') {
		arr1[j++] = arr1[i++];
	}
	i = 0;
	while(arr2[i]!= '\0'){
		arr1[j++] = arr2[i++];
	}
	arr1[j] = '\0';
	puts(arr1);
	system("pause");
	return 0;
} 