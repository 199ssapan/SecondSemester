#include "/home/maxim/GameOfLife/GOFLib/GOF.h"
#include <unistd.h>

int main()
{
    initscr();
    printw("Enter a degree of occupacyty in %%\n");
    int occupacity;
    scanw("%d", &occupacity);
    int rows, columns;
    printw("Enter the size of field like \"20 40\"(50 50 max)\n");
    scanw("%d %d", &rows, &columns);
    printw("Game of life\n1)Auto\n2)Manual control\n");
    refresh();
    int flag;
    char c = getch();
    clear();
    flag = 1 ? c == '1' : 0;
    Field* field = createField(rows, columns);
    setcolor();
    fillInField(field, occupacity);
    while (1)
    {
        printField(field);
        if (checkGameOver(field) == 0) break;
        updateField(field);
        refresh();
        if (flag != 1)
        {
           getch();
        }
        else
        {
            sleep(1);
        }
        clear();
    }
    endwin();
    return 0;
}