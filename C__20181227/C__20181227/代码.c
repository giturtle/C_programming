#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int d = 1;
fun(int p) {
	static int d = 5;
	d += p;
	printf("%d ", d);
	return d;
}
main() {
	int a = 3;
	printf("%d\n", fun(a + fun(d)));
	//6 15 15
	//1+5,6+9,15
}


int d = 1;
fun(int p) {
	int d = 5;
	d += p++;
	printf("%d ", d);
}
main() {
	int a = 3;
	fun(a);
	d += a++;
	printf("%d\n", d);
	//8 4
	system("pause");
	return 0;
}


f(int a) {
	int b = 0;
	static c = 3;
	a = c++;
	b++;
	return a;
}
main() {
	int a = 2, i, k;
	for (i = 0; i < 2; i++) {
		k = f(a++);
	}
	printf("%d\n", k);
	//4
	system("pause");
	return 0;
}


int m = 13;
int fun2(int x, int y) {
	int m = 3;
	return x * y - m;
}
main() {
	int a = 7, b = 5;
	printf("%d\n", fun2(a, b) / m);
	// 2 = 32 / 13
	system("pause");
	return 0;
}


fun3(int x) {
	static int a = 3;
	a += x;
	return a;
}
main() {
	int k = 2, m = 1, n;
	n = fun3(k);
	n = fun3(m);
	printf("%d\n",n);
	// (3+2) + 1 = 6
	system("pause");
	return 0;
}


int a = 3;
main() {
	int s = 0;
	{int a = 5;
	s += a++; }
	s += a++;
	printf("%d\n", s);
	//5+3 = 8
	system("pause");
	return 0;
}


int x = 3;
main() {
	int i;
	for (i = 1; i < x; i++) {
		incre();
	}
	system("pause");
	return 0;
}
incre() {
	static int x = 1;
	x *= x + 1;
	printf(" %d", x);
	//2  6
}


f(int a) {
	int b = 0;
	static int c = 3;
	b++; c++;
	return (a + b + c);
}
main() {
	int a = 2, i;
	for (i = 0; i < 3; i++)
		printf("%d\n", f(a));
	//7  8  9
	system("pause");
	return 0;
}


main() {
	int i;
	for (i = 0; i < 2; i++) {
		add();
	}
	system("pause");
	return 0;
}
add() {
	int x = 0; static int y = 0;
	printf("%d,%d\n", x, y);
	//0,0  0,2
	//静态变量y只进行一次初始化
	x++;
	y = y + 2;
}


int a, b;
void fun() {
	a = 100; b = 200;
}
main() {
	int a = 5,b = 7;
	fun();
	printf("%d%d\n", a, b);
	//形参是实参的一份拷贝
	//形参的变化不影响实参
}


int i = 5;
main() {
	int i = 3;
	{int i = 10;
	i++; }
	f1();
	i += 1;
	printf("%d\n", i);
	//4  = 3 + 1
	system("pause");
	return 0;
}
int f1() {
	i = i + 1;
	return i;
}


int w = 3;
main() {
	int w = 10;
	printf("%d\n", fun(5)*w);
	//360 * 10 = 3600
}
fun(int k) {
	if (k == 0) {
		return w;
	}
	return (fun(k - 1)*k);
}


func(int x) {
	int p;
	if (x == 0 || x == 1)
		return (3);
	p = x - func(x - 2);
	//7
	return p;
}
main() {
	printf("%d\n", func(9));
	system("pause");
	return 0;
}


long fib(int n) {
	if (n > 2) 
		return fib(n - 1) + fib(n - 2);
	else
		return (2);
}
int main() {
	printf("%d\n", fib(3));
	//4   注意不是斐波那契数列
	system("pause");
	return 0;
}


f(int b[], int n) {
	int i, r;
	r = 1;
	for (i = 0; i <= n; i++) {
		r = r * b[i];
	}
	return r;
}
main() {
	int x, a[] = { 2,3,4,5,6,7,8,9 };
	x = f(a, 3);
	printf("%d\n", x);
	//2 * 3 * 4 * 5 = 120;
	system("pause");
	return 0;
}


func(int a, int b) {
	int c;
	c = a + b;
	return c;
}
main() {
	int x = 6, y = 7, z = 8, r;
	r = func((x--, y--, x + y), z--);
	//逗号表达式 x--为5,y--为6		func((5+6),8) = 19;
	printf("%d\n", r);
	system("pause");
	return 0;
}


//编写函数不允许创建临时变量,求字符串的长度
int count(char* p) {
	if (*p == '\0') {
		return 0;
	}
	return 1 + count(p + 1);
}
int main() {
	char *p = "abcdef";
	int len = count(p);
	printf("%d\n", len);
	system("pause");
	return 0;
}



main() {
	int t = 1;
	fun(fun(t));		//为什么第二次调用参数是 3 ????
	system("pause");
	return 0;
}
fun(int h){
	static int a[3] = { 1,2,3 };
	int k;
	for (k = 0; k < 3; k++) {
		a[k] += a[k] - h;
	}
	for (k = 0; k < 3; k++) {
		printf("%d,", a[k]);
	}
	printf("\n");
	return(a[h]);
}