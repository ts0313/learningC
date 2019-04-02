//简易扫雷小游戏的实现
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int Menu() {												//打印菜单
	printf("======================================\n");
	printf("============ 1. 开始游戏 =============\n");
	printf("============ 0. 退出游戏 =============\n");
	printf("======================================\n");
	printf("============ 请输入您的选择! =========\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define MAX_ROW 9								//宏定义行数
#define MAX_COL 9								//宏定义列数
#define MINE_COUNT 10							//宏定义雷的个数

void Init(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]) {		//初始化棋盘
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			show_map[row][col] = '*';
		}
	}
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			mine_map[row][col] = '0';
		}
	}
	int n = MINE_COUNT;
	while (n > 0) {									//随机生成雷的分布
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '1') {
			continue;
		}
		mine_map[row][col] = '1';
		--n;
	}
}

void PrintMap(char map[MAX_ROW][MAX_COL]) {					//打印棋盘
	printf("    ");
	for (int i = 0; i < MAX_COL; ++i) {
		printf("%d ", i);
	}
	printf("\n");
	for (int row = 0; row < MAX_ROW; ++row) {
		printf(" %d| ", row);
		for (int col = 0; col < MAX_COL; ++col) {
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}

void UpdateShowMap(int row, int col, char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]) {
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0
		&& row - 1 < MAX_ROW && col - 1 < MAX_COL
		&& mine_map[row - 1][col - 1] == '1') {
		++count;
	}
	if (row - 1 >= 0 && col >= 0
		&& row - 1 < MAX_ROW && col < MAX_COL
		&& mine_map[row - 1][col] == '1') {
		++count;
	}
	if (row - 1 >= 0 && col + 1 >= 0
		&& row - 1 < MAX_ROW && col + 1 < MAX_COL
		&& mine_map[row - 1][col + 1] == '1') {
		++count;
	}
	if (row >= 0 && col - 1 >= 0
		&& row < MAX_ROW && col - 1 < MAX_COL
		&& mine_map[row][col - 1] == '1') {
		++count;
	}
	if (row >= 0 && col + 1 >= 0
		&& row < MAX_ROW && col + 1 < MAX_COL
		&& mine_map[row][col + 1] == '1') {
		++count;
	}
	if (row + 1 >= 0 && col - 1 >= 0
		&& row + 1 < MAX_ROW && col - 1 < MAX_COL
		&& mine_map[row + 1][col - 1] == '1') {
		++count;
	}
	if (row + 1 >= 0 && col >= 0
		&& row + 1 < MAX_ROW && col < MAX_COL
		&& mine_map[row + 1][col] == '1') {
		++count;
	}
	if (row + 1 >= 0 && col + 1 >= 0
		&& row + 1 < MAX_ROW && col + 1 < MAX_COL
		&& mine_map[row + 1][col + 1] == '1') {
		++count;
	}
	show_map[row][col] = '0' + count;
}

void Game() {
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	int blank_count_already_show = 0;
	Init(show_map, mine_map);
	while (1) {
		PrintMap(show_map);
		printf("请输入一组坐标(row col): ");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		system("cls");
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("您的输入有误,请重新输入!\n");
			continue;
		}
		if (show_map[row][col] != '*') {
			printf("您输入的坐标已经翻开了!\n");
			continue;
		}
		if (mine_map[row][col] == '1') {
			printf("游戏结束!\n");
			PrintMap(mine_map);
			break;
		}
		++blank_count_already_show;
		if (blank_count_already_show == MAX_ROW * MAX_COL - MINE_COUNT) {
			printf("游戏胜利!\n");
			PrintMap(mine_map);
			break;
		}
		UpdateShowMap(row, col, show_map, mine_map);
	}
}

int main() {
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			Game();
		}
		else if (choice == 0) {
			printf("Goodbye!\n");
			break;
		}
		else {
			printf("您的输入有误!\n");
		}
	}
	system("pause");
	return 0;
}