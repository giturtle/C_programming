#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//��̽��ַ���s�����еĿո��ַ�ɾȥ

//�������������ʵ���ˡ��ַ���һ���ո񡱵�ɾȥ����̫����
void delete_string1(char arr[]) {
	char str[50];
	int i = 0;
	while (*arr != '\0') {
		if (*arr != ' ') {
			str[i++] = *arr;
		}
		else {
			str[i++] = *(arr + 1);
		}
		arr++;
	}
	str[i] = '\0';
	printf("%s\n", str);
}

//�ڸĽ��棬���Դ������ո�
void delete_string(char arr[]) {
	char str[50];
	int i = 0;
	while (*arr != '\0') {
		if (*arr == ' ') {
			arr++;
			continue;
		}
		str[i++] = *arr;
		arr++;
	}
	str[i] = '\0';
	printf("%s\n", str);
}

int main() {
	char *s = "Our   story  begins   ~";
	printf("ɾ��֮ǰ���ַ���Ϊ��%s\n\n", s);
	printf("ɾ��֮����ַ���Ϊ��\n");
	delete_string(s);
	delete_string1(s);
	system("pause");
	return 0;
}



//��д������ת��һ��3 �� 3����
void reverse(int arr[3][3]) {
	int t;
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 3; j++) {
			//j = i�ܹؼ�������1
			//���������j = 0���ͻ�ת�����Σ������ԭ��������
			//j = i�������Ļ��ͱ�֤�ӶԽ���һ�����֣�����任����
			t = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = t;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int a[3][3];
	printf("����һ���������о���\n");
	for (int i = 0; i < 3; i++) {
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	}
	printf("\n�任�������Ϊ��\n");
	reverse(a);
	system("pause");
	return 0;
}




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



