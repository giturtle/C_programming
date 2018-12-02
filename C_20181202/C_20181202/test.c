#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 10
#define MAX_COL 10
#define DEFAULT_MINE_COUNT 10

int Menu() {
	printf("=============================\n");
	printf("||        <扫雷游戏>       ||\n");
	printf("||  1.开始游戏 0.退出游戏  ||\n");
	printf("=============================\n");
	int choice = 0;
	while (1) {
		scanf("%d", &choice);
		if (choice != 0 && choice != 1) {
			printf("您的输入有误,请重新输入!\n");
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
	//能够随机的构造出 N 个数,放在雷阵中
	int mine_count = DEFAULT_MINE_COUNT;
	while (mine_count > 0) {
		//随机布置地雷
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
	//打印坐标横行
	for (int row = 1; row <= MAX_ROW; ++row) {
		printf("%d ", row);
	}
	printf("\n");
	//打印上边框
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
	//这个函数要根据mine_map来计算row,col位置上周围是有几个地雷
	//把结果写到对应的show_map位置上
	//===========此处这8个位置对应的下标不会越界======
	//===========因为引入了一圈边框===================
	//row和col取值是[1,MAX_ROW]
	//数组下标取值为[0,MAX_ROW + 1]

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
	//具体的一局扫雷游戏
	//两个二维数组来表示地图
	//第一个数组表示给玩家展示的地图
	//此处加上一圈边框
	//对于show_map:里面元素有2种情况:
	//1.这个位置没有被掀开,用 * 表示
	//2.这个位置已经被掀开了,用一个具体的数字来表示
	//(字符'2'来表示)
	char show_map[MAX_ROW + 2][MAX_COL + 2];
	//第二个数组表示雷阵
	//对于mine_map,里面的元素以下情况:
	//1.这个位置是地雷,使用字符'1'表示
	//2.这个位置不是地雷,使用字符'0'表示
	char mine_map[MAX_ROW + 2][MAX_COL + 2];
	int blank_count = 0;
	//1.对这两个数组进行初始化
	//2.打印初始地图
	Init(show_map, mine_map);
	DisplayMap(show_map);
	while (1) {
		//3.让玩家输入坐标,判定是否合法
		int row, col;
		printf("请输入坐标:\n");
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > MAX_ROW
			|| col <= 0 || col > MAX_COL) {
			printf("您的输入不合法,重新输入!\n");
			continue;
		}
		//4.判断玩家是否踩雷,如果是,游戏结束
		if (mine_map[row][col] == '1') {
			printf("游戏结束!\n");
			printf("扫雷失败!\n");
			DisplayMap(mine_map);
			break;
		}

		//5,如果没踩雷,判定是否掀开了全部格子(玩家胜利)
		//6.就统计该位置周围有几个雷,并把这个数字更新到地图上
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
						printf("扫雷成功，游戏结束\n");
						break;
					}
				}
			}
		}
		printf("\n");
	}
}

void Start() {
	//这是游戏入口函数,游戏菜单
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

