//折半查找有序数组中想要的数字，返回数字下标#include<stdio.h>
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
		//本人错误点：此处如果是int mid，声明了局部变量，生命周期只在循环花括号内.
		//下面蓝色阴影中的mid即为全局变量，运行结果为0.根据构思应该为这个局部变量的值。
		//【更改】把此处int去掉运行正常。结果为5.
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





//编写代码，模拟密码输入场景，最多输入三次密码，密码正确提示成功，密码错误提示错误。可以多次输入，最多三次，三次均错则退出程序。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int i = 0;
	char password[1024] = "";
	for (i = 1; i <= 3; ++i) {
		printf("请输入密码：\n");
		scanf("%s", password);
		if (strcmp(password, "password") == 0)
			break;
	}
	if (i == 4) {
		printf("次数用尽，退出！\n");
	}
	else {
		printf("登陆成功！\n");
	}
	system("pause");
	return 0;
}








//编写程序，小写字符就输出大写字符，大写字符输出小写字符，如果是数字不输出
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
		printf("输出错误。\n");
	}
	system("pause");
	return 0;
}

//【优化】：
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

//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定.
//输入9，输出9 * 9口诀表.
//输入12，输出12 * 12的乘法口诀表。
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




//交换两个整数
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



//[优化]------------------------------------------------------------------ -
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




















//判断闰年
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




//判断素数
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
	printf("请输入一个整形数字：\n");
	scanf("%d", &a);
	printf("%d\n", IsPrime(a));
	system("pause");
	return 0;
}


