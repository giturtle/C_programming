#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



//有一行电文，已按下面规律译成密码
//A → Z ，B → Y， C → X
//a → z ，b → y， c → x
//即第一个字母变成了第26个字母，第i个字母变成了第（26-i+1）个字母，非字母字符不变，要求编程将密码译回原文，并输出密码和原文
int main() {
	char arr[20];
	int i = 0;
	printf("请输入密码:\n");
	gets(arr);
	printf("\n\n============\n");
	printf("密文为:\n");
	puts(arr);
	for (; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
		if (arr[i] >= 'a' && arr[i] <= 'z')
			arr[i] = 27 - (arr[i] - 96) + 96;
		if (arr[i] >= 'A' && arr[i] <= 'Z')
			arr[i] = 27 - (arr[i] - 64) + 64;
	}
	printf("\n密码原文为：\n");
	puts(arr);
	printf("============\n\n");
	system("pause");
	return 0;
}


//有15个数按由小到大顺序存放在一个数组中，输入一个数
//要求用折半查找法找出该数是数组中第几个元素的值，如果不在数组中输出“无此数”
int main() {
	int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int to_found, mid;
	printf("请输入要查找的值:\n");
	scanf("%d", &to_found);
	int left = 0;
	int right = (sizeof(arr) / sizeof(arr[0])) - 1;
	//while(left < right){
	//不可以使用这个while语句
	for(int i = 0; i < sizeof(arr) / sizeof(arr[0]);i++){
		//这里判定条件不可以写 < right，因为right值在变化
		mid = (left + right) / 2;
		if (to_found < arr[mid]) {
			right = mid - 1;
		}
		else if (to_found > arr[mid]) {
			left = mid + 1;
		}
		else {
			break;
		}
	}
	if (left <= right) {
		printf("找到了！下标为%d\n", mid);
	}
	else {
		printf("无此数\n");
	}
	system("pause");
	return 0;
}


//找出一个二维数组中的鞍点，该位置的元素在该行最大，在该列最小，也可能没有鞍点
#define M 100
#define N 100
int main() {
	int m, n;
	int arr[M][N];
	int row, col;
	int flag = 0;//鞍点等于0表示 没有鞍点
	printf("请输入矩阵的行数m与列数n:\n");
	scanf("%d %d", &m, &n);
	printf("请输入%d行 %d列的矩阵:\n", m, n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &arr[i][j]);
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

//我的错误：
#define N 3
int main() {
	int arr[N][N];
	int i = 0, j = 0, max, min, m, n;
	printf("输入二维数组中的元素:\n");
	for (; j < N; i++) {
		for (; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0; i < N; i++) {
		for (max = arr[i][j], m = 0, n = j = 0; j < N; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
				m = i;
				n = j;
			}
		}
		for (min = arr[m][n], j = 0; j < N; j++) {
			if (arr[j][n] < min)
				break;
			else {
				continue;
			}
		}
		if (j + 1 == N) {
			printf("鞍点为%d，下标是%d行%d列\n", arr[m][n], m, n);
		}
	}
	system("pause");
	return 0;
}


//输入魔方阵，所谓魔方阵是指这样的方阵，他的每一行、每一列和对角线之和均相等
//例如：
// 8  1  6
// 3  5  7
// 4  9  2
//要求输出1 ~ n^2的自然数构成的魔方阵

//  【魔方阵】    排列规则：
//⑴将1放在第一行中间一列；
//⑵从2开始直到n×n止各数依次按下列规则存放；每一个数存放的行比前一个数的行数减1，列数加1（例如上面的三阶魔方阵，5在4的上一行后一列）；
//⑶如果上一个数的行数为1，则下一个数的行数为n（指最下一行）；例如1在第一行，则2应放在最下一行，列数同样加1；
//⑷当上一个数的列数为n时，下一个数的列数应为1，行数减去1。例如2在第3行最后一列，则3应放在第二行第一列；
//⑸如果按上面规则确定的位置上已有数，或上一个数是第一行第n列时，则把下一个数放在上一个数的下面。例如按上面的规定，4应该放在第1行第2列，但该位置已经被占据，所以4就放在3的下面。

//①
#define N 100
int main(){
	int a[N][N], i, j, n, m, x, y;
	//二维数组的初始化不像一维数组一样直接设置全 0 
	//而是使用循环遍历赋值
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			a[i][j] = 0;
		}
	}
	printf("请输入魔方阶数n (n<100):");//输入奇数
	//输入偶数 结果不正确.
	scanf("%d", &n);


	//主逻辑开始
	i = 0, j = n / 2;
	//将 1 放在第一行中间
	a[i][j] = 1;
	//然后从 2 开始放
	for (m = 2; m <= n * n; m++){
		//x、y用来保存上一个数的下标
		x = i;  
		y = j;
		i = (i - 1 + n) % n;
		j = (j + 1) % n;
		if (a[i][j] == 0){	//如果此时为0，说明没有被放过值，直接放入
			a[i][j] = m;
		}
		else{
			a[++x][y] = m;	//否则放在前一个数的下面，即行数 +1
			i = x;
			j = y;
		}
	}

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%-3d", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


//②20+行简化函数体
#define ROW 10
void MagicSqaure(int(*arr)[ROW])
{
	assert(ROW % 2 != 0);
	arr[0][ROW / 2] = 1;

	int preRow = 0;
	int preCol = ROW / 2;

	for (int i = 2; i <= ROW * ROW; i++)
	{
		if (arr[(preRow - 1 + ROW) % ROW][(preCol + 1) % ROW] != 0)
		{
			preRow = (preRow + 1) % ROW;
		}
		else
		{
			preRow = (preRow - 1 + ROW) % ROW;
			preCol = (preCol + 1) % ROW;
		}
		arr[preRow][preCol] = i;
	}
}


//输出10行杨辉三角
//1
//1 1
//1 2 1
//1 3 3 1
//...
int main() {
	int arr[10][10];
	int i, j;
	for (i = 0; i < 10; i++) {
		arr[i][i] = 1;
		arr[i][0] = 1;
	}
	for (i = 2; i < 10; i++) {
		for (j = 1; j < i; j++) {	
			//这里j要小于i，如果 <= i，就会把设好的a[i][i]值重置
			//结果会是随机值，因为a[i-1][j]这个值在上一行是越界的
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j <= i; j++) {
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}



//将一个数组中的值按照逆序重新存放
//例如，原来顺序为8,6,5,4,1 ， 要求改为1,4,5,6,8
#define num 6
//要想更改宏定义数字，需要与main函数中的数组元素个数对应
int main() {
	int arr[num] = { 8,6,5,4,1,3 };
	int temp = 0;
	for (int i = 0; i < num / 2; i++) {
		int j = (num - 1) - i;
		temp = arr[i];
		arr[i]= arr[j];
		arr[j] = temp;
	}
	for (int i = 0; i < num; i++) {
		printf("%3d", arr[i]);
	}
	system("pause");
	return 0;
}
