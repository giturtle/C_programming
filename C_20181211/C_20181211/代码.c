#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
�Ľ�֮ǰ��ϰ���ִ���

//��������ʹ����ȫ����λ��ż��ǰ��
//ʵ��һ������,��������λ������ǰ�벿��,ż����벿��
//��ͷ��һ��ż������
//��β��һ����������
//��������λ��
//ͷָ��++,βָ��--

void reverse_array(int a[], int n) {
	int left = 0;
	int right = n - 1;
	while (left < right) {
		//���������ҵ�һ��ż��
		while (left < right && a[left] % 2 != 0) {
			left++;
		}
		//���������ҵ�һ������
		while (left < right && a[right] % 2 == 0) {
			right--;
		}
		//������ ������żֵ
		if (left < right) {
			a[left] = a[left] ^ a[right];
			a[right] = a[left] ^ a[right];
			a[left] = a[left] ^ a[right];
		}
	}
}
int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	reverse_array(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}



//��һ���ַ����������Ϊ:"student a am i", 
//���㽫��������ݸ�Ϊ"i am a student". 
//Ҫ��:
//1.����ʹ�ÿ⺯��,��Ҫ�Լ���������
//2.ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ�
//student a am i  -->  i ma a tneduts -->  i am a student
//Ҳ���� : ������ת + �ֲ���ת

//���õ����ַ����ĳ���
int my_strlen(char* str) {
	int count = 0;
	while (*str++) {
		count++;
	}
	return count;
}

//������ת:��תָ����Χ�ڵ��ַ���
void reverse_string(char* start,char* end) {
	//char* start = str;
	//char* end = str + my_strlen(str) - 1;
	while (start < end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

//�ֲ���ת
void reverse(char* str) {
	int len = my_strlen(str);
	char* start = str;
	char* end = str + len - 1;
	char* cur = str;
	//������ת:
	reverse_string(start, end);
	//�ֲ���ת:
	while (*cur) {
		char* st = cur;
		//Ѱ���Ӵ�β��
		while (*cur != ' ' && *cur != '\0') {
			cur++;
		}
		//��ת�Ӵ�
		reverse_string(st, cur - 1);
		if (*cur == ' ') {
			cur++;
		}
	}
}
int main() {
	char str[100];
	//scanf("%s", str);
	//���ﲻ����scanf����,��Ϊscanf�����տո�,��gets����
	gets(str);
	reverse(str);
	printf("%s", str);
	system("pause");
	return 0;
}



//һ��������ֻ��һ�����ֳ�����һ�Ρ�
//�����������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡�
int find(int a[], int n) {
	// 0 ^ n = n;
	int ret = 0;
	int i;
	for (i = 0; i < n; i++) {
		ret ^= a[i];
	}
	return ret;
}
int main() {
	int a[] = { 1,2,3,0,14,9,8,1,2,3,0,9,8 };
	printf("%d\n", find(a, sizeof(a) / sizeof(a[0])));
	system("pause");
	return 0;
}




//��ʹ�ã�a + b��/2���ַ�ʽ������������ƽ��ֵ
//һ
//(a + b) >> 1 //���������,���մ�
int avg(int a, int b) {
	return (a + b) >> 1;
}
//��
//a + (b - a) >> 1 //�������С
int avg2(int a, int b) {
	return a + ((b - a) >> 1);
}
//��
//��������ƽ��ֵ,�����������ԵĶ�����ÿһλ��ƽ��ֵ
int avg3(int a, int b) {
	return (a & b) + ((a ^ b) >> 1);
}
//a = 1011,b = 1100
//a & b = 1000   a & b�õ�������ͬλ����ƽ��ֵ
//a ^ b = 0111	 a ^ b�õ����ǲ�ͬλ���ܺ� ����Ҫ���� 2
int main() {
	int a = 10, b = 20;
	printf("%d\n", avg(a, b));
	printf("%d\n", avg2(a, b));
	printf("%d\n", avg3(a, b));
	system("pause");
	return 0;
}





//��������,����ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ.

//===========˼·1===========
//�� 1 --> 32     2^31
//�� 2 --> 31     2^30
unsigned int reserve_bit1(unsigned int value) {
	unsigned int sum = 0;
	int i;
	for (i = 0; i < 32; i++) {
		sum += ((value >> i) & 1) * (unsigned)pow(2, 31 - i);
	}
	return sum;
}

//===========˼·2===========
unsigned int reserve_bit2(unsigned int value) {
	unsigned int temp = 0;
	int i;
	for (i = 0; i < 32; i++) {
		//�ڳ�����һλ,���浱ǰλ��ȡ��ֵ
		temp = temp << 1;
		//��value��iλ��ֵ������temp�ĵ�һλ
		temp = temp | ((value >> i) & 1);
		//temp = temp << 1;�����������ͻ�����һλ����ȥ
	}
	return temp;
}
int main() {
	int n = 25;
	printf("%u\n",reserve_bit1(n));
	printf("%u\n", reserve_bit2(n));
	//���Ϊ%u��ʽ
	system("pause");
	return 0;
}



//��ӡ�������
//��i��Ԫ��:i
//a[i][0] = 1,a[i][i] = 1;
//a[i][j] = a[i-1][j-1] + a[i-1][j];
#define N 10
int main() {
	int a[N][N];
	int i, j;
	for (i = 0; i < N; i++) {
		a[i][0] = 1;
		a[i][i] = 1;
	}
	//�� 0 �� 1 �ж������,���Դӵ� 2 �п�ʼ
	//�� 0 �������,�ӵ� 1 �п�ʼ
	for (i = 2; i < N; i++) {
		for (j = 1; j < i; j++) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < 2*(N - i);j++) {
			printf(" ");
		}
		for (j = 0; j <= i; j++) {
			printf("%3d ", a[i][j]);
			//����4����λ�����ֲ� �ո�
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
