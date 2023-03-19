#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 20

typedef struct
{
    unsigned rows;
    unsigned columns;
    char** field;
}Field;

Field* createField(int, int);
void fillInField(Field* field, int occupacity);
void printField(Field* field);
void drawFrame(int x, int y);
void updateField(Field* field);
unsigned countNeighbours(Field* field, int posX, int posY);
void freeField(Field* field);
int checkGameOver(Field* field);
void setcolor();
