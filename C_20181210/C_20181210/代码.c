#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
char g_board[ROW][COL];
//����ȫ�ֱ�����û��ʽ��ʼ�����ͻ�Ĭ�ϳ�ʼ��Ϊ 0 
void menu() {
	while (1) {
		printf("         ������\n");
		printf("-----------------------\n");
		printf("1.��ʼ��Ϸ  0.�˳���Ϸ\n");
		printf("-----------------------\n");
		int a = 0;
		scanf("%d", &a);
		if (a == 1) {
			break;
		}
		else {
			printf("\n��������,�����ѡ��������������!\n");
			printf("\n");
			continue;
		}
	}
}
//1.�������̵ĳ�ʼ��

int Isfull() {
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COL; ++col) {
			if (g_board[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
void Init() {
	srand((unsigned int)time(0));
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COL; ++col) {
			g_board[row][col] = ' ';
		}
	}
}
void Print() {
	printf("|---|---|---|\n");
	for (int row = 0; row < ROW; ++row) {
		printf("| %c | %c | %c |\n", g_board[row][0],
			g_board[row][1], g_board[row][2]);
		printf(" ---|---|--- \n");
	}
}

void PlayerMove() {
	printf("��������ӣ�\n");
	while (1) {
		printf("����������(row col):\n");
		int row, col;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL) {
			printf("���������Ƿ������������룡\n");
			continue;
		}
		if (g_board[row][col] != ' ') {
			printf("��ǰλ���Ѿ����ӣ����������룡\n");
			continue;
		}
		g_board[row][col] = 'x';
		break;
	}
}

void ComputerMove() {
	printf("���������!\n");
	while (1) {
		int row = rand() % ROW;
		int col = rand() % ROW;
		if (g_board[row][col] != ' ') {
			continue;
		}
		g_board[row][col] = 'o';
		break;
	}
}


char CheckWinner() {
	//�������б���Ƿ������������
	//��
	for (int row = 0; row < ROW; ++row) {
		if (g_board[row][0] == g_board[row][1] &&
			g_board[row][0] == g_board[row][2] &&
			g_board[row][0] != ' ') {
			return g_board[row][0];
		}
	}
	//��
	for (int col = 0; col < COL; ++col) {
		if (g_board[0][col] == g_board[1][col] &&
			g_board[0][col] == g_board[2][col] &&
			g_board[0][col] != ' ') {
			return g_board[0][col];
		}
	}
	//б
	if (g_board[0][0] == g_board[1][1] &&
		g_board[0][0] == g_board[2][2] &&
		g_board[0][0] != ' ') {
		return g_board[0][0];
	}
	if (g_board[0][2] == g_board[1][1] &&
		g_board[0][2] == g_board[2][0] &&
		g_board[0][2] != ' ') {
		return g_board[0][2];
	}
	//�жϺ������
	/*for (int row = 0; row < ROW; ++row){
		for (int col = 0; col < COL; ++col){
		if (g_board[row][col] == ' '){
		return ' ';
		}
		}
		}
		return 'q';*/
	if (Isfull()) {
		return 'q';
	}
	return ' ';

}



int main() {
	menu();
	Init();
	Print();
	//2.��ӡ����
	char winner;
	while (1) {

		//winner -> x ���ʤ
		//winner -> o ����ʤ
		//winner -> ' 'ʤ��δ��
		//winner -> q ����
		//3.������ӣ��ж��Ƿ���Ϸ����
		PlayerMove();
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
		Print();
		//4.�������ӣ��ж��Ƿ���Ϸ����
		ComputerMove();
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
		Print();
	}
	if (winner == 'x') {
		printf("���ʤ\n");
		Print();
	}
	else if (winner == 'o') {
		printf("����ʤ\n");
		Print();
	}
	else {
		printf("����\n");
		Print();
	}
	system("pause");
	return 0;
}
