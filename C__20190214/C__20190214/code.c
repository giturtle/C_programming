#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



//λ��
struct A {
	//�ĸ�λ�����ͱ���
	int _a : 2;	//a����ռ�� 2��λ
	int _b : 5;	//a����ռ�� 5��λ
	int _c : 10;
	int _d : 30;
};


struct S
{
	int data[1000];
	int num;
};

//�ṹ�崫��
void print1(struct S s) {
	printf("%d\n", s.num);
}

//�ṹ���ַ����
void print2(struct S *ps) {
	printf("%d\n", ps->num);
}

int main() {
	print1(s);		//���ṹ��
	print2(&s);		//���ṹ���ַ
	return 0;
}


//�����ṹ��
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
