#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//ʵ��һ�����������������ַ�����k���ַ�
//ABCD����1���ַ��õ�BCDA
//ABCD����2���ַ��õ�CDAB

//����1
void left_rotate(char *str, int k) {
	while (k--) {
		//�ȱ������ַ�
		char temp = *str;
		char *cur = str;
		//�ַ���ǰŲ��һ��λ��
		while (*(cur + 1)) {
			*cur = *(cur + 1);
			cur++;
		}
		//���ַ������ַ������һ��λ��
		*cur = temp;
	}
}

//����2
void reverse(char* left, char* right) {
	//�ַ������������ת
	while (left < right) {
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
void left_rotate2(char *str, int k) {
	//������ת
	//��һ����תǰk���ַ�
	reverse(str, str + k - 1);
	//�ڶ�����תʣ����ַ�
	reverse(str, str + strlen(str) - 1);
	//������������ת
	reverse(str, str + strlen(str) - 1);
}

int main() {
	//char* str = "ABCD"; �������������壬��Ϊ�����ǲ������޸ĵ�
	char str[] = "ABCD";
	int k;
	scanf("%d", &k);
	printf("%s\n", str);
	left_rotate(str, k);
	printf("%s\n", str);
	left_rotate2(str, k);
	printf("%s\n", str);
	system("pause");
	return 0;
}


//��һ����λ���飬�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����
//�������������в���һ�������Ƿ���ڣ�ʱ�临�Ӷ�С��O(N)
int find(int a[3][3], int row, int col, int key, int *px, int *py) {
	//�����Ͻǿ�ʼ����
	int x = 0;
	int y = col - 1;
	//�����½���������(�����½ǿ�ʼ��Ч����΢��ͬ)
	while (x < row && y >= 0) {
		if (a[x][y] == key) {
			//�������
			*px = x;
			*py = y;
			return 1;//��ʾ�ҵ��ˣ�
		}
		else if (a[x][y] > key) {
			//��������
			y--;
		}
		else {
			//��������
			x++;
		}
	}
	//������Чֵ
	*px = -1;
	*py = -1;
	return 0;
}

int main() {
	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int to_find;
	int px, py;
	scanf("%d", &to_find);
	if (find(a, 3, 3, to_find, &px, &py)) {
		printf("%d,%d\n", px, py);
	}
	else {
		printf("%d������\n", to_find);
	}
	system("pause");
	return 0;
}