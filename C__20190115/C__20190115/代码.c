#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//дһ��������ʹ������һ��3��3�Ķ�ά��������ת�ã����л���
#define NUM 5
void transform(int arr[][NUM],int num) {
	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {	//�����ʱ��j = 0���ͻ�ת�����α��ԭ����
			//������ ��������
			int temp = arr[j][i];
			arr[j][i] = arr[i][j];
			arr[i][j] = temp;
		}
	}
}
int main() {
	int num, arr[NUM][NUM];
	printf("�����ά��������:\n");
	scanf("%d", &num);
	printf("��������Ԫ��:\n");
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	transform(arr, num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


//дһ���ж������ĺ�������������������һ������������Ƿ�Ϊ��������Ϣ
int Isprime(int num) {
	int i;
	for (i = 2; i < sqrt(num); i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	if (i >(int)sqrt(num)) {
		return 1;
	}
	//���������� return 1�� ��������if
}

int main() {
	int num;
	printf("����������:\n");
	scanf("%d", &num);
	if (Isprime(num)) {
		printf("%d������", num);
	}
	else {
		printf("%d��������", num);
	}
	system("pause");
	return 0;
}


//�������ax^2 + bx + c = 0�ĸ��������������ֱ���
//�� b^2 - 4ac > 0/ = 0/ < 0ʱ�ĸ�����������������������a��b��c��ֵ
void dayu(double delta, double p, double q, double a, double b, double c) {
	double x, y;
	printf("\n���������ȵ�ʵ��\n");
	x = p + q;
	y = p - q;
	printf("һ��Ϊ:%5.2lf,һ��Ϊ: %5.2lf", x, y);
}
void dengyu(double delta, double p, double q, double a, double b, double c) {
	printf("\n��������ȵ�ʵ��\n");
	printf("��ȵ�ʵ��Ϊ: %5.2lf", p);
}
void xiaoyu(double delta, double p,double q,double a,double b,double c) {
	printf("\n������������\n");
	printf("һ��Ϊ: %5.2lf+%5.2lfi\n", p, sqrt(-delta) / (2 * a));
	printf("һ��Ϊ: %5.2lf-%5.2lfi\n", p, sqrt(-delta) / (2 * a));
}

int main() {
	double a, b, c;
	double delta;
	printf("ax^2 + bx + c = 0\n");
	printf("�����뷽�̵Ĳ���a,b,c��\n");
	scanf("%lf %lf %lf", &a,&b,&c);
	double p = -b / (2 * a);
	delta = b * b - 4 * a * c;
	double q = sqrt(delta) / (2 * a);
	if (delta < 0) {
		xiaoyu(delta, p, q,a,b,c);
	}
	else if (delta == 0) {
		dengyu(delta, p, q, a, b, c);
	}
	else {
		dayu(delta, p, q, a, b, c);
	}
	system("pause");
	return 0;
}


//д�����������ֱ�������֤������Լ������С���������������������������������������������������м�������

int Max_Gongyue(int num1, int num2) {
	int max = 1;
	for (int i = 1; i < (num1 > num2 ? num2: num1); i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			max = i;
		}
	}
	return max;
}

int Min_Gongbei(int num1,int num2) {
	int min = num1 > num2 ? num1 : num2;
	int i = min;
	while(min){
		if (i % num1 == 0 && i % num2 == 0) {
			min = i;
			break;
		}
		i++;
	}
	return min;
}

int main() {
	int num1, num2;
	printf("��������������:\n");
	scanf("%d %d", &num1, &num2);
	printf("\n����Ϊ%d��%d\n���Լ��Ϊ:%d\n��С������Ϊ:%d\n", 
		num1, num2, Max_Gongyue(num1, num2), Min_Gongbei(num1, num2));
	system("pause");
	return 0;
}



//��дһ�����򣬽��ַ�����s2�е�ȫ���ַ����Ƶ��ַ�����s1��
//��Ҫ��strcpy����������ʱ��'\0'ҲҪһ�����ƹ�ȥ��'\0'����ַ�������
int main() {
	char s1[20];
	char s2[20];
	gets(s2);
	int i = 0, j = 0;
	for(;s2[i] != '\0';i++){
	//while(s2[i] != '\0'){   //�������������ԣ�for��while���Ի���ת��,�����iҪ��������
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