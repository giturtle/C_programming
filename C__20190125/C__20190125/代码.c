#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个数字，编程实现。

//连续异或的结果相当于两个单独出现数字的异或结果
//找到异或结果中二进制1的位置
//根据1的位置把所有数分成两组
//每一组中必有一个数单独出现一次
int main() {
	int i, ret, bit = -1;
	int arr[] = { 1,2,3,4,5,6,7,5,4,3,2,1 };
	int size = (int)(sizeof(arr) / sizeof(arr[0]));
	for (i = 0; i < size; ++i) {
		ret ^= arr[i];
	}
	//找到二进制中1的位置
	for (i = 0; i < 32; ++i) {
		if (((ret >> i) & 1) == 1) {
			bit = i;
			break;
		}
	}
	int x = 0, y = 0;
	for (i = 0; i < size; ++i) {
		//根据二进制中1的位置分 2 组::
		//第一组：bit位是 1
		if (((arr[i] >> bit) & 1) == 1) {
			x ^= arr[i];
		}
		//第二组：bit位是 0
		else {
			y ^= arr[i];
		}
	}
	printf("%d,%d\n", x, y);
	system("pause"); 
	return 0;
}



//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。
int main() {
	int money;
	printf("请输入钱数：\n");
	scanf("%d", &money);
	int total;
	int empty = 0;
	total = money;
	empty = total;
	while (empty > 1) {
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("总共可以喝%d瓶,空瓶数为%d\n", total, empty);
	system("pause");
	return 0;
}



//3.模拟实现strcpy

	//方法一
void Strcpy(char* dest, char* src) {
	while (*src) {
		*dest++ = *src++;
	}
	*dest = '\0';
}

	//方法二
char* Strcpy(char* dest, char* src) {
	char* temp = dest;
	while (*dest++ = *src++);
	return temp;
}

int main() {
	char a[20] = "abcde";
	char b[10] = "fgh";
	Strcpy(a, b);
	printf("%s\n", a);
	system("pause");
	return 0;
}



//4.模拟实现strcat
void Strcat(char* dest, char* src) {
	while (*dest) {
		dest++;
	}
	while (*dest = *src) {
		dest++;
		src++;
	}
}

int main() {
	char a[20] = "abcde";
	char b[10] = "fgh";
	Strcat(a, b);
	printf("%s\n", a);
	system("pause");
	return 0;
}
