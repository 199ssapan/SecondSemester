#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct IntMatrix
{
	int** data;
	unsigned rows;
	unsigned columns;
}IntMatrix;

IntMatrix* createintMatrix(unsigned r, unsigned c);
IntMatrix* intAdditionMatrix(IntMatrix* f, IntMatrix* s);
void fillInIntMatrix(IntMatrix* matrix);
void printIntMatrix(IntMatrix* matrix);
