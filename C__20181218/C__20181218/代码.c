#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//编写一个程序,将字符数组s2中的全部字符 拷贝到字符数组s1中
//不能使用strcpy函数.拷贝时,'\0'也要拷贝过去,'\0'后面的字符不拷贝
int main() {
	char s1[80], s2[40];
	int i;
	printf("请输入字符数组s2:\n");
	scanf("%s", s2);
	for (i = 0; i <= strlen(s2); i++) {
		s1[i] = s2[i];
	}
	//s1[i] = '\0'; 当上面判定条件包含=时本语句可以省略;
	printf("拷贝之后的字符串为:%s\n", s1);
	system("pause");
	return 0;
}



//编写程序,将两个字符串 s1 和 s2 进行比较
//如果s1 > s2,输出一个正数
//如果s1 = s2,输出0;
//如果s1 < s2,输出一个负数
//要求不使用strcmp函数,两个字符串用gets函数读入
//输出的正数或者负数的绝对值是相比较的两个字符串对应字符的ASCII码的差值
int main() {
	int i = 0,num;
	char a1[50], a2[50];
	printf("请输入字符串s1:\n");
	gets(a1);
	printf("请输入字符串s2:\n");
	gets(a2);
	while ((a1[i] == a2[i]) && (a1[i] != '\0')) {
		i++;
	}
	if ((a1[i] == '\0') && (a2[i] == '\0')) {
		num = 0;
	}
	else {
		num = a1[i] - a2[i];
	}
	printf("\n%d\n", num);
	system("pause");
	return 0;
}



//编一个程序,将两个字符串连起来,不要用strcat函数
int main() {
	char str1[20], str2[20];
	printf("请输入字符串1:\n");
	gets(str1);
	printf("请输入字符串2:\n");
	gets(str2);
	printf("%s%s", str1, str2);
	system("pause");
	return 0;
}

//以下是其他算法:
int main() {
	char s1[80], s2[40];
	int i = 0, j = 0;
	printf("请输入字符串1:\n");
	scanf("%s", &s1);
	printf("请输入字符串2:\n");
	scanf("%s", &s2);
	while (s1[i]) {
		i++;
	}
	while (s2[j] != '\0') {//这里判定条件和上一个等效
		//将s2字符串的各个字符放到s1字符串适当位置
		s1[i++] = s2[j++];
	}
	s1[i] = '\0';
	printf("合并后的字符串为: %s\n", s1);
	system("pause");
	return 0;
}



//打印以下图形:
// *****
//  *****
//   *****
//    *****
//      *****
int main() {
	int i, j;
	for (i = 0; i < 5; ++i) {
		for (j = 0; j <= i; ++j) {
			printf(" ");
		}
		for (j = 0; j < 5; ++j) {
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}



//一个数如果恰好等于它的因子之和,这个数就称为"完数",6=1+2+3,输出1000内的所有完数.
//输出格式 6 its factors are 1,2,3
int main() {
	int j, k, sum;
	for (k = 2; k <= 1000; k++)
	{
		sum = 0;
		for (j = 1; j < k; j++)
			if (k%j == 0)
				sum = sum + j;
		if (sum == k)
			printf("%d ", k);
	}
	system("pause");
	return 0;
}

//有问题  多输出24 因为24不到最后一个因子就和本数相等了 可以试着用数组存储
int main()
{
	int j, i, sum;
	for (i = 2; i <= 1000; i++)
	{
		sum = 0;
		for (j = 1; j < i; j++)
		{
			if (i % j == 0)
				sum += j;/*把它的因数累加起来赋给sum存储起来*/
			if (sum == i) /*因数之和等于给出的那个数n*/
			{
				printf(" %4d its factors are: ", i);/*输出n的值*/
				for (j = 1; j < i; j++)
				{
					if (i % j == 0) printf("%d,", j);/*把i的值依次输出*/
				}	
				printf("\n");	/*输出完一列之后换行*/
			}
		}
	}
	system("pause");
	return 0;
}


int main() {
	int i, j, k = 0, count = 0, sum;
	char a[6];
	for (i = 2; i <= 1000; ++i) {
		sum = 0;
		for (j = 1; j < i; j++) {
			if (i % j == 0) {
				sum += j;
				a[k] = j;
			//我的错误点:希望创建数组把因子存起来,最后实现挨个输出
			//其实并非存的全部因子,每个数字的公共因子 1 会多次存储
				k++;
				count++;
			}
		}
		if (sum == i) {
			printf("%4d ", i);
			for (j = 0;j <= count; j++) {
				printf("its factors are %d", a[j]);
			}
		}
	}
	system("pause");
	return 0;
}