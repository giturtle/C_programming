#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//��һ�����ź�������飬Ҫ������һ�����󣬰�ԭ������Ĺ��ɽ�������������

//��׼�ⷨ
int main(){
	int a[11] = { 1,4,6,9,13,16,19,28,40,100 };
	int temp, i = 0, j = 0;
	scanf("%d", &temp);
	for (i = 9; i >= 0; i--){
		if (temp < a[i]) {
			a[i + 1] = a[i];
		}
		else {
			a[i + 1] = temp;
			break;
		}
	}
	for (i = 0; i < 11; i++){
		printf("%3d", a[i]);
	}
	system("pause");
	return 0;
}

//�Լ�������
//ȱ�㣺ֻ�ܲ�����βԪ������֮������ֲ��Ҳ��ܲ����ظ����֣���������
//���Ҷ࿪��һ��������ڴ�ռ䣬�˷�
//�
int main() {
	int arr[6] = { 1,4,7,9,12 };
	int arr2[6];
	int num, i;
	printf("\n�������������֣�\n");
	scanf("%d",&num);
	for (i = 0; i <= 4; i++) {
		if (num > arr[i]) {
			arr2[i] = arr[i];
		}else {
			arr2[i] = num;
			for(int j = 0; j <= 6 - i;j++) {
				arr2[i+1] = arr[i];
				i++;
			}
			break;
		}
	}
	for (i = 0; i < 6; i++) {
		printf("%3d", arr2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


//
////��һ��3��3���;���Խ���Ԫ��֮��
//int main() {
//	int arr[3][3];
//	int i,j;
//	printf("������3��3�����Ԫ��:\n");
//	for (i = 0; i < 3; i++) {
//		for (j = 0; j < 3; j++) {
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	printf("�Խ��߼Ӻ�Ϊ:%d\n",arr[0][0]+arr[1][1]+arr[2][2]+
//		arr[0][2] + arr[2][0]);
//	system("pause");
//	return 0;
//}
//
//
////��ѡ�񷨶�10����������
//#define number 10
//int main() {
//	int arr[10];
//	int i, j;
//	printf("������10��������\n");
//	for (i = 0; i < number; i++) {
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < number - 1; i++) {		//10����������9�αȽ�
//		for (j = 0; j < number - 1 - i; j++) {		//��һ�����Ƚ�9�Σ����εݼ�
//			if (arr[j] > arr[j + 1]) {
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	printf("sorted number :");
//	for (j = 0; j < number; j++) {
//		printf("%3d", arr[j]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//
//
////��ɸѡ����100���ڵ�����
//int main() {
//	int num,i,j = 2;
//	for (i = 5; i <= 100; i += 2) {
//		for (j = 2; j <= sqrt(i); j++) {
//			if (i % j == 0)
//				break;
//			}
//		if (j >= (int)sqrt(i) + 1) {
//			printf("%3d", i);
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//
////�������ַ�����Ҫ���ҳ����������
////���ǱȽϳ��ȣ������ֵ����С
//int main() {
//	char arr[3][20];
//	char max[20];
//	for (int i = 0; i < 3; i++) {
//		gets(arr[i]);
//	}
//	if (strcmp(arr[0], arr[1]) > 0) {
//		strcpy(max, arr[0]);
//	}
//	else {
//		strcpy(max, arr[1]);
//	}
//	if (strcmp(arr[2],max) > 0) {
//		strcpy(max, arr[2]);
//	}
//	printf("%s\n", max);
//	system("pause");
//	return 0;
//}
//
//
//�ҳ�һ���ַ����ж��ٸ�����
//int main() {
//	char str[81];
//	int i, num = 0, word = 0;
//	gets(str);
//	for (i = 0; str[i] != '\0'; i++) {
//		if (str[i] == ' ') {
//			word = 0;
//		}
//		else if (word == 0) {
//			word = 1;
//			//word ��1������������ж��׶Σ�ѭ����������뱾ѭ��
//			//ֻ�е����ո�Ż��� 0 �������ж���һ������
//			num++;
//		}
//	}
//	printf("%d������\n", num);
//	system("pause");
//	return 0;
//}
//
////��������
//void despace(char *s, int *i)
//{
//	while (s[*i] == ' ') (*i)++;
//}
//int main()
//{
//	int count = 0, i = 0;
//	char s[50];
//	char c;
//	gets(s);
//	while ((c = s[i]) != '\0')
//	{
//		if (c == ' ')
//		{
//			despace(s, &i);
//			count++;
//		}
//		i++;
//	}
//	count++;
//	printf("\ncount:%d", count);
//	getch();
//	return 1;
//}
//
