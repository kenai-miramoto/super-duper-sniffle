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
			printf("���Ӯ\n");
		}
		else if (ret == '#')
		{
			printf("����Ӯ\n");
		}
		else
		{
			printf("ƽ��\n");
		}
}
int main()
{
	int intput;
	srand((unsigned int)time(NULL));
    do {
		menu();
		printf("������\n");
		scanf("%d", &intput);
		switch (intput)
		{
		case(1):
			game();
			break;
		case(0):
			printf("�˳���Ϸ\n");
			break;

		default:
			printf("����������\n");
			break;
		}
	}
		while (intput);
     	
	return 0;
}

