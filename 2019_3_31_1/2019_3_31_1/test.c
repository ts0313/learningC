#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void print(int chess[][3])		//��ӡ����
{
	int i = 0;
	int j = 0;
	system("cls");
	printf("======================��������Ϸ=======================\n");
	for (i = 0; i < 3; i++)
	{
		printf("\n			");
		for (j = 0; j < 3; j++)
		{
			if (chess[i][j] == 1)
				printf("X  ");
			else if (chess[i][j] == 0)
				printf("_  ");
			else
				printf("0  ");
		}
		printf("\n");
	}
	printf("\n");
	printf("========================================================\n");
}

void player(int chess[][3])		//�������
{
	int x = 0;
	int y = 0;
	do
	{
		printf("�����������ӵ�����: ");
		scanf("%d %d", &x, &y);
		if (chess[x][y] != 0)
			printf("������������������!\n");
	} while (chess[x][y] != 0);
	chess[x][y] = 1;
}

void computer(int chess[][3])		//��������
{
	int x = 0;
	int y = 0;
	do
	{
		srand((unsigned)time(NULL));
		x = rand() % 3;
		y = rand() % 3;
	} while (chess[x][y] != 0);
	chess[x][y] = 2;
}

int check_winner(int chess[][3])		//�ж�ʤ��
{
	int flag = 0;
	int x = 0;
	int y = 0;
	if ((chess[0][0] == chess[0][1]) && (chess[0][1] == chess[0][2]))
	{
		if (chess[0][0] == 1)
			return 1;
		else if (chess[0][0] == 2)
			return 2;
	}
	if ((chess[1][0] == chess[1][1]) && (chess[1][1]) == chess[1][2])
	{
		if (chess[1][0] == 1)
			return 1;
		else if (chess[1][0] == 2)
			return 2;
	}
	if ((chess[2][0] == chess[2][1]) && (chess[2][1]) == chess[2][2])
	{
		if (chess[2][0] == 1)
			return 1;
		else if (chess[2][0] == 2)
			return 2;
	}
	if ((chess[0][0] == chess[1][0]) && (chess[1][0]) == chess[2][0])
	{
		if (chess[0][0] == 1)
			return 1;
		else if (chess[0][0] == 2)
			return 2;
	}
	if ((chess[0][1] == chess[1][1]) && (chess[1][1]) == chess[2][1])
	{
		if (chess[0][1] == 1)
			return 1;
		else if (chess[0][1] == 2)
			return 2;
	}
	if ((chess[0][2] == chess[1][2]) && (chess[1][2]) == chess[2][2])
	{
		if (chess[0][2] == 1)
			return 1;
		else if (chess[0][2] == 2)
			return 2;
	}
	if ((chess[0][0] == chess[1][1]) && (chess[1][1]) == chess[2][2])
	{
		if (chess[0][0] == 1)
			return 1;
		else if (chess[0][0] == 2)
			return 2;
	}
	if ((chess[0][2] == chess[1][1]) && (chess[1][1]) == chess[2][0])
	{
		if (chess[0][2] == 1)
			return 1;
		else if (chess[0][2] == 2)
			return 2;
	}

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (chess[x][y] == 0)
				return 0;
		}
	}
	return -1;
}
int grade(int chess[][3])
{
	int x = 0;
	int y = 0;
	int sum_grade = 0;
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (chess[x][y] == 0)
				sum_grade++;
		}
	}
	return sum_grade;
}
void play()
{
	int chess[3][3] = { 0 };
	int winner = 0;
	print(chess);
	while (check_winner(chess) == 0)
	{
		player(chess);
		print(chess);
		if (check_winner(chess) != 0)
			break;
		computer(chess);
		print(chess);
		Sleep(1000);
	}
	winner = check_winner(chess);
	if (winner == 1)
	{
		printf("��ϲ����ʤ�ˣ�\n");
	}
	else if (winner == 2)
	{
		printf("���ź��������ˡ�\n");
	}
	else
	{
		printf("ƽ�֣�\n");
	}
}

int main()
{
	int have_fun = 1;
	do
	{
		play();
		printf("\n����1������Ϸ: ");
		scanf("%d", &have_fun);
	} while (have_fun == 1);
	return 0;
}