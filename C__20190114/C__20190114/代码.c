#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



//��һ�е��ģ��Ѱ���������������
//A �� Z ��B �� Y�� C �� X
//a �� z ��b �� y�� c �� x
//����һ����ĸ����˵�26����ĸ����i����ĸ����˵ڣ�26-i+1������ĸ������ĸ�ַ����䣬Ҫ���̽��������ԭ�ģ�����������ԭ��
int main() {
	char arr[20];
	int i = 0;
	printf("����������:\n");
	gets(arr);
	printf("\n\n============\n");
	printf("����Ϊ:\n");
	puts(arr);
	for (; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
		if (arr[i] >= 'a' && arr[i] <= 'z')
			arr[i] = 27 - (arr[i] - 96) + 96;
		if (arr[i] >= 'A' && arr[i] <= 'Z')
			arr[i] = 27 - (arr[i] - 64) + 64;
	}
	printf("\n����ԭ��Ϊ��\n");
	puts(arr);
	printf("============\n\n");
	system("pause");
	return 0;
}


//��15��������С����˳������һ�������У�����һ����
//Ҫ�����۰���ҷ��ҳ������������еڼ���Ԫ�ص�ֵ���������������������޴�����
int main() {
	int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int to_found, mid;
	printf("������Ҫ���ҵ�ֵ:\n");
	scanf("%d", &to_found);
	int left = 0;
	int right = (sizeof(arr) / sizeof(arr[0])) - 1;
	//while(left < right){
	//������ʹ�����while���
	for(int i = 0; i < sizeof(arr) / sizeof(arr[0]);i++){
		//�����ж�����������д < right����Ϊrightֵ�ڱ仯
		mid = (left + right) / 2;
		if (to_found < arr[mid]) {
			right = mid - 1;
		}
		else if (to_found > arr[mid]) {
			left = mid + 1;
		}
		else {
			break;
		}
	}
	if (left <= right) {
		printf("�ҵ��ˣ��±�Ϊ%d\n", mid);
	}
	else {
		printf("�޴���\n");
	}
	system("pause");
	return 0;
}


//�ҳ�һ����ά�����еİ��㣬��λ�õ�Ԫ���ڸ�������ڸ�����С��Ҳ����û�а���
#define M 100
#define N 100
int main() {
	int m, n;
	int arr[M][N];
	int row, col;
	int flag = 0;//�������0��ʾ û�а���
	printf("��������������m������n:\n");
	scanf("%d %d", &m, &n);
	printf("������%d�� %d�еľ���:\n", m, n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < m; ++i) {
		//���ҳ��� i �����Ԫ�� a[i][col]
		col = 0;
		for (int j = 1; j < n; ++j) {
			if (arr[i][j] > arr[i][col]) {
				col = j;
			}
		}
		//�ҳ���col����СԪ�� a[row][col];
		row = 0;
		for (int j = 1; j < n; ++j) {
			if (arr[row][col] > arr[j][col]) {
				row = j;
			}
		}
		//��������Ԫ���ڵ�row��,���row����i,�������ǰ���
		if (row == i) {
			flag = 1;
			printf("����������±���:%d,%d\n����ֵ��:%d\n", row, col, arr[row][col]);
		}
	}
	if (!flag) {
		printf("û�а���!\n");
	}
	system("pause");
	return 0;
}

//�ҵĴ���
#define N 3
int main() {
	int arr[N][N];
	int i = 0, j = 0, max, min, m, n;
	printf("�����ά�����е�Ԫ��:\n");
	for (; j < N; i++) {
		for (; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0; i < N; i++) {
		for (max = arr[i][j], m = 0, n = j = 0; j < N; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
				m = i;
				n = j;
			}
		}
		for (min = arr[m][n], j = 0; j < N; j++) {
			if (arr[j][n] < min)
				break;
			else {
				continue;
			}
		}
		if (j + 1 == N) {
			printf("����Ϊ%d���±���%d��%d��\n", arr[m][n], m, n);
		}
	}
	system("pause");
	return 0;
}


//����ħ������νħ������ָ�����ķ�������ÿһ�С�ÿһ�кͶԽ���֮�;����
//���磺
// 8  1  6
// 3  5  7
// 4  9  2
//Ҫ�����1 ~ n^2����Ȼ�����ɵ�ħ����

//  ��ħ����    ���й���
//�Ž�1���ڵ�һ���м�һ�У�
//�ƴ�2��ʼֱ��n��nֹ�������ΰ����й����ţ�ÿһ������ŵ��б�ǰһ������������1��������1���������������ħ����5��4����һ�к�һ�У���
//�������һ����������Ϊ1������һ����������Ϊn��ָ����һ�У�������1�ڵ�һ�У���2Ӧ��������һ�У�����ͬ����1��
//�ȵ���һ����������Ϊnʱ����һ����������ӦΪ1��������ȥ1������2�ڵ�3�����һ�У���3Ӧ���ڵڶ��е�һ�У�
//��������������ȷ����λ����������������һ�����ǵ�һ�е�n��ʱ�������һ����������һ���������档���簴����Ĺ涨��4Ӧ�÷��ڵ�1�е�2�У�����λ���Ѿ���ռ�ݣ�����4�ͷ���3�����档

//��
#define N 100
int main(){
	int a[N][N], i, j, n, m, x, y;
	//��ά����ĳ�ʼ������һά����һ��ֱ������ȫ 0 
	//����ʹ��ѭ��������ֵ
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			a[i][j] = 0;
		}
	}
	printf("������ħ������n (n<100):");//��������
	//����ż�� �������ȷ.
	scanf("%d", &n);


	//���߼���ʼ
	i = 0, j = n / 2;
	//�� 1 ���ڵ�һ���м�
	a[i][j] = 1;
	//Ȼ��� 2 ��ʼ��
	for (m = 2; m <= n * n; m++){
		//x��y����������һ�������±�
		x = i;  
		y = j;
		i = (i - 1 + n) % n;
		j = (j + 1) % n;
		if (a[i][j] == 0){	//�����ʱΪ0��˵��û�б��Ź�ֵ��ֱ�ӷ���
			a[i][j] = m;
		}
		else{
			a[++x][y] = m;	//�������ǰһ���������棬������ +1
			i = x;
			j = y;
		}
	}

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%-3d", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


//��20+�м򻯺�����
#define ROW 10
void MagicSqaure(int(*arr)[ROW])
{
	assert(ROW % 2 != 0);
	arr[0][ROW / 2] = 1;

	int preRow = 0;
	int preCol = ROW / 2;

	for (int i = 2; i <= ROW * ROW; i++)
	{
		if (arr[(preRow - 1 + ROW) % ROW][(preCol + 1) % ROW] != 0)
		{
			preRow = (preRow + 1) % ROW;
		}
		else
		{
			preRow = (preRow - 1 + ROW) % ROW;
			preCol = (preCol + 1) % ROW;
		}
		arr[preRow][preCol] = i;
	}
}


//���10���������
//1
//1 1
//1 2 1
//1 3 3 1
//...
int main() {
	int arr[10][10];
	int i, j;
	for (i = 0; i < 10; i++) {
		arr[i][i] = 1;
		arr[i][0] = 1;
	}
	for (i = 2; i < 10; i++) {
		for (j = 1; j < i; j++) {	
			//����jҪС��i����� <= i���ͻ����õ�a[i][i]ֵ����
			//����������ֵ����Ϊa[i-1][j]���ֵ����һ����Խ���
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j <= i; j++) {
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}



//��һ�������е�ֵ�����������´��
//���磬ԭ��˳��Ϊ8,6,5,4,1 �� Ҫ���Ϊ1,4,5,6,8
#define num 6
//Ҫ����ĺ궨�����֣���Ҫ��main�����е�����Ԫ�ظ�����Ӧ
int main() {
	int arr[num] = { 8,6,5,4,1,3 };
	int temp = 0;
	for (int i = 0; i < num / 2; i++) {
		int j = (num - 1) - i;
		temp = arr[i];
		arr[i]= arr[j];
		arr[j] = temp;
	}
	for (int i = 0; i < num; i++) {
		printf("%3d", arr[i]);
	}
	system("pause");
	return 0;
}
