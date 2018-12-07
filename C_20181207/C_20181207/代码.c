#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//写一个函数返回参数二进制中 1 的个数
//比如： 15: 0000 1111    4 个 1

int BitOneCount(unsigned int num) {
	int count = 0;
	while (num) {
		if (num % 2 == 1) {
			++count;
		}
		num /= 2;
	}
	return count;
}
//方法②
//n = n & (n - 1)
//把 n 的二进制从低位到高位依次把 1 变成 0
//例如 n = 10 (1010),  n - 1 --> 1001,  n & (n - 1) --> 1000;  count++
//n = 1000,   n - 1 =   0111,  n & (n - 1) --> 0000;  count++;
int count_one(unsigned int n) {
	int count = 0;
	while (n) {
		count++;
		n = n & (n - 1);
	}
	return count;
}





//获取一个数二进制序列中所有的偶数位/奇数位
//分别输出二进制序列.
①	↓↓↓↓↓↓↓
void print_bits(int n) {
	int i = 0;
	//从最高位打
	// 1. 打印偶数位
	for (i = 31; i > 0; i -= 2) {
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
	// 2. 打印奇数位
	for (i = 30; i >= 0; i -= 2) {
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
}

//稍微不太好理解↓↓↓↓↓↓↓↓②
int main() {
	int num, count = 0;
	int a1[16];
	int a2[16];
	scanf("%d", &num);
	while (count < 32) {
		a1[count / 2] = num % 2;
		num = num >> 1;
		++count;
		a2[(count - 1) / 2] = num % 2;
		num = num >> 1;
		++count;
	}
	printf("奇数列:\n");
	for (count = 15; count >= 0; count--) {
		printf("%d", a1[count]);
	}
	printf("\n偶数列:\n");
	for (count = 15; count >= 0; count--) {
		printf("%d", a2[count]);
	}
	system("pause");
	return 0;
}



//输出一个整数的每一位。
int print(int x) {
	if (x > 9) {
		print(x / 10);
	}
	printf("%d\n", x % 10);
}
int main() {
	int num = 1234;
	print(num);
	system("pause");
	return 0;
}

//判断两数二进制位有多少不同
//①按位比较		(m >> (i - 1) & 1 ) == (n >> (i  - 1) & 1)

int bijiao(int m, int n) {
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (((m >> i) & 0x1) != ((n >> i) & 0x1)) {
			++count;
		}
	}
	return count;
}

//②异或比较
//m 1999 -> 011111001111
//n 2299 -> 100011111011
//m ^ n -> 111100110100

int main() {
	uint32_t  m = 1999;
	uint32_t  n = 2299;
	int count = 0, chu = m ^ n;
	for (int i = 1; i <= 32; ++i) {
		if (chu % 2 == 1) {
			++count;
		}
		chu /= 2;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}


//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果 
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。

//如果条件输入完,只用加法   则还是会有多种可能,但是比没有这条约束条件少
//如果只用乘法,可以直接求解
//乘法和加法一起使用一定可以求解

int main() {
	int a, b, c, d, e, c1, c2, c3, c4, c5;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						c1 = (b == 2) + (a == 3) == 1;
						c2 = (b == 2) + (e == 4) == 1;
						c3 = (c == 1) + (d == 2) == 1;
						c4 = (c == 5) + (d == 3) == 1;
						c5 = (e == 4) + (a == 1) == 1;
						if (c1 + c2 + c3 + c4 + c5 == 5 && a + b + c + d + e == 15 && a*b*c*d*e == 120)
						{
							printf("A:%d\nB:%d\nC:%d\nD:%d\nE:%d\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}









//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

int main() {
	char killer;
	for (killer = 'A'; killer <= 'K'; killer++) {
		if ((killer != 'A') + (killer == 'C') + (killer == 'D')
			+ (killer != 'D') == 3) {
			printf("killer is %c\n", killer);
		}
	}
	system("pause");
	return 0;
}


//杨辉三角

int main() {
	int s = 1, h;                    // 数值和高度
	int i, j;                        // 循环计数
	scanf("%d", &h);                 // 输入层数
	printf(" 1\n");                   // 输出第一个 1
	for (i = 2; i <= h; s = 1, i++) {         // 行数 i 从 2 到层高	
		printf("1 ");                // 第一个 1
		for (j = 1; j <= i - 2; j++) // 列位置 j 绕过第一个直接开始循环
			//printf("%d ", (s = (i - j) / j * s));
			printf("%d ", (s = (i - j) * s / j));
		printf("1\n");               // 最后一个 1，换行
	}
	system("pause");
	return 0;
}


//输入两个复数的实部和虚部,输入这两个复数积的实部和虚部
int main(){
	int a,b,c,d;
	printf("输入两个复数的实部和虚部:\n(格式:第一个复数实部和虚部,第二个复数实部和虚部)\n");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int num1 = a * c - b * d;
	int num2 = a * d + b * c;
	printf("两复数积的实部为:%d\n虚部为%d\n", num1, num2);
    system("pause");
    return 0;
}



//输入秒数,将它转换用小时分钟秒来表示
//例如输入7278秒,输出:2小时1分18秒
int main(){
	int second = 0;
	printf("输入秒数:\n");
	scanf("%u", &second);
	int minute, hour;
	hour = second / 3600;
	second %= 3600;
	minute = second / 60;
	second %= 60;
	printf("%d小时 %d分钟 %d秒\n", hour, minute, second);
    system("pause");
    return 0;
}

//输入2小写字母赋值给ch1,ch2,转换为大写,交换二者值,输出ch1,ch2
int main(){
	char ch1, ch2;
	printf("请输入两个小写字母:\n");
	scanf("%c %c", &ch1, &ch2);
	ch1 = ch1 + ('A' - 'a');
	ch2 = ch2 + ('A' - 'a');
	char ret = 0;
	ret = ch1;
	ch1 = ch2;
	ch2 = ret;
	printf("ch1是%c,ch2是%c\n", ch1, ch2);
    system("pause");
    return 0;
}