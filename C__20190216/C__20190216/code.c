#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//��ָ��ָ��ķ�����n�������������
//Ҫ�����򵥶�д��һ��������n�������������������룬����������������
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
	printf("�����������ĸ���n:\n");
	scanf("%d", &n);
	int *p = (int*)malloc(n * sizeof(int));
	printf("������%d������:\n",n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
	}
	Sort(p,n);
	printf("����������Ϊ:\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", p[i]);
	}
	free(p);
	system("pause");
	return 0;
}



//��ָ��ָ���ָ��ķ�����5���ַ����������
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
	printf("������5���ַ�����\n");
	//�����ά��������
	for (int j = 0; j < 5; ++j) {
		scanf("%s", b[j]);
	}
	//�Ѷ�ά����ĸ�ά����ָ������
	for (int i = 0; i < 5; ++i) {
		ptr[i] = b[i];
	}
	Sort(ptr);
	printf("�������ַ���Ϊ:\n");
	for (int k = 0; k < 5; ++k) {
		printf("%s\n", ptr[k]);
	}
	system("pause");
	return 0;
}


//дһ������new����n���ֽڿ��������ڴ�ռ䡣new(n)��ʾ����n���ֽڵ��ڴ�ռ�
//дһ������free����ǰ��new����ռ�õĿռ��ͷš�free(p)��ʾ��p����ַ��ָ��ĵ�Ԫ�Ժ���ڴ���ͷ�
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
	int a[0];		//���������Ա��0����˼�ǿ�����������Ԫ��
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

//ջ���ѡ�����Ρ����ݶ�
void func() {

}
int a = 10;
int main() {
	int *p = (int*)malloc(4);
	int b = 0;
	const char *str = "abc";
	printf("�����ĵ�ַ = %p\n", &func);
	printf("�����ĵ�ַ = %p\n", str);
	printf("ȫ�ֱ����ĵ�ַ = %p\n", &a);
	printf("�ѵĵ�ַ = %p\n", p);
	printf("ջ�ĵ�ַ = %p\n", &b);
	system("pause");
	return 0;
}
