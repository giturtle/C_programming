#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
��д����ʵ�ֽ��ַ���str2�������ַ���str1
int main() {
	char str1[256];
	char str2[256];
	int i;
	printf("�������ַ���:\n");
	gets(str2);
	for (i = 0; str2[i]; i++) {
		str1[i] = str2[i];
	}
	str1[i] = '\0';
	û������������ ������ ,��������Ҫ�ص����
	printf("���ƺ���ַ�����:%s\n", str1);
	system("pause");
	return 0;
}



//ĳ�����������ո߳�������:���޴ͺ���?����Ի:ֻ�������̵ĵ�һ���з�1����,�ڶ����2��
//���ÿ����һ��,�����ӱ�,�����½���64���й�������΢��
//̰�����������ù�������? 2 ^ 63
int main() {
	//����ͨ�ı�������ͻ����
	int a[64] = { 1 }; 
	int i, j, n, t; //���� n ��Ż���λ��
	for (i = 1, n = 1; i <= 63; i++) {  //����2 ^ 63�η���ֵ
		t = 0;	//���� t ��Ž�λ
		for (j = 0; j < n; j++) {
			a[j] = 2 * a[j] + t;	//��ǰ������(����a)��ÿһλ�� 2 �ӽ�λ
			t = a[j] / 10;
			if (t > 0) {
				a[j] = a[j] % 10;
			}
		}
		if (t > 0) {	//������λ�н�λ,��ǰ��������λ���� 1
			a[n++] = 1;
		}
	}//�����������ÿһλ,��λ����� a[0] ��,���λ����� a[n - 1]Ԫ����
	for (i = n - 1; i >= 0; i--) {
		printf("%d", a[i]);
	}
	system("pause");
	return 0;
}




//(�����е�С����)
//������������,��-1��������,����Щ���������a��,�����
//���ҳ�a���������е�������������b
//����ÿ��5��Ԫ�صĸ�ʽ�ɴ�С�����Щ����
int main() {
	int a[15], b[15];
	int x,i,j,m = 0,n = 0;
	int swap, temp;
	printf("������15�����ڵ�����,��-1��������:\n");
	scanf("%d", &x);
	while (x != -1) {
		a[n++] = x;
		scanf("%d", &x);
	}
	for (i = 0; i < n; ++i) {
		for (j = 2; j <= a[i] - 1; j++) {
			if (a[i] && j == 0) {
				break;
			}
		}
		if (j == a[i]) {
			b[m++] = a[i];
		}
	}
	
	for (i = 0; i < m - 1; ++i) {
		swap = 0;
		for (j = 0; j < m - i - 1; j++) {
			if (b[j] > b[j + 1]) {
				swap = 1;
				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
			if (!swap) {
				break;
			}
		}
	}
	printf("��������Ϊ:\n");
	for (i = 0, j = 0; i < m; i++) {
		j++;
		printf("%8d", b[i]);
		if (j % 5 == 0) {
			printf("\n");
		}
	}
	system("pause");
	return 0;
}


//(δ���)��Ҫ�޸�,��Сȱ��
//������A�е�N(0<N<100)��������С��������������
//Ҫ��:���ܸı�����A��Ԫ�ص�˳��,����ͬ������������ͬ�ı��
//��:A����{5,3,4,7,3,5,6}
//�����Ϊ3,1,2,5,1,3,4
int main() {
	int i, j, n;
	int a[100], code[100] = { 0 };
	int min, max, end, count = 0;
	printf("�����������ĸ���n (0 < n <100)\n");
	scanf("%d", &n);
	printf("������%d������:\n", n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (i == 0) {
			max = a[0];
		}
		else if (a[i] > max) {
			max = a[i];
		}
	}
	while (1) {
		min = max + 1;
		end = 1;
		for (i = 0; i < n; ++i) {
			if ((a[i] < min) && (code[i] == 0)) {
				min = a[i];
				end = 0;
			}
			if (!end) {
				count++;
				for (i = 0; i < n; ++i) {
					if (a[i] == min) {
						code[i] = count;
					}
				}
			}
			if (end)
				break;
		}

		for (i = 0; i < n; ++i) {
			printf("%d ", code[i]);
		}
		system("pause");
		return 0;
	}
}



//��1000�����˺ŵĲ�Ʒ,��Ŵ�1001��2000
//���������ȡ10����Ʒ������
//��д����,��С�����������ȡ�Ĳ�Ʒ���
int main() {
	int i, j, k;
	int a[1000], temp;
	for (i = 0; i < 1000; ++i) {
		a[i] = 1001 + i;
	}
	for (i = 0; i < 10; ++i) {
		k = i + rand(1000 - i);
		temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
	//��ѡ�񷨶�a����ǰ 10 ��Ԫ�ؽ�������
	for (i = 0; i < 10 - 1; i++) {
		k = i;
		for (j = i + 1; j < 10; j++) {
			if (a[k] > a[j]) {
				k = j;
			}
			if (k != i) {
				temp = a[i];
				a[i] = a[k];
				a[k] = temp;
			}
		}
		printf("����ȡ�Ĳ�Ʒ���Ϊ:\n");
		for (i = 0; i < 10; i++) {
			printf("%4d", a[i]);
		}
		printf("\n");

	}
	system("pause");
	return 0;
}

//����10����������������,�ҳ�������С���ʹ���С��
int main() {
	int a[10];
	int i;
	printf("������10������:\n");
	for (i = 0; i < 10; ++i) {
		scanf("%d", &a[i]);
	}
	int min1, min2;
	min1 = a[0] < a[1] ? a[0] : a[1];
	min2 = a[0] < a[1] ? a[1] : a[0];
	for (i = 2; i < 10; ++i) {
		if (a[i] < min1) {
			min2 = min1;
			min1 = a[i];
		}
		else if (a[i] < min2)
			min2 = a[i];
	}
	printf("10������С����%d,����С����%d\n", min1, min2);
	system("pause");
	return 0;
}