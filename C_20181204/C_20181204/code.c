//�۰����������������Ҫ�����֣����������±�#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
int main() {
	int arr[10] = { 0,1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int to_found = 5;
	int mid = 0;
	int left = 0;
	int right = (sizeof(arr) / sizeof(arr[0]) - 1);
	for (int i = 0; i <= sizeof(arr) / sizeof(arr[0]); ++i) {
		mid = (left + right) / 2;
		//���˴���㣺�˴������int mid�������˾ֲ���������������ֻ��ѭ����������.
		//������ɫ��Ӱ�е�mid��Ϊȫ�ֱ��������н��Ϊ0.���ݹ�˼Ӧ��Ϊ����ֲ�������ֵ��
		//�����ġ��Ѵ˴�intȥ���������������Ϊ5.
		if (arr[mid] < to_found) {
			left = mid + 1;
		}
		else if (arr[mid] > to_found) {
			right = mid - 1;
		}
		else {
			break;
		}
	}
	if (left <= right) {
		printf("%d\n", mid);
	}
	else {
		printf("%d\n", -1);
	}

	system("pause");
	return 0;
}





//��д���룬ģ���������볡������������������룬������ȷ��ʾ�ɹ������������ʾ���󡣿��Զ�����룬������Σ����ξ������˳�����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int i = 0;
	char password[1024] = "";
	for (i = 1; i <= 3; ++i) {
		printf("���������룺\n");
		scanf("%s", password);
		if (strcmp(password, "password") == 0)
			break;
	}
	if (i == 4) {
		printf("�����þ����˳���\n");
	}
	else {
		printf("��½�ɹ���\n");
	}
	system("pause");
	return 0;
}








//��д����Сд�ַ��������д�ַ�����д�ַ����Сд�ַ�����������ֲ����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	char input = 0;
	scanf("%c", &input);
	if (input >= 65 && input <= 90) {
		printf("%c\n", input + 32);
	}
	else if (input <= 122 && input >= 97) {
		printf("%c\n", input - 32);
	}
	else {
		printf("�������\n");
	}
	system("pause");
	return 0;
}

//���Ż�����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	while (1) {
		int c = getchar();
		if (c == EOF) {
			break;
		}
		if (c >= 'a'&&c <= 'z') {
			putchar(c - ('a' - 'A'));
		}
		else if (c >= 'A'&&c <= 'Z') {
			putchar(c + ('a' - 'A'));
		}
		else if (c >= '0'&&c <= '9') {
			continue;
		}
		else {
			putchar(c);
		}
	}
	system("pause");
	return 0;
}

//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��.
//����9�����9 * 9�ھ���.
//����12�����12 * 12�ĳ˷��ھ���
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int chengfa() {
	int hang = 0;
	scanf("%d", &hang);
	for (int i = 1; i <= hang; ++i) {
		for (int col = 1; col <= i; ++col) {
			printf("%d * %d = %d\t", i, col, i*col);
		}
		printf("\n");
	}
}
int main() {
	chengfa();
	system("pause");
	return 0;
}




//������������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int change(int* x, int* y) {
	int tmp = 0;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
int main() {
	int x = 1;
	int y = 2;
	printf("%d,%d", change(&x, &y));
	system("pause");
	return 0;
}



//[�Ż�]------------------------------------------------------------------ -
int swap(int *a, int *b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	int a = 20;
	int b = 10;
	swap(&a, &b);
	printf("a=%d b=%d", a, b);
	system("pause");
	return  0;
}




















//�ж�����
#include<stdio.h>
#include<stdlib.h>
int IsLeap(int x) {
	if (x % 4 == 0) {
		if (x % 100 == 0) {
			return 0;
		}
		return 1;
	}
	if (x % 400 == 0) {
		return 1;
	}
	return  0;
}
int main() {
	int year = 1997;
	printf("%d\n", IsLeap(year));
	return 0;
}




//�ж�����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int IsPrime(int x) {
	for (int i = 2; i < x; ++i) {
		if (x % i == 0) {
			return 0;
		}
	} return 1;
}
int main() {
	int a = 0;
	printf("������һ���������֣�\n");
	scanf("%d", &a);
	printf("%d\n", IsPrime(a));
	system("pause");
	return 0;
}


