#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��д����fun���Ӵ����num���ַ������ҳ����һ���ַ���
//Ҫ�����޷���ֵ��ͨ���β�ָ��max���ظô���ַ������������������ַ���
void fun(char (*a)[80],int num,char **max) {
	int i;
	char *p = a[0];
	*max = p;
	for (i = 0; i < num; i++) {
		if (strlen(a[i]) > strlen(p)) {
			p = a[i];
		}
	}
	*max = p;
}

int main() {
	char ss[10][80], *ps;
	int i = 0, n;
	printf("������һЩ�ַ�����\n");
	gets(ss[i]);
	//**** �����������־
	while (!strcmp(ss[i], "****") == 0) {
		i++;
		gets(ss[i]);
	}
	n = i;
	fun(ss,n,&ps);
	printf("\nmax = %s\n", ps);
	system("pause");
	return 0;
}


//��д����fun�����ַ���str���ҳ�ASCII�������ַ��������ڵ�һ��λ���ϣ��������ַ�ǰ��Ԫ�ַ����˳���ƶ�
void fun(char *str) {
	int i = 0;
	char max = *str;
	char *p = str;
	while (str[i] != '\0') {
		if (str[i] > max) {
			max = str[i];
			p = str + i;
		}
		i++;
	}
	while (p > str){
		*p = *(p - 1);
		p--;
	}
	str[0] = max;
}
int main(){
	char str[80];
	gets(str);
	fun(str);
	printf("%s\n",str);
	system("pause");
	return 0;
}


//�涨������ַ�����ֻ������ĸ��*�ţ���д����fun
//���ַ���β��������*ȫ��ɾ����ǰ����м��*�Ų�Ҫɾ��
void delete(char *str) {
	char *p = str;
	while (*p) {
		p++;
	}
	p--;
	while (*p) {
		if (*p == '*') {
			*p = '\0';
		}
		p--;
		if (*p != '*')
			break;
	}
}
int main() {
	char str[80];
	gets(str);
	delete(str);
	printf("%s", str);
	system("pause");
	return 0;
}


//��д����fun��ͳ���Ӵ�substr�����ַ���str�г��ֵĴ���

//-> ����
int fun(char *str, char *substr) {
	int i, j, k, num = 0;
	for (i = 0;i < str[i]; i++) {
		for (j = i, k = 0; substr[k] == str[j]; k++, j++) {
			if (substr[k + 1] == '\0') {
				num++;
				break;
			}
		}
	}
	return num;
}

int main() {
	char str[80], substr[80];
	printf("���������ַ���:\n");
	gets(str);
	printf("�������Ӵ�:\n");
	gets(substr);
	printf("�������Ӵ����ִ���Ϊ:");
	printf("%d\n", fun(str, substr));
	system("pause");
	return 0;
}


//-> �ҵĴ���û���ҵ������ַ������ȵķ���,�趨�ַ�����ò�Ҫ��ָ��
int fun(char *sub, char *str,int size1,int size2) {
	int count = 0, i, num = 0;
	for (i = 0; i < size1 - 1; i++) {
		if (*str == *sub) {
			num++;
		}
		if (num == size2) {
			count++;
			num = 0;
		}
	}
	return count;
}

int main() {
	char* string = "lileihanmeimeimeiyouqian";
	char* substring = "mei";
	int size1 = sizeof(string) / sizeof(string[0]);
	int size2 = sizeof(substring) / sizeof(substring[0]);
	printf("%d\n", fun(substring, string, size1,size2));
	system("pause");
	return 0;
}