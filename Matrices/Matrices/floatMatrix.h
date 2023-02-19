#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct FloatMatrix
{
	double** data;
	unsigned rows;
	unsigned columns;
}FloatMatrix;

FloatMatrix* createfloatMatrix(unsigned r, unsigned c);
FloatMatrix* floatAdditionMatrix(FloatMatrix* f, FloatMatrix* s);
void fillInfloatMatrix(FloatMatrix* matrix);
void printFloatMatrix(FloatMatrix* matrix);
