#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


//��дһ������new����n���ַ����������ռ䣬�˺���Ӧ����һ��ָ�룬ָ���ַ�����ʼ�Ŀռ�
//new(n)��ʾ����n���ֽڵ��ڴ�ռ�


//����һ
char *new(size_t n){
	char *a = (char*)malloc(n*sizeof(char));
	return a;
}
int main() {
	int a;
	scanf("%d", &a);
	char *n = new(a);
	scanf("%s", n);
	//������gets(n);
	puts(n);
	system("pause");
	return 0;
}


//������
char *news(char *s[], int n) {
	for (int i = 0; i < n; s[i++] = (char *)malloc(20 * sizeof(char)));
	return *s;
}
int main(){
	char *str[10], **p;
	int i;
	printf("�����������: ");
	scanf("%d", &i);
	*str = news(str, i);
	for (p = str, printf("����%d���ַ���: ", i); p < str + i; scanf("%s", *p++));
	for (p = str, printf("���Ϊ: "); p < str + i; printf("%s ", *p++));
	system("pause");
	printf("\n");
	return 0;
}





//��дһ���������·ݺţ�������µ�Ӣ����������������3�����march����ָ�����鴦��
int main() {
	char *arr[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December" 
	};
	int month;
	printf("�������·ݺţ�\n");
	scanf("%d", &month);
	printf("%s\n", arr[month - 1]);
	system("pause");
	return 0;
}


//дһ������ʵ�������ַ����ıȽϡ����Լ�дһ��strcmp����
int Strcmp(char *p1, char *p2) {
	while (*p1 && (*p1 == *p2)) {
		p1++;
		p2++;
	}
	return *p1 - *p2;
}
int main() {
	char *str1 = "h";
	char *str2 = "haha";
	printf("%d\n", Strcmp(str1, str2));
	system("pause");
	return 0;
}



//����һ���ַ������������ֺͷ������ַ���������������������Ϊһ�����������δ�ŵ�һ����a�У�ͳ�ƹ��ж������������
void Count(char *s){
	int a[10],i = 0, j,num, t = 0; //iΪ����a���±꣬num���ж��Ƿ������֣�t�����յ�����
	char *p;
	for (p = s; *p != '\0'; p++) {
		if (*p >= '0' && *p <= '9') {
			num = 1;	//������
			t = t * 10 + (*p - '0');
		}
		else if (num == 1) {
			num = 0;	//��һλ��������
			a[i++] = t;
			t = 0;
		}
		if (*p >= '0' && *p <= '9' && p[1] == '\0') {   
			//���������ж��ַ���ĩβ�����ֵ�����¼���һ���ַ����������һ������û��¼�������ѭ��
			p[2] = '\0';
			p[1] = 'a';
		}
	}
	j = i;
	printf("\n�ַ����й���%d�����֡�\n", j);
	printf("�ֱ�Ϊ��\n");
	for (i = 0; i < j; i++) {
		printf("%d ", a[i]);
		printf("\n");
	}
}
int main() {
	char str[50];
	printf("�����ַ���:\n");
	gets(str);
	Count(str);
	system("pause");
	return 0;
}



int main() {
	union IP {
		uint32_t a;
		struct {		//�����ṹ��
			char d1;
			char d2;
			char d3;
			char d4;
		}b;
	}ip;
	ip.a = 0x1;
	printf("%d.%d.%d.%d\n", ip.b.d1, ip.b.d2, ip.b.d3, ip.b.d4);
	system("pause");
	return 0;
}


union Un1{
	char c[5];
	int i;
};
union Un2{
	short c[7];
	int i;
};
int main() {
	printf("%d\n", sizeof(union Un1));	//8
	printf("%d\n", sizeof(union Un2));	//16
	system("pause");
	return 0;
}


//�ֽ�����֤
int Little() {
	int a = 0x11223344;
	char *b = (char*)&a;
	if (*b == 0x11) {
		return 0;
	}
	return 1;
}
//ʹ��������
int little() {
	union Un {
		char a;
		int b;
	}u;
	u.b = 0x11223344;
	if (u.a == 0x11) {
		return 0;
	}
	return 1;
}



union Un {
	char c;
	int i;	
};
struct S {
	char c;
	int i;
};
int main() {
	union Un u;
	struct S s;
	printf("%lu\n", sizeof(u));
	printf("%lu\n", sizeof(s));

	system("pause");
	return 0;
}



enum Color{
	red = 1,
	green = 4,
	blue = 5,
};
int main() {
	enum Color c = green;
	c = 4;
	system("pause");
	return 0;
}