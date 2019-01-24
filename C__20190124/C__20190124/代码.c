#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//�ж�һ���ַ����Ƿ�����һ���ַ�����ת֮����ַ���
//s1 = AABCD , s2 = BCDAA ����1
//s1 = abcd �� s2 = ABCD ����0
int is_rotate(char* dest, char* src) {		//��Ҫ�����е���������
	void right_rotate(char* str, int k);
	if (strlen(dest) != strlen(src)) {
		return 0;
	}
	int len = strlen(src);
	while (len--) {
		right_rotate(src, 1);
		if (strcmp(dest, src) == 0) {
			return 1;
		}
	}
	return 0;
}
int main() {
	char dest[100];
	char src[100];
	scanf("%s", dest);
	scanf("%s", src);
	printf("%d\n", is_rotate(dest, src));
	system("pause");
	return 0;
}



//ABCD --> ����1�� -->DABC �൱�� ����3��
//����K�� --> ����strlen(str) - k��
void reverse(char* left, char* right) {
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_rotate(char* str, int k) {
	//������ת
	//��һ�η�תǰk���ַ�
	reverse(str, str + k - 1);
	//�ڶ��η�תʣ�µ��ַ�
	reverse(str + k, str + strlen(str) - 1);
	//���������巭ת
	reverse(str, str + strlen(str) - 1);
}
void right_rotate(char* str, int k) {
	left_rotate(str, strlen(str) - k);
}

int main() {
	char str[] = "ABCDEF";
	int k;
	scanf("%d", &k);
	printf("%s\n", str);
	left_rotate(str, k);
	printf("%s\n", str);
	right_rotate(str, k);
	printf("%s\n", str);
	system("pause");
	return 0;
}



//���ݹ�汾��
//��һ����λ���飬�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����
//�������������в���һ�������Ƿ���ڣ�ʱ�临�Ӷ�С��O(N)

//�����½ǿ�ʼ����
int find_r(int a[3][3], int row, int col, int x, int y, int key, int* px, int* py) {
	//�ҵ����Ͻǻ�û���ҵ�,��������
	if (x < 0 || y >= col)
		return -1;
	//key > a[x][y]ʱ����������
	if (key > a[x][y]) {
		return find_r(a, row, col, x, ++y, key, px, py);
	}
	//key < a[x][y]ʱ����������
	else if (key < a[x][y]) {
		return find_r(a, row, col, --x, y, key, px, py);
	}
	else if (key == a[x][y]) {
		*px = x;
		*py = y;
		return 1;
	}
}

int main() {
	int a[3][3] = {1,2,3,4,5,6,7,8,9};
	int row, col;
	printf("�����С�����:\n");
	scanf("%d %d", &row, &col);
	int px, py;
	printf("��������ֵ:\n");
	int key;
	scanf("%d", &key);
	//���½�
	if (find_r(a, row, col, row-1, 0, key, &px, &py)) {	//row - 1��0�൱����ʼ�㣬���½�
		printf("%d,%d\n", px, py);
	}
	else {
		printf("%d������\n",key);
	}
	system("pause");
	return 0;
}