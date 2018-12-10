#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
改进之前练习部分代码

//调整数组使奇数全部都位于偶数前面
//实现一个函数,所有奇数位于数组前半部分,偶数后半部分
//从头找一个偶数出来
//从尾找一个奇数出来
//交换二者位置
//头指针++,尾指针--

void reverse_array(int a[], int n) {
	int left = 0;
	int right = n - 1;
	while (left < right) {
		//从左向右找第一个偶数
		while (left < right && a[left] % 2 != 0) {
			left++;
		}
		//从右向左找第一个奇数
		while (left < right && a[right] % 2 == 0) {
			right--;
		}
		//异或操作 交换奇偶值
		if (left < right) {
			a[left] = a[left] ^ a[right];
			a[right] = a[left] ^ a[right];
			a[left] = a[left] ^ a[right];
		}
	}
}
int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	reverse_array(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}



//有一个字符数组的内容为:"student a am i", 
//请你将数组的内容改为"i am a student". 
//要求:
//1.不能使用库函数,需要自己构建函数
//2.只能开辟有限个空间（空间个数和字符串的长度无关）
//student a am i  -->  i ma a tneduts -->  i am a student
//也就是 : 整体逆转 + 局部逆转

//先拿到了字符串的长度
int my_strlen(char* str) {
	int count = 0;
	while (*str++) {
		count++;
	}
	return count;
}

//整体逆转:逆转指定范围内的字符串
void reverse_string(char* start,char* end) {
	//char* start = str;
	//char* end = str + my_strlen(str) - 1;
	while (start < end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

//局部逆转
void reverse(char* str) {
	int len = my_strlen(str);
	char* start = str;
	char* end = str + len - 1;
	char* cur = str;
	//整体逆转:
	reverse_string(start, end);
	//局部逆转:
	while (*cur) {
		char* st = cur;
		//寻找子串尾点
		while (*cur != ' ' && *cur != '\0') {
			cur++;
		}
		//逆转子串
		reverse_string(st, cur - 1);
		if (*cur == ' ') {
			cur++;
		}
	}
}
int main() {
	char str[100];
	//scanf("%s", str);
	//这里不能用scanf函数,因为scanf不接收空格,而gets接受
	gets(str);
	reverse(str);
	printf("%s", str);
	system("pause");
	return 0;
}



//一组数据中只有一个数字出现了一次。
//其他所有数字都是成对出现的。
//请找出这个数字。
int find(int a[], int n) {
	// 0 ^ n = n;
	int ret = 0;
	int i;
	for (i = 0; i < n; i++) {
		ret ^= a[i];
	}
	return ret;
}
int main() {
	int a[] = { 1,2,3,0,14,9,8,1,2,3,0,9,8 };
	printf("%d\n", find(a, sizeof(a) / sizeof(a[0])));
	system("pause");
	return 0;
}




//不使用（a + b）/2这种方式，求两个数的平均值
//一
//(a + b) >> 1 //有溢出风险,风险大
int avg(int a, int b) {
	return (a + b) >> 1;
}
//二
//a + (b - a) >> 1 //溢出风险小
int avg2(int a, int b) {
	return a + ((b - a) >> 1);
}
//三
//两个数的平均值,就是它俩各自的二进制每一位的平均值
int avg3(int a, int b) {
	return (a & b) + ((a ^ b) >> 1);
}
//a = 1011,b = 1100
//a & b = 1000   a & b拿到的是相同位数的平均值
//a ^ b = 0111	 a ^ b拿到的是不同位的总和 所以要除以 2
int main() {
	int a = 10, b = 20;
	printf("%d\n", avg(a, b));
	printf("%d\n", avg2(a, b));
	printf("%d\n", avg3(a, b));
	system("pause");
	return 0;
}





//构建函数,返回值value的二进制位模式从左到右翻转后的值.

//===========思路1===========
//第 1 --> 32     2^31
//第 2 --> 31     2^30
unsigned int reserve_bit1(unsigned int value) {
	unsigned int sum = 0;
	int i;
	for (i = 0; i < 32; i++) {
		sum += ((value >> i) & 1) * (unsigned)pow(2, 31 - i);
	}
	return sum;
}

//===========思路2===========
unsigned int reserve_bit2(unsigned int value) {
	unsigned int temp = 0;
	int i;
	for (i = 0; i < 32; i++) {
		//腾出来第一位,保存当前位获取的值
		temp = temp << 1;
		//把value第i位的值保存在temp的第一位
		temp = temp | ((value >> i) & 1);
		//temp = temp << 1;如果放在这里就会把最高一位挤出去
	}
	return temp;
}
int main() {
	int n = 25;
	printf("%u\n",reserve_bit1(n));
	printf("%u\n", reserve_bit2(n));
	//输出为%u格式
	system("pause");
	return 0;
}



//打印杨辉三角
//第i行元素:i
//a[i][0] = 1,a[i][i] = 1;
//a[i][j] = a[i-1][j-1] + a[i-1][j];
#define N 10
int main() {
	int a[N][N];
	int i, j;
	for (i = 0; i < N; i++) {
		a[i][0] = 1;
		a[i][i] = 1;
	}
	//第 0 和 1 行都算过了,所以从第 2 行开始
	//第 0 列算过了,从第 1 列开始
	for (i = 2; i < N; i++) {
		for (j = 1; j < i; j++) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < 2*(N - i);j++) {
			printf(" ");
		}
		for (j = 0; j <= i; j++) {
			printf("%3d ", a[i][j]);
			//不够4个单位的数字补 空格
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
