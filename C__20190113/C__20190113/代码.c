#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�����࣬ÿ��10��ͬѧ����ƽ���ɼ�
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
	printf("��ֱ����������࣬10��ѧ���ĳɼ�:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%lf", &arr[i][j]);
		}
	}
	for (int i = 0; i < 2; i++) {
		printf("\n%d��ƽ���ɼ�Ϊ��%5.2lf\n", i+1,average(arr[i]));
	}
	system("pause");
	return 0;
}


//��һ��һά����score���ڴ��10��ѧ���ɼ�����ƽ��ֵ
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
	printf("��ֱ�����10��ѧ���ĳɼ�:\n");
	for (int i = 0; i < 10; i++) {
		scanf("%lf", &arr[i]);
	}
	printf("\nƽ���ɼ�Ϊ��%5.2lf\n", average(arr));
	system("pause");
	return 0;
}
