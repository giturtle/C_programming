#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>




//����һ���ַ����ҳ����д�д��ĸ��Сд��ĸ���ո������Լ������ַ���Ŀ
void Found(char* a) {
	int dx = 0, xx = 0, kg = 0, sz = 0, qt = 0;
	while (*a != '\0') {
		if (*a >= 'A' && *a <= 'Z') {
			dx++;
		}
		else if (*a >= 'a' && *a <= 'z') {
			xx++;
		}
		else if (*a > '0' && *a <= '9') {
			sz++;
		}
		else if (*a == ' ') {
			kg++;
		}
		else {
			qt++;
		}
		a++;
	}
	printf("��д��ĸ��%d��\n", dx);
	printf("Сд��ĸ��%d��\n", xx);
	printf("���֣�%d��\n", sz);
	printf("�ո�%d��\n", kg);
	printf("�����ַ���%d��\n", qt);
}
int main() {
	char arr[100];
	printf("������һ���ַ���\n");
	gets(arr);
	Found(arr);
	system("pause");
	return 0;
}


//дһ��������һ���ַ������ȣ���main�����������ַ�����������䳤��
int my_strlen(char str[]) {
	int count = 0;
	while(*str != '\0'){
		count++;
		str++;
	}
	return count;
}
int main() {
	char str[20];
	printf("�������ַ�����\n");
	scanf("%s",&str);
	printf("%d\n",my_strlen(str));
	system("pause");
	return 0;
}




//����10����������������С�������һ�����Ի��������������һ�����ֶԻ�
//д��������������10���������д������10����
void input(int arr[10]) {
	printf("����10��������\n");
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
}

void transform(int arr[10]) {
	int *max, *min, *p, *arr_end;
	arr_end = arr + 10;
	max = min = arr;//��ŵĶ��ǵ�ַ
	for (p = arr + 1; p < arr_end; p++) {
		if (*p > *max)
			max = p;
		else if (*p < *min)
			min = p;
	}
	*p = arr[0]; arr[0] = *min; *min = *p;//��С�����һ��������
	*p = arr[9]; arr[9] = *max; *max = *p;//����������һ��������
}

void output(int arr[10]) {
	int *p;
	for (p = arr; p <= arr + 9; p++) {
		printf("%3d", *p);
	}
}
int main() {
	int arr[10];
	input(arr);
	transform(arr);
	output(arr);
	system("pause");
	return 0;
}