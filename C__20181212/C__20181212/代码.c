#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
编写程序实现将字符串str2拷贝到字符串str1
int main() {
	char str1[256];
	char str2[256];
	int i;
	printf("请输入字符串:\n");
	gets(str2);
	for (i = 0; str2[i]; i++) {
		str1[i] = str2[i];
	}
	str1[i] = '\0';
	没有上面语句就是 烫烫烫 ,这个语句需要重点理解
	printf("复制后的字符串是:%s\n", str1);
	system("pause");
	return 0;
}



//某国国王问棋艺高超的宰相:欲朕赐何物?宰相曰:只需在棋盘的第一格中放1粒谷,第二格放2粒
//如此每往下一格,谷粒加倍,望陛下将第64格中谷粒恩赐微臣
//贪婪的宰相欲得谷粒几何? 2 ^ 63
int main() {
	//用普通的变量储存就会溢出
	int a[64] = { 1 }; 
	int i, j, n, t; //变量 n 存放积的位数
	for (i = 1, n = 1; i <= 63; i++) {  //计算2 ^ 63次方的值
		t = 0;	//变量 t 存放进位
		for (j = 0; j < n; j++) {
			a[j] = 2 * a[j] + t;	//当前运算结果(数组a)的每一位乘 2 加进位
			t = a[j] / 10;
			if (t > 0) {
				a[j] = a[j] % 10;
			}
		}
		if (t > 0) {	//如果最高位有进位,则当前运算结果的位数加 1
			a[n++] = 1;
		}
	}//以下输出积的每一位,个位存放在 a[0] 中,最高位存放在 a[n - 1]元素中
	for (i = n - 1; i >= 0; i--) {
		printf("%d", a[i]);
	}
	system("pause");
	return 0;
}




//(排序有点小问题)
//输入若干整数,以-1结束输入,把这些书存入数组a中,并输出
//再找出a数组中所有的素数存入数组b
//并按每行5个元素的格式由大到小输出这些素数
int main() {
	int a[15], b[15];
	int x,i,j,m = 0,n = 0;
	int swap, temp;
	printf("请输入15个以内的整数,以-1结束输入:\n");
	scanf("%d", &x);
	while (x != -1) {
		a[n++] = x;
		scanf("%d", &x);
	}
	for (i = 0; i < n; ++i) {
		for (j = 2; j <= a[i] - 1; j++) {
			if (a[i] && j == 0) {
				break;
			}
		}
		if (j == a[i]) {
			b[m++] = a[i];
		}
	}
	
	for (i = 0; i < m - 1; ++i) {
		swap = 0;
		for (j = 0; j < m - i - 1; j++) {
			if (b[j] > b[j + 1]) {
				swap = 1;
				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
			if (!swap) {
				break;
			}
		}
	}
	printf("其中素数为:\n");
	for (i = 0, j = 0; i < m; i++) {
		j++;
		printf("%8d", b[i]);
		if (j % 5 == 0) {
			printf("\n");
		}
	}
	system("pause");
	return 0;
}


//(未完成)需要修改,有小缺陷
//对数组A中的N(0<N<100)个整数从小到大进行连续编号
//要求:不能改变数组A中元素的顺序,且相同的整数具有相同的编号
//如:A数组{5,3,4,7,3,5,6}
//则输出为3,1,2,5,1,3,4
int main() {
	int i, j, n;
	int a[100], code[100] = { 0 };
	int min, max, end, count = 0;
	printf("请输入整数的个数n (0 < n <100)\n");
	scanf("%d", &n);
	printf("请输入%d个整数:\n", n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (i == 0) {
			max = a[0];
		}
		else if (a[i] > max) {
			max = a[i];
		}
	}
	while (1) {
		min = max + 1;
		end = 1;
		for (i = 0; i < n; ++i) {
			if ((a[i] < min) && (code[i] == 0)) {
				min = a[i];
				end = 0;
			}
			if (!end) {
				count++;
				for (i = 0; i < n; ++i) {
					if (a[i] == min) {
						code[i] = count;
					}
				}
			}
			if (end)
				break;
		}

		for (i = 0; i < n; ++i) {
			printf("%d ", code[i]);
		}
		system("pause");
		return 0;
	}
}



//有1000个编了号的产品,编号从1001到2000
//从中随机抽取10个产品来检验
//编写程序,由小到大输出被抽取的产品编号
int main() {
	int i, j, k;
	int a[1000], temp;
	for (i = 0; i < 1000; ++i) {
		a[i] = 1001 + i;
	}
	for (i = 0; i < 10; ++i) {
		k = i + rand(1000 - i);
		temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
	//用选择法对a数组前 10 个元素进行排序
	for (i = 0; i < 10 - 1; i++) {
		k = i;
		for (j = i + 1; j < 10; j++) {
			if (a[k] > a[j]) {
				k = j;
			}
			if (k != i) {
				temp = a[i];
				a[i] = a[k];
				a[k] = temp;
			}
		}
		printf("被抽取的产品编号为:\n");
		for (i = 0; i < 10; i++) {
			printf("%4d", a[i]);
		}
		printf("\n");

	}
	system("pause");
	return 0;
}

//输入10个整数存入数组中,找出其中最小数和次最小数
int main() {
	int a[10];
	int i;
	printf("请输入10个整数:\n");
	for (i = 0; i < 10; ++i) {
		scanf("%d", &a[i]);
	}
	int min1, min2;
	min1 = a[0] < a[1] ? a[0] : a[1];
	min2 = a[0] < a[1] ? a[1] : a[0];
	for (i = 2; i < 10; ++i) {
		if (a[i] < min1) {
			min2 = min1;
			min1 = a[i];
		}
		else if (a[i] < min2)
			min2 = a[i];
	}
	printf("10个数最小的是%d,次最小数是%d\n", min1, min2);
	system("pause");
	return 0;
}