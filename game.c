#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{

		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}

		}printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}



}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x,y;
	printf("�����\n");
	while (1)
	{
		printf("����������>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] ==' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�������ѱ�ռ��");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("������>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL],int row,int col)
{
	int i,j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j]==' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char Iswin(char board[ROW][COL], int row, int col)
{
	int i;
	for(i = 0; i < row; i++)
	{
		if(board[i][0] == board[i][1] && board[i][1]== board[i][2] && board[i][0]!=' ')
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i]!= ' ')
		{
			return board[i][0];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][1] && board[1][1] != ' ')
	{
		return board[0][0];
	}
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	} 
	return 'C';
}
 