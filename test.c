#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"
void menu()
{
	printf("#############################\n");
	printf("######1.play ### 0.exit######\n");
	printf("#############################\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL); 
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=Iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	} if(ret=='*')
		{
			printf("玩家赢\n");
		}
		else if (ret == '#')
		{
			printf("电脑赢\n");
		}
		else
		{
			printf("平局\n");
		}
}
int main()
{
	int intput;
	srand((unsigned int)time(NULL));
    do {
		menu();
		printf("请输入\n");
		scanf("%d", &intput);
		switch (intput)
		{
		case(1):
			game();
			break;
		case(0):
			printf("退出游戏\n");
			break;

		default:
			printf("请重新输入\n");
			break;
		}
	}
		while (intput);
     	
	return 0;
}

