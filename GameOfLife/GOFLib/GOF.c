#include "GOF.h"


Field* createField(int r, int c)
{
    Field* field = (Field*)malloc(sizeof(Field));
    if (field == NULL)
        return NULL;
    field->field = (char**)malloc(sizeof(char*) * r);
    if (field->field == NULL)
    {
        free(field);
        return NULL;
    }
    for (int i = 0; i < r; i++)
    {
        field->field[i] = (char*)malloc(sizeof(char) * c);
        if (field->field[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(field->field[j]);
            }
            free(field->field);
            free(field);
            return NULL;
        }
    }
    field->rows = r;
    field->columns = c;
    return field;
}

void fillInField(Field* field, int occupacity)
{
    srand((unsigned)time(0));
    for (int i = 0; i < field->rows; i++)
    {
        for (int j = 0; j < field->columns; j++)
        {
            field->field[i][j] = 0;
        }
    }
    for (int i = 0; i < field->rows; i++)
    {
        for (int j = 0; j < field->columns; j++)
        {
            if ((rand() % 100) < occupacity)
            field->field[i][j] = 1;
            else
            field->field[i][j] = 0;
        }
    }
}

void printField(Field* field)
{
    drawFrame(field->rows, field->columns);
    for (int i = 0; i < field->rows; i++)
    {
        move(i + 1, 1);
        for (int j = 0; j < field->columns; j++)
        {
            if (field->field[i][j])
            {
                printw("@ ");
            }
            else
            {
                printw("  ");
            }
        }
        printw("\b# \n");
    }
}

void drawFrame(int x, int y)
{
    for (int i = 0; i <= y; i++)
    {
        printw("# ");
    }
    printw("   Press \'e\' to exit");
    printw("\n");
    for (int i = 0; i < x; i++)
    {
        printw("# ");
        for (int j = 0; j <= y; j++)
        {
            printw("  ");
        }
        printw("  #\n");
    }
    for (int i = 0; i <= y; i++)
    {
        printw("# ");
    }
    printw("\n");
    move(1, 1);
}

int updateField(Field* field)
{
    char** newField = (char**)malloc(sizeof(char*) * field->rows);
    if (newField == NULL)
    {
        return 0;
    }
    for (int i = 0; i < field->rows; i++)
    {
        newField[i] = (char*)malloc(sizeof(char) * field->columns);
        if (newField[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(newField[j]);
                free(newField);
                return 0;
            }
        }
    }
    for (int i = 0; i < field->rows; i++)
    {
        for (int j = 0; j < field->columns; j++)
        {
            newField[i][j] = 0;
        }
    }
    
    for (int i = 0; i < field->rows; i++)
    {
        for (int j = 0; j < field->columns; j++)
        {
            unsigned neighboursCount = countNeighbours(field, i, j);
            if (field->field[i][j] == 1)
            {
                if (neighboursCount == 2 || neighboursCount == 3)
                {
                    newField[i][j] = 1;
                }
            }
            else
            {
                if (neighboursCount == 3)
                {
                    newField[i][j] = 1;
                }
            }
        }
    }
    freeField(field);
    field->field = newField;
    return 1;
    }

unsigned countNeighbours(Field* field, int posX, int posY)
{
    unsigned h1 = (unsigned)(field->field[posX][(posY + field->columns - 1) % field->columns]);
    unsigned h2 = (unsigned)(field->field[posX][(posY + 1) % field->columns]);
    unsigned v1 = (unsigned)(field->field[(posX + field->rows - 1) % field->rows][posY]);
    unsigned v2 = (unsigned)(field->field[(posX + 1) % field->rows][posY]);
    unsigned d1 = (unsigned)(field->field[(posX + field->rows - 1) % field->rows][(posY + field->columns - 1) % field->columns]);
    unsigned d2 = (unsigned)(field->field[(posX + field->rows - 1) % field->rows][(posY + 1) % field->columns]);
    unsigned d3 = (unsigned)(field->field[(posX + 1) % field->rows][(posY + field->columns - 1) % field->columns]);
    unsigned d4 = (unsigned)(field->field[(posX + 1) % field->rows][(posY + 1) % field->columns]);
    return h1 + h2 + v1 + v2 + d1 + d2 + d3 + d4;
}

void freeField(Field* field)
{
    for (int i = 0; i < field->rows; i++)
    {
        free(field->field[i]);
    }
    free(field->field);
}

int checkGameOver(Field* field)
{
    int flag = 0;
    for (int i = 1; i < field->rows - 1; i++)
    {
        for (int j = 1; j < field->columns - 1; j++)
        {
            if (field->field[i][j] == 1)
            {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

void setcolor()
{
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    attrset(COLOR_PAIR(1));
}