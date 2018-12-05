//(递归)斐波那契数列
int fib(int x) {
	if (x <= 2) {
		return 1;
	}
	return fib(x - 1) + fib(x - 2);
}
//(非递归)斐波那契数列
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Fib(int x) {
	if (x == 1 || x == 2) {
		return 1;
	}
	int f1 = 1;
	int f2 = 1;
	int c = 0;
	for (int i = 3; i <= x; i++) {
		c = f1 + f2;
		f1 = f2;
		f2 = c;
	}return c;
}




//非递归编写一个函数实现n^k
int CiFang(int n, int k) {
	int num = 1;
	if (n == 0) {
		return 0;
	}
	for (int i = 1; i <= k; i++) {
		num *= n;
	}
	//或者
	//	while (k--)
	//	{
	//		num *= n;
	//	}
	return num;
}
//递归实现一个函数n^k
int CiFang(int n, int k) {
	if (k < 0) {
		return 0;
	}
	if (k == 0) {
		return 1;
	}
	return n * CiFang(n, k - 1);
}


//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和。
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19。
int DigitSum(int n) {
	if (n < 10) {
		return n;
	}
	return n % 10 + DigitSum(n / 10);

	[我的错解]：
		int DigitSum(int n) {
		int sum = 0;
		int num = n / 10;
		sum += DigitSum(num % 10);
		return sum;
	}







	//编写一个函数 reserve_string(char* string)(递归实现)
	//实现:将参数字符串中字符反向排列
	//要求:不能使用C函数库中的字符串操作函数
	// ① 可以申请一个数组 在倒序出来
	// ② 指针 : (指针解引用)首尾内容交换,头指针++,尾指针--

	//创建自己的strlen,不使用库函数的
	int mystrlen(char* str) {
		int count = 0;
		while (*str) {
			count++;
			str++;
		}
		return count;
	}

	//非递归
	void reverse_string(char* str) {
		char* start = str;
		char* end = str + mystrlen(str) - 1;
		while (start < end) {
			char tmp;
			tmp = *start;
			*start = *end;
			*end = tmp;
			start++;
			end--;
		}
	}

	//递归
	void reverse(char* str) {
		if (*str) {
			char* start = str;
			char* end = str + mystrlen(str) - 1;
			//首尾内容互换
			char temp = *start;
			*start = *end;
			//尾点内容暂时存为结束标识符
			*end = '\0';
			//逆转子串
			reverse(start + 1);
			//恢复尾点内容
			*end = temp;
		}
	}

	int main() {
		//char str[] = "abcdef";
		char str[100] = { 0 };
		scanf("%s", &str);

		reverse_string(str);
		printf("%s\n", str);

		reverse(str);
		printf("%s", str);

		system("pause");
		return 0;
	}





	//递归实现strlen
	//①
	int Strlen(const char *str) {
		if (*str == '\0') {
			return 0;
		}
		else {
			return 1 + Strlen(str + 1);
		}
	}
	//递归
	int m_strlen(char* str) {
		if (*str)
			//等价于if (*string != '\0')
		{
			return 1 + m_strlen(str + 1);
		}
		return 0;

	}
	//非递归
	int feistrlen(char* str) {
		int count = 0;
		while (*str) {
			count++;
			str++;
		}
		return count;
	}





	//非递归实现n的阶乘
	int JieCheng(int n) {
		if (n <= 1) {
			return  1;
		}
		int num = 1;
		for (int i = 1; i <= n; ++i) {
			num *= i;
		}
		return num;
	}
	//递归实现n的阶乘
	int JieCheng(int n) {
		if (n <= 1) {
			return 1;
		}
		return n * JieCheng(n - 1);



		//递归方式实现打印一个整数的每一位 
		int PrintNum(int x) {
			if (x > 9) {
				PrintNum(x / 10);
			}
			printf("%d\n", x % 10);
		}
		//非递归方式实现打印一个整数的每一位太繁琐 




