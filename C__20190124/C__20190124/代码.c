#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



//【递归版本】
//有一个二位数组，数组的每行从左到右是递增的，每列从上到下是递增的
//在这样的数组中查找一个数字是否存在，时间复杂度小于O(N)

//从左下角开始搜索
int find_r(int a[3][3], int row, int col, int x, int y, int key, int* px, int* py) {
	//找到右上角还没有找到,搜索结束
	if (x < 0 || y >= col)
		return -1;
	//key > a[x][y]时，向右搜索
	if (key > a[x][y]) {
		return find_r(a, row, col, x, ++y, key, px, py);
	}
	//key < a[x][y]时，向上搜索
	else if (key < a[x][y]) {
		return find_r(a, row, col, --x, y, key, px, py);
	}
	else if (key == a[x][y]) {
		*px = x;
		*py = y;
		return 1;
	}
}

int main() {
	int a[3][3] = {1,2,3,4,5,6,7,8,9};
	int row, col;
	printf("输入行、列数:\n");
	scanf("%d %d", &row, &col);
	int px, py;
	printf("输入索引值:\n");
	int key;
	scanf("%d", &key);
	//左下角
	if (find_r(a, row, col, row-1, 0, key, &px, &py)) {	//row - 1，0相当于起始点，左下角
		printf("%d,%d\n", px, py);
	}
	else {
		printf("%d不存在\n",key);
	}
	system("pause");
	return 0;
}