#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//��Ҫ�úô�Ħ,���˼��
//��������һ������n(1<= n <= 20) ��ӡ n �� n ��������ת����
//����,��n = 4,�����:
//1 12 11 10
//2 13 16  9
//3 14 15  8
//4  5  6  7
int main() {
	int arr[20][20];
	int i, j, row, col, n, dir_i;
	struct directory {
		int x, y;
	}dir[4] = {{ 1,0 }, { 0,1 }, { -1,0 }, { 0,-1 }
};
	printf("������һ��С��20��������:\n");
	scanf("%d", &n);
	for (i = 1; dir_i = 0, row = col = 0; i <= n * n; i++) {
		arr[row][col] = i;
		row += dir[dir_i].x;
		col += dir[dir_i].y;
		if (row < 0 || col < 0 || row >= n || col >= n || a[row][col] != 0) {
			���ڻ���a[row][col]������0
			row -= dir[dir_i].x;
			col -= dir[dir_i].y;
			dir_i++;
			if (dir_i == 4) {
				dir_i = 0;
			}
			row += dir[dir_i].x;
			col += dir[dir_i].y;
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

//�ҳ�һ����ά�����еİ���
//����:��λ���ϵ�Ԫ���ڸ������,�ڸ�����С,�п���û�а���
#define M 100
#define N 100
int main() {
	int m , n ;
	int arr[M][N];
	int row, col;
	int flag = 0;//�������0��ʾ û�а���
	printf("��������������m������n:\n");
	scanf("%d %d", &m, &n);
	printf("������%d�� %d�еľ���:\n", m, n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%5d", &arr[i][j]);
		}
	}
	for (int i = 0; i < m; ++i) {
		//���ҳ��� i �����Ԫ�� a[i][col]
		col = 0;
		for (int j = 1; j < n; ++j) {
			if (arr[i][j] > arr[i][col]) {
				col = j;
			}
		}
		//�ҳ���col����СԪ�� a[row][col];
		row = 0;
		for (int j = 1; j < n; ++j) {
			if (arr[row][col] > arr[j][col]) {
				row = j;
			}
		}
		//��������Ԫ���ڵ�row��,���row����i,�������ǰ���
		if (row == i) {
			flag = 1;
			printf("����������±���:%d,%d\n����ֵ��:%d\n", row, col, arr[row][col]);
		}
	}
	if (!flag) {
		printf("û�а���!\n");
	}
	system("pause");
	return 0;
}



//����һ��3 �� 4 ��ʵ������ a ,��һ��4 �� 2 ��ʵ������ b 
//����������Ļ� c = a �� b 
//c�и�Ԫ�ر���2λС��,����λС����������
int main() {
	double a[3][4],b[4][2];
	double c[3][2];
	int i, j, k;
	double temp;
	printf("����a�����Ԫ��:\n");
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; ++j) {
			scanf("%lf", &temp);
			a[i][j] = temp;
		}
	}
	printf("����b�����Ԫ��:\n");
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 2; ++j) {
			scanf("%lf", &temp);
			b[i][j] = temp;

		}
	}
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 2; ++j) {
			for (k = 0; k < 4; ++k) {
				c[i][j] = a[i][k] * b[k][j];
			}
		}
	}
	printf("������ĳ˻���:\n");
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 2; ++j) {
			c[i][j] = ((int)(c[i][j] * 100 + 0.5)) / 100.0;
			//����������˸�Ԫ�ر���2λС��
			//����λ������������ͨ������0.5,����0.5����ȥ,���˾ͻ�ӵ���1������,ģ������������
			printf("%10.2f\n", c[i][j]);
		}
	}
	system("pause");
	return 0;
}