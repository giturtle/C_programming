#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//实现一个函数，可以左旋字符串中k个字符
//ABCD左旋1个字符得到BCDA
//ABCD左旋2个字符得到CDAB

//方法1
void left_rotate(char *str, int k) {
	while (k--) {
		//先保存首字符
		char temp = *str;
		char *cur = str;
		//字符向前挪动一个位置
		while (*(cur + 1)) {
			*cur = *(cur + 1);
			cur++;
		}
		//首字符放在字符串最后一个位置
		*cur = temp;
	}
}

//方法2
void reverse(char* left, char* right) {
	//字符区间的内容逆转
	while (left < right) {
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
void left_rotate2(char *str, int k) {
	//三次逆转
	//第一次逆转前k个字符
	reverse(str, str + k - 1);
	//第二次逆转剩余的字符
	reverse(str, str + strlen(str) - 1);
	//第三次整体逆转
	reverse(str, str + strlen(str) - 1);
}

int main() {
	//char* str = "ABCD"; 不可以这样定义，因为常量是不可以修改的
	char str[] = "ABCD";
	int k;
	scanf("%d", &k);
	printf("%s\n", str);
	left_rotate(str, k);
	printf("%s\n", str);
	left_rotate2(str, k);
	printf("%s\n", str);
	system("pause");
	return 0;
}


//有一个二位数组，数组的每行从左到右是递增的，每列从上到下是递增的
//在这样的数组中查找一个数字是否存在，时间复杂度小于O(N)
int find(int a[3][3], int row, int col, int key, int *px, int *py) {
	//从右上角开始搜索
	int x = 0;
	int y = col - 1;
	//到左下角搜索结束(从左下角开始等效，略微不同)
	while (x < row && y >= 0) {
		if (a[x][y] == key) {
			//标记索引
			*px = x;
			*py = y;
			return 1;//表示找到了！
		}
		else if (a[x][y] > key) {
			//向左搜索
			y--;
		}
		else {
			//向下搜索
			x++;
		}
	}
	//设置无效值
	*px = -1;
	*py = -1;
	return 0;
}

int main() {
	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int to_find;
	int px, py;
	scanf("%d", &to_find);
	if (find(a, 3, 3, to_find, &px, &py)) {
		printf("%d,%d\n", px, py);
	}
	else {
		printf("%d不存在\n", to_find);
	}
	system("pause");
	return 0;
}