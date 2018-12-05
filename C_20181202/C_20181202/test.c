#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 10
#define MAX_COL 10
#define DEFAULT_MINE_COUNT 10

int Menu() {
	printf("=============================\n");
	printf("||        <ɨ����Ϸ>       ||\n");
	printf("||  1.��ʼ��Ϸ 0.�˳���Ϸ  ||\n");
	printf("=============================\n");
	int choice = 0;
	while (1) {
		scanf("%d", &choice);
		if (choice != 0 && choice != 1) {
			printf("������������,����������!\n");
			continue;
		}/*
		 if (choice == 0){
		 break;
		 }*/
		return choice;
	}
}



void Init(char show_map[MAX_ROW + 2][MAX_COL + 2],
	char mine_map[MAX_ROW + 2][MAX_COL + 2]) {
	for (int row = 0; row < MAX_ROW + 2; ++row) {
		for (int col = 0; col < MAX_COL + 2; ++col) {
			show_map[row][col] = '*';
		}
	}
	for (int row = 0; row < MAX_ROW + 2; ++row) {
		for (int col = 0; col < MAX_COL + 2; ++col) {
			mine_map[row][col] = '0';
		}
	}
	//�ܹ�����Ĺ���� N ����,����������
	int mine_count = DEFAULT_MINE_COUNT;
	while (mine_count > 0) {
		//������õ���
		int row = rand() % MAX_ROW + 1;
		int col = rand() % MAX_COL + 1;
		if (mine_map[row][col] == '1') {
			continue;
		}
		mine_map[row][col] = '1';
		--mine_count;
	}
}

void DisplayMap(char map[MAX_ROW + 2][MAX_COL + 2]) {
	printf("   ");
	//��ӡ�������
	for (int row = 1; row <= MAX_ROW; ++row) {
		printf("%d ", row);
	}
	printf("\n");
	//��ӡ�ϱ߿�
	for (int row = 1; row <= MAX_ROW; ++row) {
		printf("---");
	}
	printf("\n");
	for (int row = 1; row <= MAX_ROW; ++row) {
		printf("%02d|", row);
		for (int col = 1; col <= MAX_COL; ++col) {
			printf("%c ", map[row][col]);
		}
		printf("\n");

	}
	printf("\n");
	printf("\n");
	printf("\n");

}

void UpdateShowMap(char show_map[MAX_ROW + 2][MAX_COL + 2],
	char mine_map[MAX_ROW + 2][MAX_COL + 2], int row, int col) {
	//�������Ҫ����mine_map������row,colλ������Χ���м�������
	//�ѽ��д����Ӧ��show_mapλ����
	//===========�˴���8��λ�ö�Ӧ���±겻��Խ��======
	//===========��Ϊ������һȦ�߿�===================
	//row��colȡֵ��[1,MAX_ROW]
	//�����±�ȡֵΪ[0,MAX_ROW + 1]

	int mine_count = 0;
	for (int i = row - 1; i <= row + 1; ++i) {
		for (int j = col - 1; j <= col + 1; ++j) {
			mine_count =
				mine_map[i - 1][j - 1] - '0' +
				mine_map[i - 1][j] - '0' +
				mine_map[i - 1][j + 1] - '0' +
				mine_map[i][j - 1] - '0' +
				mine_map[i][j + 1] - '0' +
				mine_map[i + 1][j - 1] - '0' +
				mine_map[i + 1][j] - '0' +
				mine_map[i + 1][j + 1] - '0';

			if (mine_map[i][j] == '1') {
				show_map[i][j] = '*';
			}
			else {
				show_map[i][j] = '0' + mine_count;
			}
		}
	}
}



void Game() {
	//�����һ��ɨ����Ϸ
	//������ά��������ʾ��ͼ
	//��һ�������ʾ�����չʾ�ĵ�ͼ
	//�˴�����һȦ�߿�
	//����show_map:����Ԫ����2�����:
	//1.���λ��û�б��ƿ�,�� * ��ʾ
	//2.���λ���Ѿ����ƿ���,��һ���������������ʾ
	//(�ַ�'2'����ʾ)
	char show_map[MAX_ROW + 2][MAX_COL + 2];
	//�ڶ��������ʾ����
	//����mine_map,�����Ԫ���������:
	//1.���λ���ǵ���,ʹ���ַ�'1'��ʾ
	//2.���λ�ò��ǵ���,ʹ���ַ�'0'��ʾ
	char mine_map[MAX_ROW + 2][MAX_COL + 2];
	int blank_count = 0;
	//1.��������������г�ʼ��
	//2.��ӡ��ʼ��ͼ
	Init(show_map, mine_map);
	DisplayMap(show_map);
	while (1) {
		//3.�������������,�ж��Ƿ�Ϸ�
		int row, col;
		printf("����������:\n");
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > MAX_ROW
			|| col <= 0 || col > MAX_COL) {
			printf("�������벻�Ϸ�,��������!\n");
			continue;
		}
		//4.�ж�����Ƿ����,�����,��Ϸ����
		if (mine_map[row][col] == '1') {
			printf("��Ϸ����!\n");
			printf("ɨ��ʧ��!\n");
			DisplayMap(mine_map);
			break;
		}

		//5,���û����,�ж��Ƿ��ƿ���ȫ������(���ʤ��)
		//6.��ͳ�Ƹ�λ����Χ�м�����,����������ָ��µ���ͼ��
		UpdateShowMap(show_map, mine_map, row, col);
		DisplayMap(show_map);
		int blank_cnt = 0;
		for (row = 1; row <= MAX_ROW; ++row)
		{
			for (col = 1; col <= MAX_COL; ++col)
			{
				if (show_map[row][col] != '*')
				{
					++blank_cnt;
					if (blank_cnt == MAX_ROW * MAX_COL - DEFAULT_MINE_COUNT)
					{
						DisplayMap(mine_map);
						printf("ɨ�׳ɹ�����Ϸ����\n");
						break;
					}
				}
			}
		}
		printf("\n");
	}
}

void Start() {
	//������Ϸ��ں���,��Ϸ�˵�
	while (1) {
		int choice = Menu();
		if (choice == 0) {
			break;
		}
		Game();
	}
}

int main() {
	Start();
	system("pause");
	return 0;
}

