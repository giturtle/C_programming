#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



//有一篇文章,共有 3 行文字,每行有 80 个字符.
//要求分别统计出其中英文大写字母,小写字母,数字,空格以及其他字符的个数
#define M 3
#define N 80
int main() {
	char a[M][N];
	int dxzm, xxzm, sz, kg, other;
	dxzm = xxzm = sz = kg = other = 0;//计数器
	for (int i = 0; i < 3; ++i) { //每一行
		printf("请输入第%d行数据:\n", i + 1);
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
	printf("小写字母有:%3d个\n", xxzm);
	printf("大写字母有:%3d个\n", dxzm);
	printf("数字有:%3d个\n", sz);
	printf("空格有:%3d个\n", kg);
	printf("其他字符有:%3d个\n", other);

	system("pause");
	return 0;
}



//有15个数按由大到小的顺序存放在一个数组中,输入一个数,
//要求用折半查找的方法找出该数是数组中第几个元素的值
//如果不在该数组中,则打印出无此数
int main() {
	int i,left, right, mid, num;
	int a[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	printf("请输入要查找的数字:\n");
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
	//以上代码同样可以实现查找,和下面代码等效
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
		printf("找到了,他在数组中的下标为%d\n", mid);
	}
	else {
		printf("没找到!\n");
	}
	system("pause");
	return 0;
}



//打印杨辉三角形,要求打印10行
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