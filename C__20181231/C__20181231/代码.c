#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//编写函数fun，将s所指向字符串的正序和逆序进行连接，形成的新串放在t数组中
void fun(char s[],char t[]) {
	int i, d;
	d = strlen(s);
	for (i = 0; i < d; i++) {
		t[i] = s[i];
	}
	for (i = 0; i < d; i++) {
		t[d+i] = s[d-1-i];
	}
	t[2 * d] = '\0';
}

int main() {
	char s[40], t[80];
	printf("输入字符串：\n");
	scanf("%s", s);
	fun(s, t);
	printf("%s\n", t);
	system("pause");
	return 0;
}


//编写程序fun，函数的功能是：从字符串中删除指定的字符，同一字符大小写按不同字符处理

//方案一
void fun(char s[], char c) {
	int i = 0; char *p;
	p = s;
	while (*p) {
		if (*p != c) {
			s[i] = *p;
			i++;
		}
		p++;
	}
	s[i] = '\0';
}

//方案二
void fun2(char s[], char c) {
	int i, j;
	for (i = j = 0; *(s + i); i++) {
		if (s[i] != c) {
			s[j++] = s[i];
		}
		s[j] = '\0';
	}
}

int main() {
	static char str[] = "my name is hanmeimei";
	char ch;
	printf("原字符串为：%s\n", str);
	printf("请输入一个字符：\n");
	scanf("%c", &ch);
	//getch(ch);
	//fun(str, ch);
	fun2(str, ch);
	printf("新字符串为：%s\n", str);
	system("pause");
	return 0;
}