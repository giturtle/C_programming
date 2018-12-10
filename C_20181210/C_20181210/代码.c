#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
char g_board[ROW][COL];
//对于全局变量，没显式初始化，就会默认初始化为 0 
void menu() {
	while (1) {
		printf("         三子棋\n");
		printf("-----------------------\n");
		printf("1.开始游戏  0.退出游戏\n");
		printf("-----------------------\n");
		int a = 0;
		scanf("%d", &a);
		if (a == 1) {
			break;
		}
		else {
			printf("\n输入有误,请根据选项数字重新输入!\n");
			printf("\n");
			continue;
		}
	}
}
//1.进行棋盘的初始化

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
	printf("请玩家落子！\n");
	while (1) {
		printf("请输入坐标(row col):\n");
		int row, col;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL) {
			printf("输入的坐标非法，请重新输入！\n");
			continue;
		}
		if (g_board[row][col] != ' ') {
			printf("当前位置已经有子，请重新输入！\n");
			continue;
		}
		g_board[row][col] = 'x';
		break;
	}
}

void ComputerMove() {
	printf("请电脑落子!\n");
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
	//检查行列斜线是否可以连成三个
	//行
	for (int row = 0; row < ROW; ++row) {
		if (g_board[row][0] == g_board[row][1] &&
			g_board[row][0] == g_board[row][2] &&
			g_board[row][0] != ' ') {
			return g_board[row][0];
		}
	}
	//列
	for (int col = 0; col < COL; ++col) {
		if (g_board[0][col] == g_board[1][col] &&
			g_board[0][col] == g_board[2][col] &&
			g_board[0][col] != ' ') {
			return g_board[0][col];
		}
	}
	//斜
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
	//判断和棋情况
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
	//2.打印棋盘
	char winner;
	while (1) {

		//winner -> x 玩家胜
		//winner -> o 电脑胜
		//winner -> ' '胜负未分
		//winner -> q 和棋
		//3.玩家落子，判定是否游戏结束
		PlayerMove();
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
		Print();
		//4.电脑落子，判定是否游戏结束
		ComputerMove();
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
		Print();
	}
	if (winner == 'x') {
		printf("玩家胜\n");
		Print();
	}
	else if (winner == 'o') {
		printf("电脑胜\n");
		Print();
	}
	else {
		printf("和棋\n");
		Print();
	}
	system("pause");
	return 0;
}
