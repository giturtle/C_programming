#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



//编写一个程序，将字符数组s2中的全部字符复制到字符数组s1中
//不要用strcpy函数，复制时，'\0'也要一并复制过去，'\0'后的字符不复制
int main() {
	char s1[20];
	char s2[20];
	gets(s2);
	int i = 0, j = 0;
	//while(s2[i] != '\0'){   //两个条件都可以，for和while可以互相转换
	for(;s2[i] != '\0';i++){
		s1[j++] = s2[i];
	}
	s1[j] = '\0';
	printf("复制后的si数组为:\n");
	puts(s1);
	system("pause");
	return 0;
}


//编程将两个字符串s1和s2比较
//若s1>s2，输出一个正数，若s1=s2，输出0，若s1<s2，输出一个负数
//不要使用strcpy函数，两个字符串用gets函数输入
//输出的整数或负数的绝对值应是相比较的两个字符串相应字符的ASCII码的差值
int main() {
	char s1[10];
	char s2[10];
	printf("请输入字符串s1:\n");
	gets(s1);
	printf("请输入字符串s2:\n");
	gets(s2);
	int i = 0;
	for (; s1[i] != '\0' && s1[i] != '\0'; i++) {
		if (s1[i] == s2[i]) {
			continue;
		}
		else
			printf("%d\n", s1[i] - s2[i]);
	}
	if (s1[i] == '\0' || s2[i] == '\0') {
		printf("%d\n", 0);
	}
	system("pause");
	return 0;
}


//编写一个程序，将两个字符串连接起来，不要用strcat函数
int main() {
	char arr1[20] = "i am";
	char arr2[10] = " Tom!";
	int j = 0;
	int i = 0;
	while (arr1[i] != '\0') {
		arr1[j++] = arr1[i++];
	}
	i = 0;
	while(arr2[i]!= '\0'){
		arr1[j++] = arr2[i++];
	}
	arr1[j] = '\0';
	puts(arr1);
	system("pause");
	return 0;
}