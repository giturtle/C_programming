#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��д����fun����s��ָ���ַ��������������������ӣ��γɵ��´�����t������
void fun(char s[],char t[]) {
	int i, d;
	d = strlen(s);
	for (i = 0; i < d; i++) {
		t[i] = s[i];
	}
	for (i = 0; i < d; i++) {
		t[d+i] = s[d-1-i];
	}
	t[2 * d] = '\0';
}

int main() {
	char s[40], t[80];
	printf("�����ַ�����\n");
	scanf("%s", s);
	fun(s, t);
	printf("%s\n", t);
	system("pause");
	return 0;
}


//��д����fun�������Ĺ����ǣ����ַ�����ɾ��ָ�����ַ���ͬһ�ַ���Сд����ͬ�ַ�����

//����һ
void fun(char s[], char c) {
	int i = 0; char *p;
	p = s;
	while (*p) {
		if (*p != c) {
			s[i] = *p;
			i++;
		}
		p++;
	}
	s[i] = '\0';
}

//������
void fun2(char s[], char c) {
	int i, j;
	for (i = j = 0; *(s + i); i++) {
		if (s[i] != c) {
			s[j++] = s[i];
		}
		s[j] = '\0';
	}
}

int main() {
	static char str[] = "my name is hanmeimei";
	char ch;
	printf("ԭ�ַ���Ϊ��%s\n", str);
	printf("������һ���ַ���\n");
	scanf("%c", &ch);
	//getch(ch);
	//fun(str, ch);
	fun2(str, ch);
	printf("���ַ���Ϊ��%s\n", str);
	system("pause");
	return 0;
}