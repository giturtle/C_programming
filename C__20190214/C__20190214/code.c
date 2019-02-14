#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



//位段
struct A {
	//四个位段类型变量
	int _a : 2;	//a变量占存 2个位
	int _b : 5;	//a变量占存 5个位
	int _c : 10;
	int _d : 30;
};


struct S
{
	int data[1000];
	int num;
};

//结构体传参
void print1(struct S s) {
	printf("%d\n", s.num);
}

//结构体地址传参
void print2(struct S *ps) {
	printf("%d\n", ps->num);
}

int main() {
	print1(s);		//传结构体
	print2(&s);		//传结构体地址
	return 0;
}


//匿名结构体
struct {		
	int a;
	char b;
	float c;
}x;

struct {
	int a;
	char b;
	float c;
}*p, a[8];
int main() {
	p = &x;
	return 0;
}


struct Student {
	char a;
	int b;
	int c;
};
int main() {
	struct Student stu;
	printf("stu = %p\n", &stu);
	printf("stu.a = %p\n", &stu.a);
	printf("stu.b = %p\n", &stu.b);
	printf("stu.c = %p\n", &stu.c);
	printf("%lu\n", sizeof(stu));
	system("pause");
	return 0;
}
