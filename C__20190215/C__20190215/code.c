#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


//编写一个函数new，对n个字符开辟连续空间，此函数应返回一个指针，指向字符串开始的空间
//new(n)表示分配n个字节的内存空间


//方法一
char *new(size_t n){
	char *a = (char*)malloc(n*sizeof(char));
	return a;
}
int main() {
	int a;
	scanf("%d", &a);
	char *n = new(a);
	scanf("%s", n);
	//不能用gets(n);
	puts(n);
	system("pause");
	return 0;
}


//方法二
char *news(char *s[], int n) {
	for (int i = 0; i < n; s[i++] = (char *)malloc(20 * sizeof(char)));
	return *s;
}
int main(){
	char *str[10], **p;
	int i;
	printf("输入数组个数: ");
	scanf("%d", &i);
	*str = news(str, i);
	for (p = str, printf("输入%d个字符串: ", i); p < str + i; scanf("%s", *p++));
	for (p = str, printf("结果为: "); p < str + i; printf("%s ", *p++));
	system("pause");
	printf("\n");
	return 0;
}





//编写一程序，输入月份号，输出该月的英文月名。例如输入3，输出march，用指针数组处理
int main() {
	char *arr[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December" 
	};
	int month;
	printf("请输入月份号：\n");
	scanf("%d", &month);
	printf("%s\n", arr[month - 1]);
	system("pause");
	return 0;
}


//写一函数，实现两个字符串的比较。即自己写一个strcmp函数
int Strcmp(char *p1, char *p2) {
	while (*p1 && (*p1 == *p2)) {
		p1++;
		p2++;
	}
	return *p1 - *p2;
}
int main() {
	char *str1 = "h";
	char *str2 = "haha";
	printf("%d\n", Strcmp(str1, str2));
	system("pause");
	return 0;
}



//输入一个字符串，内有数字和非数字字符，将其中连续的数组作为一个整数，依次存放到一数组a中，统计共有多少整数并输出
void Count(char *s){
	int a[10],i = 0, j,num, t = 0; //i为数组a的下标，num是判断是否是数字，t是最终的整数
	char *p;
	for (p = s; *p != '\0'; p++) {
		if (*p >= '0' && *p <= '9') {
			num = 1;	//是数字
			t = t * 10 + (*p - '0');
		}
		else if (num == 1) {
			num = 0;	//这一位不是数字
			a[i++] = t;
			t = 0;
		}
		if (*p >= '0' && *p <= '9' && p[1] == '\0') {   
			//此条件是判断字符串末尾是数字的情况下加入一个字符，避免最后一个整数没有录入就跳出循环
			p[2] = '\0';
			p[1] = 'a';
		}
	}
	j = i;
	printf("\n字符串中共有%d个数字。\n", j);
	printf("分别为：\n");
	for (i = 0; i < j; i++) {
		printf("%d ", a[i]);
		printf("\n");
	}
}
int main() {
	char str[50];
	printf("输入字符串:\n");
	gets(str);
	Count(str);
	system("pause");
	return 0;
}



int main() {
	union IP {
		uint32_t a;
		struct {		//匿名结构体
			char d1;
			char d2;
			char d3;
			char d4;
		}b;
	}ip;
	ip.a = 0x1;
	printf("%d.%d.%d.%d\n", ip.b.d1, ip.b.d2, ip.b.d3, ip.b.d4);
	system("pause");
	return 0;
}


union Un1{
	char c[5];
	int i;
};
union Un2{
	short c[7];
	int i;
};
int main() {
	printf("%d\n", sizeof(union Un1));	//8
	printf("%d\n", sizeof(union Un2));	//16
	system("pause");
	return 0;
}


//字节序验证
int Little() {
	int a = 0x11223344;
	char *b = (char*)&a;
	if (*b == 0x11) {
		return 0;
	}
	return 1;
}
//使用联合体
int little() {
	union Un {
		char a;
		int b;
	}u;
	u.b = 0x11223344;
	if (u.a == 0x11) {
		return 0;
	}
	return 1;
}



union Un {
	char c;
	int i;	
};
struct S {
	char c;
	int i;
};
int main() {
	union Un u;
	struct S s;
	printf("%lu\n", sizeof(u));
	printf("%lu\n", sizeof(s));

	system("pause");
	return 0;
}



enum Color{
	red = 1,
	green = 4,
	blue = 5,
};
int main() {
	enum Color c = green;
	c = 4;
	system("pause");
	return 0;
}