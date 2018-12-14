#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//需要好好揣摩,多次思考
//键盘输入一正整数n(1<= n <= 20) 打印 n × n 阶右手旋转方阵
//例如,若n = 4,则输出:
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
	printf("请输入一个小于20的正整数:\n");
	scanf("%d", &n);
	for (i = 1; dir_i = 0, row = col = 0; i <= n * n; i++) {
		arr[row][col] = i;
		row += dir[dir_i].x;
		col += dir[dir_i].y;
		if (row < 0 || col < 0 || row >= n || col >= n || a[row][col] != 0) {
			碰壁或者a[row][col]不等于0
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

//找出一个二维数组中的鞍点
//鞍点:该位置上的元素在该行最大,在该列最小,有可能没有鞍点
#define M 100
#define N 100
int main() {
	int m , n ;
	int arr[M][N];
	int row, col;
	int flag = 0;//鞍点等于0表示 没有鞍点
	printf("请输入矩阵的行数m与列数n:\n");
	scanf("%d %d", &m, &n);
	printf("请输入%d行 %d列的矩阵:\n", m, n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%5d", &arr[i][j]);
		}
	}
	for (int i = 0; i < m; ++i) {
		//先找出第 i 行最大元素 a[i][col]
		col = 0;
		for (int j = 1; j < n; ++j) {
			if (arr[i][j] > arr[i][col]) {
				col = j;
			}
		}
		//找出第col列最小元素 a[row][col];
		row = 0;
		for (int j = 1; j < n; ++j) {
			if (arr[row][col] > arr[j][col]) {
				row = j;
			}
		}
		//该列最大的元素在第row行,如果row等于i,则它就是鞍点
		if (row == i) {
			flag = 1;
			printf("鞍点的数组下标是:%d,%d\n它的值是:%d\n", row, col, arr[row][col]);
		}
	}
	if (!flag) {
		printf("没有鞍点!\n");
	}
	system("pause");
	return 0;
}



//输入一个3 × 4 的实数矩阵 a ,和一个4 × 2 的实数矩阵 b 
//计算两矩阵的积 c = a × b 
//c中各元素保留2位小数,第三位小数四舍五入
int main() {
	double a[3][4],b[4][2];
	double c[3][2];
	int i, j, k;
	double temp;
	printf("输入a矩阵的元素:\n");
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; ++j) {
			scanf("%lf", &temp);
			a[i][j] = temp;
		}
	}
	printf("输入b矩阵的元素:\n");
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
	printf("两矩阵的乘积是:\n");
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 2; ++j) {
			c[i][j] = ((int)(c[i][j] * 100 + 0.5)) / 100.0;
			//这个语句完成了各元素保留2位小数
			//第三位的四舍五入是通过加上0.5,不到0.5就舍去,到了就会加到大1的数字,模拟了四舍五入
			printf("%10.2f\n", c[i][j]);
		}
	}
	system("pause");
	return 0;
}