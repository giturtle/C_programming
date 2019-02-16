#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Stdlib.h>



//typedef struct st_type {
//	int i;
//	int *a;
//}Test;

//typedef struct st_type {
//	int i;
//	int a[0];		//柔性数组成员，0的意思是可以有任意多个元素
//}Test;
//
//int main() {
//	/*Test *t = (Test*)malloc(sizeof(int) + sizeof(int) * 10);
//	Test *t2 = (Test*)malloc(sizeof(int) + sizeof(int) * 100);
//	t->i = 10;
//	for (int i = 0; i < 10; ++i) {
//		t->a[i] = i;
//	}
//	free(t);
//	free(t2);*/
//
//
//
//
//	/*Test *t2 = (Test*)malloc(sizeof(Test));
//	t2->i = 10;
//	t2->a = (int*)malloc(sizeof(int) * 10);
//	free(t2->a);
//	free(t2);*/
//
//
//	system("pause");
//	return 0;
//}

////栈、堆、代码段、数据段
//void func() {
//
//}
//int a = 10;
//int main() {
//	int *p = (int*)malloc(4);
//	int b = 0;
//	const char *str = "abc";
//	printf("函数的地址 = %p\n", &func);
//	printf("常量的地址 = %p\n", str);
//	printf("全局变量的地址 = %p\n", &a);
//	printf("堆的地址 = %p\n", p);
//	printf("栈的地址 = %p\n", &b);
//	system("pause");
//	return 0;
//}
