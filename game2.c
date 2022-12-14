#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Intimine(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i,j;
	printf("----------------扫雷游戏----------------\n");
	for ( i= 0;  i<=9; i++)
	{
		printf("%d ",i);
	}printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ",i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
	printf("----------------扫雷游戏----------------\n");

}
void Setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = EAST_COUNT;
	while (count)
	{
		int x = rand()%row+1;
		int y = rand()%col+1;
		if (mine[x][y] == '0')
		{
			mine[x][y] ='1';
			count--;
		}
		
	}

}
int Get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	int i, j;
	int count = 0;
	for (i = x; i <= x - 1; i++)
	{
		for (j = y; j <= y - 1; j++)
		{
			if (mine[i][j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win=0;
	while (win<row*col- EAST_COUNT)
	{
		printf("请输入要排查的坐标>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				int ret=Get_mine_count(mine,x,y);
				show[x][y] = ret + '0';
                DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}
	if (win == row * col- EAST_COUNT)
	{
		printf("恭喜你，赢了\n");
		DisplayBoard(mine, ROW, COL);

	}
}