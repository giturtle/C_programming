#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	int x;
	printf("����һ��������x��");
	scanf("%d",&x);
	if (prime(x)) {
		printf("yes\n");
	}else{
		printf("no\n");
	}
	system("pause");
	return 0;
}
int prime(int a) {
	int e, i, yes;
	yes = 1, e = a / 2;
	i = 2;
	while (i <= e) {
		if (a % i == 0 && yes != 0) {
			yes = 0;
		}
		else {
			i++;
		}
		return yes;
	}
}


void sort(int n, int array[]) {
	int i, j, k, t;
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (array[k] > array[j]) {
				k = j;
			}
		}
		t = array[i];
		array[i] = array[k];
		array[k] = t;
	}
}
main() {
	int i, a[10];
	printf("�������飺\n");
	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	sort(10,a);
	printf("��������飺\n");
	for (i = 0; i < 10; i++) {
		printf("%5d", a[i]);
	}
	system("pause");
	return 0;
}


void BubbleSort(int arr[], int size) {
	int bound = 0;//�߽�
	//[0,bound) ����������
	//[bound,size) ����������
	for (; bound < size; ++bound) {
		//ÿѭ��һ�Σ����ҵ�һ����ǰ��Сֵ�ŵ�������������
		//cur�Ǹ����ҳ���Сֵ��һ����������ʾ��ǰ�ڶ��ĸ�Ԫ�ؽ��бȽ�
		int cur = size - 1;
		for (; cur > bound; --cur) {
			//�������ǰ���Ԫ�رȺ����Ԫ�ش󣬲���������Ҫ��
			if (arr[cur - 1] > arr[cur]) {
				Swap(&arr[cur], &arr[cur - 1]);
			}
		}
	}
}


int main() {
	char arr[10];
	printf("�������10���ַ���\n");
	getch(arr);
	int size = sizeof(arr) / sizeof(arr[0]);
	Bubble_sort(arr,size);
	puts(arr);
	system("pause");
	return 0;
}



#define N 10
char str[N];
main() {
	int i, flag;
	for (flag = 1; flag == 1;) {
		scanf("%s", str);
		flag = 0; printf("\n");
	}
	sort(str);
	for (i = 0; i < N; i++) {
		printf("%c", str[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
sort(char str[N]) {
	int i, j;
	char t;
	for (j = 1; j < N; j++) {
		for (i = 0; (i < N - j) && (str[i] != '\0'); i++) {
			if (str[i] > str[i + 1]) {
				t = str[i];
				str[i] = str[i - 1];
				str[i - 1] = t;
			}
		}
	}
}


//��ʹ�ú����ҳ�3���ַ��������
int main() {
	int i; char string[20], str[3][20];
	for (i = 0; i < 3; i++) {
		gets(str[i]);
	}
	strlen(str[0]) > strlen(str[1]) ?
		strcpy(string,str[0]): strcpy(string, str[1]);
	if (strlen(str[2]) > strlen(string)) {
		strcpy(string, str[2]);
	}
	puts(string);
	system("pause");
	return 0;
}
