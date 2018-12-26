#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//数组内容逆置函数
void reverse(int a[], int n) {
	int i, t;
	for (i = 0; i < n / 2; i++) {
		t = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = t;
	}
}
int main() {
	int b[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i, s = 0;
	reverse(b, 8);
	for (i = 6; i < 10; i++) {
		s += b[i];
	}
	printf("%d\n", s);
	//22 = 1 + 2 + 9 + 10
	system("pause");
	return 0;
}


f(int b[], int m, int n) {
	int i, s = 0;
	for (i = m; i < n; i = i + 2) {
		s = s + b[i];
	}
	return s;
}
int main() {
	int x, a[] = { 1,2,3,4,5,6,7,8,9 };
	x = f(a, 3, 7);
	printf("%d\n", x);
	//10 = 4 + 6
	system("pause");
	return 0;
}


fun(char s[], char t[]) {
	int i = -1;
	while (++i, s[i] == t[i] && s[i] != '\0');
	return s[i] == '\0' && t[i] == '\0';
}
//函数的功能是: 比较两字符串是否相等


int abc(int u, int v) {
	int w;
	while (v) {
		w = u % v; 
		u = v;
		v = w;
	}
	return u;
}
int main() {
	int a = 24, b = 16, c;
	c = abc(a, b);
	printf("%d\n", c);
	//8
	system("pause");
	return 0;
}


float fun(int x, int y) {
	return (x + y);
}
main() {
	int a = 2, b = 5, c = 8;
	printf("%3.0f\n", fun((int)fun(a + c, b), a - c));
	//15 - 6 = 9;
	system("pause");
	return 0;
}


void func1(int i);//先声明函数,之后在函数主体内定义
void func2(int i);
char st[] = "hello,friend!";
void func1(int i){
	printf("%c", st[i]);
	if (i < 3) {
		i += 2;
		func2(i);
	}
}
void func2(int i) {
	printf("%c", st[i]);
	if (i < 3) {
		i += 2;
		func1(i);
	}
}
int main() {
	int i = 0;
	func1(i);
	//hlo
	printf("\n");
	system("pause");
	return 0;
}



fun(int x, int y, int z) {
	z = x * x + y * y;
}
int main() {
	int a = 31;
	fun(5, 2, a);
	printf("%d\n", a);
	//31 形参变化不影响实参
	system("pause");
	return 0;
}


int main() {
	int i = 3;
	printf("%d %d %d\n", i, i++, i++);
	//5 4 3
	//函数的参数是 [由右往左] 入栈的
	system("pause");
	return 0;
}