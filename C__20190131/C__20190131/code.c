#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//int int_cmp(const void * p1, const void * p2){
//	return (*(int *)p1 > *(int *)p2);
//}
//
//int main(){
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	int i = 0;
//
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
void int_cmp(const void *p1, const void *p2) {
	return (*(int *)p1 > *(int *)p2);
}


void _swap(void *p1,void *p2,int size){
	int i = 0;
	for (; i < size; i++) {
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}

void bubble(void *base, int count, int size, int(*cmp)(void *, void *)){
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (cmp((char *)base + j * size, (char *)base + (j + 1)*size) > 0)
			{
				_swap((char *)base + j * size, (char *)base + (j + 1)*size, size);
			}
		}
	}
}
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	//char *arr[] = {"aaaa","dddd","cccc","bbbb"};
	int i = 0;
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

//һ���߼���
void Bubble_Sort(int *str,int size) {
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			if (str[cur] < str[cur - 1]) {
				int temp = str[cur];
				str[cur] = str[cur - 1];
				str[cur - 1] = temp;
			}
		}
	}
}
//�ص���������
typedef int(*T)(int, int);
//������������һ������ָ�룬�������ָ���������������

//�˴�����Լ����cmp�����������������������Ҫ�󣬷���1��������ʱ������0��
void BubbleSort(int *str, int size,T cmp) {
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			if (cmp(str[cur - 1],str[cur]) == 0) {
				int temp = str[cur];
				str[cur] = str[cur - 1];
				str[cur - 1] = temp;
			}
		}
	}
}
int Less(int x, int y) {
	return x < y ? 1 : 0;
}
int Greater(int x, int y) {
	return x > y ? 1 : 0;
}
int Abs(int x, int y) {
	return abs(x) < abs(y) ? 1 : 0;
}
int main() {
	int arr[10] = { 1,6,5,4,-3,7,8,-9,2,0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//��������
	BubbleSort(arr, size, Abs);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}



//������/ת�Ʊ�
int add(int a, int b) {		//�ӷ�����
	return a + b;
}

int sub(int a, int b) {		//��������
	return a - b;
}

int mul(int a, int b) {		//�˷�����
	return a * b;
}

int divd(int a, int b) {		//��������
	return a / b;
}

int main() {
	int x, y;
	int input = 1;
	int ret = 0;
	int(*p[5])(int, int) = { 0, add, sub, mul, divd }; //ת�Ʊ�
	while (input) {
		printf("*************************\n");
		printf("  1:add           2:sub  \n");
		printf("  3:mul           4:div  \n");
		printf("*************************\n");
		printf("��ѡ��");
		scanf("%d", &input);
		if ((input <= 4 && input >= 1)) {
			printf("�����������");
			scanf("%d %d", &x, &y);
			ret = (*p[input])(x, y);
		}
		else
			printf("��������\n");
		printf("ret = %d\n", ret);
	}
	system("pause");
	return 0;
}



int Func() {
	printf("hehe\n");
	return 10;
}
int main() {
	printf("%p\n", Func);
	printf("%p\n", &Func);
	printf("%p\n", Func());

	printf("%p\n", *Func);
	printf("%p\n", (*Func)());
	//������һ��ָ�����p��p��������int(*)()�ĺ���ָ������
	//������ָ��int(*)[]���֣����Խ���ʹ��ʱ���������ض��壬ʹ�����ֱ��
	int (*p)() = Func;
	//��ʱ������һ�����͵ı��� T��
	typedef int(*T)();
	T p2 = Func;
	system("pause");
	return 0;
}
