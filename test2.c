#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
    printf("#######################################\n");
    printf("############1.play   0.exit############\n");
    printf("#######################################\n");
}
void game()
{
    char mine[ROWS][COLS];
    char show[ROWS][COLS];
    Intimine(mine, ROWS, COLS,'0');
    Intimine(show, ROWS, COLS, '*');
    //DisplayBoard(mine,ROW,COL);
    DisplayBoard(show, ROW, COL);
    Setmine(mine, ROW, COL);
    //DisplayBoard(mine, ROW, COL);
    Findmine(mine, show, ROW, COL);


}

int main()
{
    int intput=0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请输入>");
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
            printf("输入非法，请重新输入\n");
            break;
        }
    } while(intput);
    return 0;
}