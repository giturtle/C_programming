#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��дһ������,���ַ�����s2�е�ȫ���ַ� �������ַ�����s1��
//����ʹ��strcpy����.����ʱ,'\0'ҲҪ������ȥ,'\0'������ַ�������
int main() {
	char s1[80], s2[40];
	int i;
	printf("�������ַ�����s2:\n");
	scanf("%s", s2);
	for (i = 0; i <= strlen(s2); i++) {
		s1[i] = s2[i];
	}
	//s1[i] = '\0'; �������ж���������=ʱ��������ʡ��;
	printf("����֮����ַ���Ϊ:%s\n", s1);
	system("pause");
	return 0;
}



//��д����,�������ַ��� s1 �� s2 ���бȽ�
//���s1 > s2,���һ������
//���s1 = s2,���0;
//���s1 < s2,���һ������
//Ҫ��ʹ��strcmp����,�����ַ�����gets��������
//������������߸����ľ���ֵ����Ƚϵ������ַ�����Ӧ�ַ���ASCII��Ĳ�ֵ
int main() {
	int i = 0,num;
	char a1[50], a2[50];
	printf("�������ַ���s1:\n");
	gets(a1);
	printf("�������ַ���s2:\n");
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



//��һ������,�������ַ���������,��Ҫ��strcat����
int main() {
	char str1[20], str2[20];
	printf("�������ַ���1:\n");
	gets(str1);
	printf("�������ַ���2:\n");
	gets(str2);
	printf("%s%s", str1, str2);
	system("pause");
	return 0;
}

//�����������㷨:
int main() {
	char s1[80], s2[40];
	int i = 0, j = 0;
	printf("�������ַ���1:\n");
	scanf("%s", &s1);
	printf("�������ַ���2:\n");
	scanf("%s", &s2);
	while (s1[i]) {
		i++;
	}
	while (s2[j] != '\0') {//�����ж���������һ����Ч
		//��s2�ַ����ĸ����ַ��ŵ�s1�ַ����ʵ�λ��
		s1[i++] = s2[j++];
	}
	s1[i] = '\0';
	printf("�ϲ�����ַ���Ϊ: %s\n", s1);
	system("pause");
	return 0;
}



//��ӡ����ͼ��:
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



//һ�������ǡ�õ�����������֮��,������ͳ�Ϊ"����",6=1+2+3,���1000�ڵ���������.
//�����ʽ 6 its factors are 1,2,3
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

//������  �����24 ��Ϊ24�������һ�����Ӿͺͱ�������� ��������������洢
int main()
{
	int j, i, sum;
	for (i = 2; i <= 1000; i++)
	{
		sum = 0;
		for (j = 1; j < i; j++)
		{
			if (i % j == 0)
				sum += j;/*�����������ۼ���������sum�洢����*/
			if (sum == i) /*����֮�͵��ڸ������Ǹ���n*/
			{
				printf(" %4d its factors are: ", i);/*���n��ֵ*/
				for (j = 1; j < i; j++)
				{
					if (i % j == 0) printf("%d,", j);/*��i��ֵ�������*/
				}	
				printf("\n");	/*�����һ��֮����*/
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
			//�ҵĴ����:ϣ��������������Ӵ�����,���ʵ�ְ������
			//��ʵ���Ǵ��ȫ������,ÿ�����ֵĹ������� 1 ���δ洢
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