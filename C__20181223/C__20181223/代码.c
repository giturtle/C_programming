#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//对于一个二维数组,用函数求出某行中最大值,也可求某列上最小值
//每个最大值放在一个数组中,然后在这个数组中求出最大值
#define M 5
#define N 5
int maxi(int c[], int d, int e) {
	int j, max;
	max = c[d][0];
	for (j = 0; j < e; j++) {
		if (c[d][j] > max) {
			max = c[d][j];
		}
	}
	return max;
}
int maxj(int c[], int e) {
	int i, max;
	max = c[0];
	for (i = 0; i < e; ++i) {
		if (c[i] > max) {
			max = c[i];
		}
	}
	return max;
}
int main() {
	int a[M][N],b[N];
	int m, n, i, j;
	printf("请输入行数:\n");
	scanf("%d", &m);
	printf("请输入列数:\n");
	scanf("%d", &n);
	printf("请输入数据:\n");
	for (i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; ++i) {
		b[i] = maxi(a, i, m);
	}
	printf("%d")
	system("pause");
	return 0;
}



//用一个函数来实现使主函数输入的一个字符串按反序存放
//在主函数中进行输入和输出字符串

//-------方案 1 ---------
void reverse(char* str) {
	char temp;
	char* start = str;
	char* end = str + strlen(str) - 1;
	while (start < end) {
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
int main() {
	char str[100];
	printf("输入字符串:\n");
	scanf("%s", &str);
	reverse(str);
	printf("逆序之后的字符串为:%s\n", str);
	system("pause");
	return 0;
}

//------- 方案 2 --------
void reverse_2(char str[]) {
	unsigned i, j;
	char temp;
	for (i = 0, j = strlen(str); i < strlen(str) / 2; i++, j--) {
		temp = str[i];
		str[i] = str[j - 1];
		str[j - 1] = temp;
	}
}
int main() {
	char str[100];
	printf("输入字符串:\n");
	scanf("%s", &str);
	reverse_2(str);
	printf("逆序之后的字符串为:%s\n", str);
	system("pause");
	return 0;
}


//(形参与实参 还要深入理解!)   (未完成)
//将两个字符串连接起来,不要用strcat函数
int main() {
	void my_strcat(char a[], char b[]);
	char a1[100], a2[100];
	printf("请输入第一个字符串:\n");
	scanf("%s", &a1);
	printf("请输入第二个字符串:\n");
	scanf("%s", &a2);
	my_strcat(a1, a2);
	printf("%s", a1);
	system("pause");
	return 0;
}
void my_strcat(char a[],char b[]) {
	int i = 0, j = 0;
	while (a[i] != '\0')	i++;
	while (b[j] != '\0')	a[i++] =b[j++];
	a[j] = '\0';
}



//函数程序设计的方法计算10名学生1门课成绩的平均分
double avg(double grade[]) {
	int i; double average, sum = grade[0];
	for (i = 1; i < 10; i++) {
		sum += grade[i];
	}
	average = sum / 10;
	return average;
}
int main() {
	double score[10], average;
	int i;
	printf("请输入10名学生的成绩:\n");
	for (i = 0; i < 10; i++) {
		scanf("%lf", &score[i]);
	}
	average = avg(score);
	printf("\n平均成绩为:%5.2lf\n", average);
	system("pause");
	return 0;
}