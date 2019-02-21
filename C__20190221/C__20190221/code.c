#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//从键盘读入若干的字符串，对他们按照字母大小的顺序排序，然后把排好序的字符串送到磁盘文件中保存
int main() {
	FILE *fp;
	char str[3][10], temp[10];
	int i, j, k;
	int n = 3;
	printf("请输入字符串:\n");
	for (i = 0; i < n; ++i) {
		gets(str[i]);
	}
	for (i = 0; i < n - 1; ++i) {
		k = i;
		for (j = i + 1; j < n; ++j) {
			if (strcmp(str[k], str[j]) > 0)
				k = j;
		}
		if (k != i) {
			strcpy(temp, str[i]);
			strcpy(str[i],str[k]);
			strcpy(str[k],temp);
		}
	}
	if ((fp = fopen("D:\\CC\\string.dat", "w")) == NULL) {
		printf("can't open this file!\n");
		exit(0);
	}
	printf("\n the new sequence:\n");
	for (i = 0; i < 3; ++i) {
		fputs(str[i], fp);
		fputs("\n", fp);
		printf("%s\n", str[i]);
	}
	system("pause");
	return 0;
}


//将一个磁盘文件中的信息复制到另一个磁盘文件中，今要求将下题file1.dat文件中的内容复制到另一个磁盘文件file2.dat中
int main() {
	FILE *in, *out;
	char ch, infile[10], outfile[10];
	printf("输入读入文件的名字:");
	scanf("%s", infile);
	printf("输入输出文件的名字:");
	scanf("%s", outfile);
	if ((in = fopen(infile, "r")) == NULL) {
		printf("无法打开文件!\n");
		exit(0);
	}
	if ((out = fopen(outfile, "w")) == NULL) {
		printf("无法打开文件!\n");
		exit(0);
	}
	while (!feof(in)) {		//如果未遇到输入文件的结束标志
		ch = fgetc(in);		//从输入文件读入一个字符，暂放在变量ch中
		fputc(ch, out);		//将ch写到输出文件中
		putchar(ch);		//将ch显示在屏幕上
	}
	putchar(10);
	fclose(in);
	fclose(out);
	system("pause");
	return 0;
}


//从键盘输入一些字符，逐个把他们送到磁盘上去，指导用户输入一个"#"为止
int main() {
	FILE *fp;
	char filename[20], ch;
	printf("请输入所用的文件名:\n");
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("无法打开此文件!\n");
		exit(0);
	}
	ch = getchar();
	printf("请输入一个准备储存到磁盘的字符串(以#结尾):\n");
	ch = getchar();
	while (ch != '#') {
		fputc(ch, fp);
		putchar(ch);
		ch = getchar();
	}
	fclose(fp);
	putchar(10);
	system("pause");
	return 0;
}
