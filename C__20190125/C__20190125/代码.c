#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//1.һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ����������֣����ʵ�֡�

//�������Ľ���൱�����������������ֵ������
//�ҵ�������ж�����1��λ��
//����1��λ�ð��������ֳ�����
//ÿһ���б���һ������������һ��
int main() {
	int i, ret, bit = -1;
	int arr[] = { 1,2,3,4,5,6,7,5,4,3,2,1 };
	int size = (int)(sizeof(arr) / sizeof(arr[0]));
	for (i = 0; i < size; ++i) {
		ret ^= arr[i];
	}
	//�ҵ���������1��λ��
	for (i = 0; i < 32; ++i) {
		if (((ret >> i) & 1) == 1) {
			bit = i;
			break;
		}
	}
	int x = 0, y = 0;
	for (i = 0; i < size; ++i) {
		//���ݶ�������1��λ�÷� 2 ��::
		//��һ�飺bitλ�� 1
		if (((arr[i] >> bit) & 1) == 1) {
			x ^= arr[i];
		}
		//�ڶ��飺bitλ�� 0
		else {
			y ^= arr[i];
		}
	}
	printf("%d,%d\n", x, y);
	system("pause"); 
	return 0;
}



//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�
int main() {
	int money;
	printf("������Ǯ����\n");
	scanf("%d", &money);
	int total;
	int empty = 0;
	total = money;
	empty = total;
	while (empty > 1) {
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("�ܹ����Ժ�%dƿ,��ƿ��Ϊ%d\n", total, empty);
	system("pause");
	return 0;
}



//3.ģ��ʵ��strcpy

	//����һ
void Strcpy(char* dest, char* src) {
	while (*src) {
		*dest++ = *src++;
	}
	*dest = '\0';
}

	//������
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



//4.ģ��ʵ��strcat
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
