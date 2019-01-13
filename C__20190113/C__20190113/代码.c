#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//两个班，每班10个同学，求平均成绩
double average(double score[]) {
	double sum = score[0];
	double avg;
	for (int i = 1; i < 10; i++) {
		sum += score[i];
	}
	avg = sum / 10;
	return avg;
}

int main() {
	double arr[2][10];
	printf("请分别输入两个班，10个学生的成绩:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%lf", &arr[i][j]);
		}
	}
	for (int i = 0; i < 2; i++) {
		printf("\n%d班平均成绩为：%5.2lf\n", i+1,average(arr[i]));
	}
	system("pause");
	return 0;
}


//有一个一维数组score，内存放10个学生成绩，求平均值
double average(double score[]) {
	double sum = score[0];
	double avg;
	for (int i = 1; i < 10; i++) {
		sum += score[i];
	}
	avg = sum / 10;
	return avg;
}

int main() {
	double arr[10];
	printf("请分别输入10个学生的成绩:\n");
	for (int i = 0; i < 10; i++) {
		scanf("%lf", &arr[i]);
	}
	printf("\n平均成绩为：%5.2lf\n", average(arr));
	system("pause");
	return 0;
}
