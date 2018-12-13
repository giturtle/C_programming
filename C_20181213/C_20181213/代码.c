#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



把1到25的自然数按行顺序存入一个5×5的二维数组中,然后输出该数组的右上半三角
int main() {
	int a[5][5], i, j, k = 1;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			a[i][j] = k++;
		}
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (i > j) {
				printf("%4s", " ");
			}
			else {
				printf("%4d", a[i][j]);
			}
		}
	}
	printf("\n");
	system("pause");
	return 0;
}



//从键盘输入一串英文文字,统计其中字母(不区分大小写)的数目
int main() {
	char str[300];
	int i, j;
	printf("请输入一串英文文字:\n");
	gets(str);
	for (i = 0, j = 0; str[i]; i++) {
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
			j++;
		}
	}
	printf("字符串中共有%d个英文字母.\n", j);
	system("pause");
	return 0;
}




//编写程序,输入两个字符串str和substr,删除主字符串str中的所有子字符串substr
int main() {
	char str[300], substr[300];
	int i, i1, j;
	printf("请输入主字符串:\n");
	gets(str);
	printf("请输入子字符串:\n");
	gets(substr);
	for (i = 0, i1 = 0; str[i1] != '\0';) {
		j = 0;
		while (str[i1] && substr[j] && str[i1] == substr[j]) {
			i1++;
			j++;
		}
		if (substr[j] == '\0') {
			continue;
		}
		else {
			i1 -= j;
			str[i++] = str[i1++];
		}
	}
	str[i] = '\0';
	printf("删除子字符串后,主字符串变成了%s\n", str);
	system("pause");
	return 0;
}



//编写程序,将一个字符串反向存放
int main() {
	char str[256], temp;
	int i, j,len;
	printf("请输入字符串:");
	gets(str);
	len = strlen(str);
	for (i = 0, j = len - 1; i <= len / 2; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	printf("反向后的字符串是:%s\n",str);
	system("pause");
	return 0;
}





//从键盘输入一个字符串,将该字符串中的字符排序
//然后再输入一个字符,并用折半查找方法找出该字符在已排序的字符串中的位置
//若该字符不在字符串中,输出提示信息.
int main() {
	char arr[10];
	printf("请输入一个字符串:\n");
	scanf("%s", &arr);
	int left, right, mid;
	int i, j, k;
	for (i = 0; i < strlen(arr); i++) {
		k = i;
		for (j = i + 1; j < strlen(arr); j++) {
			if (arr[k] > arr[j]) {
				k = j;
			}
		}
		if (k != i) {
			int temp = 0;
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
	printf("排序后的字符串:\n");
	printf("%s", arr);
	printf("请输入一个要查找的字符:\n");
	char to_find = getchar();
	left = 0;
	right = strlen(arr) - 1;
	if (to_find > arr[left] && to_find < arr[right]) {
		for (i = 0; i <= strlen(arr) - 1; i++) {
			mid = (left + right) / 2;
			if (to_find > arr[mid]) {
				left = mid + 1;
			}
			else if (to_find < arr[mid]) {
				right = mid - 1;
			}
			else {
				break;
			}
		}
	}
	if (left < right && mid != 0) {
		printf("数组下标是%d\n", mid);
	}
	else {
		printf("没找到!\n");
	}
	system("pause");
	return 0;
}