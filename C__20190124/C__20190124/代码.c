#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



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