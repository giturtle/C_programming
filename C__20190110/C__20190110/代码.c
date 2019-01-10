#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>


int main() {
	char i, j, k;
	//i是A的对手，j是B的对手，k是C的对手
	for (i = 'X'; i <= 'Z'; i++)
	{
		for (j = 'X'; j <= 'Z'; j++)
		{
			for (k = 'X'; k <= 'Z'; k++)
			{
				if (i != k && j != k && i != j)
				{
					if (i != 'X' && k != 'X' && k != 'Z')
					{
						printf("A——%c\nB——%c\nC——%c\n", i, j, k);
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}


//求和
#define n 5
int main() {
	int a, Sn = 0,t = 0;
	printf("请输入a的值:\n");
	scanf("%d",&a);
	for (int i = 0; i < n; i++) {
		t = t * 10+a;
		Sn += t;
	}
	printf("%d\n", Sn);
	system("pause");
	return 0;
}

//求正整数m，n最大公约数和最小公倍数
int main() {
	int m, n;
	int gongyue, gongbei, max,min;
	printf("输入两个正整数m，n:\n");
	scanf("%d %d", &m, &n);
	int ll = 1, key = 1;
	for (int i = 1; i <= (n < m ? n : m); i++) {
		if (m % i == 0 && n % i == 0) {
			gongyue = i;
			if (ll) {
				max = gongyue;
				ll--;
			}
			if (max < gongyue) {
				max = gongyue;
			}
		}
	}
	gongbei= m > n ? m : n;
	while (1) {
		if (gongbei % m == 0 && gongbei % n == 0) {
			min = gongbei;
			break;
		}
		gongbei++;
	}
	printf("最大公约数为:%d\n", max);
	printf("最小公倍数为:%d\n", min);
	system("pause");
	return 0;
}


int main() {
	char arr[20] = { 0 };
	system("shutdown -s -t 6000");
	while (1) {
		printf("电脑即将关机，如果输入“i am pig”就取消关机！请输入：\n");
		gets(arr);
		if (!strcmp(arr,"i am pig")) {
			system("shutdown -a");
			printf("好的\n");
			break;
		}
	}
	system("pause");
	return 0;
}



//译密码
int main() {
	char c;
	c = getchar();
	while (c != '\n') {
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
			if ((c >= 'W' && c <= 'Z') || (c >= 'w' && c <= 'z')) {
				c = c - 'A' - 'a';
			}
			else {
				c = c + 4;
			}
		}
		putchar(c);
		c = getchar();//第二字符的入口
	}
	printf("\n");
	system("pause");
	return 0;
}


//判断素数 100 ~ 200
int main() {
	int i, j, m = 0;
	for (i = 101; i <= 200; i += 2) {
		for (j = 2; j <= (int)sqrt(i); j++){
			if (i % j == 0) {
				break;
			}
		}
		if (j >= (int)sqrt(i) + 1) {
			//全都是 >= 的情况，但 == 就已经都满足了
			printf("%4d", i);
			m++;
		}
		if (m == 10) {
			printf("\n");
			m = 0;
		}
	}
	system("pause");
	return 0;
}