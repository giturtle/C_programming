#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



//��һƪ����,���� 3 ������,ÿ���� 80 ���ַ�.
//Ҫ��ֱ�ͳ�Ƴ�����Ӣ�Ĵ�д��ĸ,Сд��ĸ,����,�ո��Լ������ַ��ĸ���
#define M 3
#define N 80
int main() {
	char a[M][N];
	int dxzm, xxzm, sz, kg, other;
	dxzm = xxzm = sz = kg = other = 0;//������
	for (int i = 0; i < 3; ++i) { //ÿһ��
		printf("�������%d������:\n", i + 1);
		gets(a[i]);
		for (int j = 0; j < N && a[i][j] != '\0';j++) {
			if (a[i][j] >= 'A' && a[i][j] <= 'Z') {
				dxzm++;
			}
			else if (a[i][j] >= 'a' && a[i][j] <= 'z') {
				xxzm++;
			}
			else if (a[i][j] >= '0' && a[i][j] <= '9') {
				sz++;
			}
			else if (a[i][j] == ' ') {
				kg++;
			}
			else {
				other++;
			}
		}
	}
	printf("Сд��ĸ��:%3d��\n", xxzm);
	printf("��д��ĸ��:%3d��\n", dxzm);
	printf("������:%3d��\n", sz);
	printf("�ո���:%3d��\n", kg);
	printf("�����ַ���:%3d��\n", other);

	system("pause");
	return 0;
}



//��15�������ɴ�С��˳������һ��������,����һ����,
//Ҫ�����۰���ҵķ����ҳ������������еڼ���Ԫ�ص�ֵ
//������ڸ�������,���ӡ���޴���
int main() {
	int i,left, right, mid, num;
	int a[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	printf("������Ҫ���ҵ�����:\n");
	scanf("%d", &num);
	left = 0;
	right = sizeof(a) / sizeof(a[0]) - 1;
	/*for (i = 0; i <= right; ++i) {
		mid = (left + right) / 2;
		if (num > a[mid]) {
			left = mid + 1;
		}
		else if (num < a[mid]) {
			right = mid - 1;
		}
		else {
			break;
		}
	}*/
	//���ϴ���ͬ������ʵ�ֲ���,����������Ч
	while (left <= right) {
		mid = (left + right) / 2;
		if (num > a[mid]) {
			left = mid + 1;
		}
		else if (num < a[mid]) {
			right = mid - 1;
		}
		else {
			break;
		}
	}
	if (left <= right ) {
		printf("�ҵ���,���������е��±�Ϊ%d\n", mid);
	}
	else {
		printf("û�ҵ�!\n");
	}
	system("pause");
	return 0;
}



//��ӡ���������,Ҫ���ӡ10��
//1
//1 1
//1 2 1
//1 3 3 1
//1 3 6 4 1
//1 5 10 10 5 1
#define N 10
int main() {
	int i, j, a[N][N];
	for (i = 0; i < N; ++i) {
		a[i][0] = 1;
		a[i][i] = 1;
	}
	for (i = 2; i < N; ++i) {
		for (j = 1; j < i; ++j) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < N; ++i) {
		for (j = 0; j <= i; ++j) {
			printf("%4d ", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}