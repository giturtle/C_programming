#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



//��дһ�����򣬽��ַ�����s2�е�ȫ���ַ����Ƶ��ַ�����s1��
//��Ҫ��strcpy����������ʱ��'\0'ҲҪһ�����ƹ�ȥ��'\0'����ַ�������
int main() {
	char s1[20];
	char s2[20];
	gets(s2);
	int i = 0, j = 0;
	//while(s2[i] != '\0'){   //�������������ԣ�for��while���Ի���ת��
	for(;s2[i] != '\0';i++){
		s1[j++] = s2[i];
	}
	s1[j] = '\0';
	printf("���ƺ��si����Ϊ:\n");
	puts(s1);
	system("pause");
	return 0;
}


//��̽������ַ���s1��s2�Ƚ�
//��s1>s2�����һ����������s1=s2�����0����s1<s2�����һ������
//��Ҫʹ��strcpy�����������ַ�����gets��������
//��������������ľ���ֵӦ����Ƚϵ������ַ�����Ӧ�ַ���ASCII��Ĳ�ֵ
int main() {
	char s1[10];
	char s2[10];
	printf("�������ַ���s1:\n");
	gets(s1);
	printf("�������ַ���s2:\n");
	gets(s2);
	int i = 0;
	for (; s1[i] != '\0' && s1[i] != '\0'; i++) {
		if (s1[i] == s2[i]) {
			continue;
		}
		else
			printf("%d\n", s1[i] - s2[i]);
	}
	if (s1[i] == '\0' || s2[i] == '\0') {
		printf("%d\n", 0);
	}
	system("pause");
	return 0;
}


//��дһ�����򣬽������ַ���������������Ҫ��strcat����
int main() {
	char arr1[20] = "i am";
	char arr2[10] = " Tom!";
	int j = 0;
	int i = 0;
	while (arr1[i] != '\0') {
		arr1[j++] = arr1[i++];
	}
	i = 0;
	while(arr2[i]!= '\0'){
		arr1[j++] = arr2[i++];
	}
	arr1[j] = '\0';
	puts(arr1);
	system("pause");
	return 0;
}