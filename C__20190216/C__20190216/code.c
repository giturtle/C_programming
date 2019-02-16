#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//用指向指针的方法对n个整数排序并输出
//要求将排序单独写成一个函数，n个整数在主函数中输入，最后在主函数中输出
void Sort(int *p,int n) {
	for (int bound = 0; bound < n; ++bound) {
		for (int cur = n - 1; cur > bound; --cur) {
			if (p[cur - 1] < p[cur]) {
				int temp = p[cur - 1];
				p[cur - 1] = p[cur];
				p[cur] = temp;
			}
		}
	}
}
int main() {
	int n;
	printf("请输入整数的个数n:\n");
	scanf("%d", &n);
	int *p = (int*)malloc(n * sizeof(int));
	printf("请输入%d个整数:\n",n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
	}
	Sort(p,n);
	printf("处理后的整数为:\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", p[i]);
	}
	free(p);
	system("pause");
	return 0;
}



//用指向指针的指针的方法对5个字符串排序并输出
void Sort(char **p) {
	char *t,**q,**x;
	for (q = p; q < p + 5; ++q) {
		for (x = q + 1; x < p + 5; ++x) {
			if (strcmp(*q , *x) > 0) {
				t = *q;
				*q = *x;
				*x = t;
			}
		}
	}
}
int main() {
	char *ptr[5],b[5][30];
	printf("请输入5个字符串：\n");
	//输入二维数组内容
	for (int j = 0; j < 5; ++j) {
		scanf("%s", b[j]);
	}
	//把二维数组的高维赋给指针数组
	for (int i = 0; i < 5; ++i) {
		ptr[i] = b[i];
	}
	Sort(ptr);
	printf("排序后的字符串为:\n");
	for (int k = 0; k < 5; ++k) {
		printf("%s\n", ptr[k]);
	}
	system("pause");
	return 0;
}


//写一个函数new，对n个字节开辟连续内存空间。new(n)表示分配n个字节的内存空间
//写一个函数free，对前面new函数占用的空间释放。free(p)表示将p（地址）指向的单元以后的内存段释放
char *new(int n){
	char *p = (char*)malloc(n * sizeof(char));
	return p;
}
void free_1(char *p) {
	free(p);
}
int main() {
	int n;
	scanf("%d", &n);
	char *p = new(n);
	scanf("%s", p);
	puts(p);
	free_1(p);
	system("pause");
	return 0;
}



typedef struct st_type {
	int i;
	int *a; 
}Test;

typedef struct st_type {
	int i;
	int a[0];		//柔性数组成员，0的意思是可以有任意多个元素
}Test;

int main() {
	/*Test *t = (Test*)malloc(sizeof(int) + sizeof(int) * 10);
	Test *t2 = (Test*)malloc(sizeof(int) + sizeof(int) * 100);
	t->i = 10;
	for (int i = 0; i < 10; ++i) {
		t->a[i] = i;
	}
	free(t);
	free(t2);*/




	/*Test *t2 = (Test*)malloc(sizeof(Test));
	t2->i = 10;
	t2->a = (int*)malloc(sizeof(int) * 10);
	free(t2->a);
	free(t2);*/


	system("pause");
	return 0;
}

//栈、堆、代码段、数据段
void func() {

}
int a = 10;
int main() {
	int *p = (int*)malloc(4);
	int b = 0;
	const char *str = "abc";
	printf("函数的地址 = %p\n", &func);
	printf("常量的地址 = %p\n", str);
	printf("全局变量的地址 = %p\n", &a);
	printf("堆的地址 = %p\n", p);
	printf("栈的地址 = %p\n", &b);
	system("pause");
	return 0;
}
