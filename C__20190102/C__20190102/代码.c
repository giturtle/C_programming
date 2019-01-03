#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//编写函数fun，从传入的num个字符串中找出最长的一个字符串
//要求函数无返回值，通过形参指针max传回该串地址并在主函数中输出该字符串
void fun(char (*a)[80],int num,char **max) {
	int i;
	char *p = a[0];
	*max = p;
	for (i = 0; i < num; i++) {
		if (strlen(a[i]) > strlen(p)) {
			p = a[i];
		}
	}
	*max = p;
}

int main() {
	char ss[10][80], *ps;
	int i = 0, n;
	printf("请输入一些字符串：\n");
	gets(ss[i]);
	//**** 是输入结束标志
	while (!strcmp(ss[i], "****") == 0) {
		i++;
		gets(ss[i]);
	}
	n = i;
	fun(ss,n,&ps);
	printf("\nmax = %s\n", ps);
	system("pause");
	return 0;
}


//编写函数fun，在字符串str中找出ASCII码最大的字符，将放在第一个位置上，并将该字符前的元字符向后顺序移动
void fun(char *str) {
	int i = 0;
	char max = *str;
	char *p = str;
	while (str[i] != '\0') {
		if (str[i] > max) {
			max = str[i];
			p = str + i;
		}
		i++;
	}
	while (p > str){
		*p = *(p - 1);
		p--;
	}
	str[0] = max;
}
int main(){
	char str[80];
	gets(str);
	fun(str);
	printf("%s\n",str);
	system("pause");
	return 0;
}


//规定输入的字符串中只包含字母和*号，编写函数fun
//将字符串尾部连续的*全部删除，前面和中间的*号不要删除
void delete(char *str) {
	char *p = str;
	while (*p) {
		p++;
	}
	p--;
	while (*p) {
		if (*p == '*') {
			*p = '\0';
		}
		p--;
		if (*p != '*')
			break;
	}
}
int main() {
	char str[80];
	gets(str);
	delete(str);
	printf("%s", str);
	system("pause");
	return 0;
}


//编写函数fun，统计子串substr在主字符串str中出现的次数

//-> 正解
int fun(char *str, char *substr) {
	int i, j, k, num = 0;
	for (i = 0;i < str[i]; i++) {
		for (j = i, k = 0; substr[k] == str[j]; k++, j++) {
			if (substr[k + 1] == '\0') {
				num++;
				break;
			}
		}
	}
	return num;
}

int main() {
	char str[80], substr[80];
	printf("请输入主字符串:\n");
	gets(str);
	printf("请输入子串:\n");
	gets(substr);
	printf("主串中子串出现次数为:");
	printf("%d\n", fun(str, substr));
	system("pause");
	return 0;
}


//-> 我的错误：没有找到衡量字符串长度的方法,设定字符串最好不要用指针
int fun(char *sub, char *str,int size1,int size2) {
	int count = 0, i, num = 0;
	for (i = 0; i < size1 - 1; i++) {
		if (*str == *sub) {
			num++;
		}
		if (num == size2) {
			count++;
			num = 0;
		}
	}
	return count;
}

int main() {
	char* string = "lileihanmeimeimeiyouqian";
	char* substring = "mei";
	int size1 = sizeof(string) / sizeof(string[0]);
	int size2 = sizeof(substring) / sizeof(substring[0]);
	printf("%d\n", fun(substring, string, size1,size2));
	system("pause");
	return 0;
}