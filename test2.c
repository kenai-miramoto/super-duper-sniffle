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
        printf("������>");
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
            printf("����Ƿ�������������\n");
            break;
        }
    } while(intput);
    return 0;
}