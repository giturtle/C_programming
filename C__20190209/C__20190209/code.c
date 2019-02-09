#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//输入3个字符串，按由大到小的顺序输出
int main() {
	char *s[3], st[3][10], **p, *t;
	int i, j;
	for (i = 0, printf("Please enter 3 strings: "); i < 3; s[i] = st[i], scanf("%s", s[i++]));
	for (i = 0; i < 3; i++)
		for (j = i + 1; j < 3; strcmp(s[i], s[j]) > 0 ? t = s[i], s[i] = s[j], s[j] = t, j++ : j++);
	for (p = s; p < s + 3; printf("%s ", *p++));
	printf("\n");

	/*char a[40], b[40], c[40];
	printf("输入第1个字符串:");
	gets(a);
	printf("输入第2个字符串:");
	gets(b);
	printf("输入第3个字符串:");
	gets(c);
	char *a_ptr = a;
	char *b_ptr = b;
	char *c_ptr = c;
	while (1) {
		if (*a_ptr > *b_ptr) {
			if (*a_ptr > *c_ptr) {
				if (*b_ptr > *c_ptr) {
					puts(a);
					puts(b);
					puts(c);
					break;
				}
				else {
					puts(a);
					puts(c);
					puts(b);
					break;
				}
			}
			else {
				puts(c);
				puts(a);
				puts(b);
				break;
			}
		}
		else if (*b_ptr > *c_ptr) {
			if (*a_ptr > *c_ptr) {
				puts(b);
				puts(a);
				puts(c);
				break;
			}
			else {
				puts(b);
				puts(c);
				puts(a);
				break;
			}
		}
		else {
			puts(c);
			puts(b);
			puts(a);
			break;
		}
		a_ptr++;
		b_ptr++; 
		c_ptr++;
	}*/
	system("pause");
	return 0;
}


//输入3个整数，按由小到大的顺序输出
int main() {
	int a, b, c;
	int *a_ptr = &a;
	int *b_ptr = &b;
	int *c_ptr = &c;
	printf("请输入三个整数：\n");
	scanf("%d %d %d", a_ptr,b_ptr,c_ptr);
	if (*a_ptr > *b_ptr) {
		int temp = *a_ptr;
		*a_ptr = *b_ptr;
		*b_ptr = temp;
	}
	if (*a_ptr > *c_ptr) {
		int temp = *a_ptr;
		*a_ptr = *c_ptr;
		*c_ptr = temp;
	}
	if (*b_ptr > *c_ptr) {
		int temp = *b_ptr;
		*b_ptr = *c_ptr;
		*c_ptr = temp;
	}
	printf("由小到大的顺序为：%d %d %d\n", *a_ptr, *b_ptr, *c_ptr);
	system("pause");
	return 0;
}