#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//判断一个字符串是否是另一个字符串翻转之后的字符串
//s1 = AABCD , s2 = BCDAA 返回1
//s1 = abcd ， s2 = ABCD 返回0
int is_rotate(char* dest, char* src) {		//需要下题中的右旋函数
	void right_rotate(char* str, int k);
	if (strlen(dest) != strlen(src)) {
		return 0;
	}
	int len = strlen(src);
	while (len--) {
		right_rotate(src, 1);
		if (strcmp(dest, src) == 0) {
			return 1;
		}
	}
	return 0;
}
int main() {
	char dest[100];
	char src[100];
	scanf("%s", dest);
	scanf("%s", src);
	printf("%d\n", is_rotate(dest, src));
	system("pause");
	return 0;
}



//ABCD --> 右旋1次 -->DABC 相当于 左旋3次
//右旋K次 --> 左旋strlen(str) - k次
void reverse(char* left, char* right) {
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_rotate(char* str, int k) {
	//三次逆转
	//第一次翻转前k个字符
	reverse(str, str + k - 1);
	//第二次翻转剩下的字符
	reverse(str + k, str + strlen(str) - 1);
	//第三次整体翻转
	reverse(str, str + strlen(str) - 1);
}
void right_rotate(char* str, int k) {
	left_rotate(str, strlen(str) - k);
}

int main() {
	char str[] = "ABCDEF";
	int k;
	scanf("%d", &k);
	printf("%s\n", str);
	left_rotate(str, k);
	printf("%s\n", str);
	right_rotate(str, k);
	printf("%s\n", str);
	system("pause");
	return 0;
}



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