#include "floatMatrix.h"



FloatMatrix* createfloatMatrix(unsigned rows, unsigned columns)
{
	FloatMatrix* matrix = (FloatMatrix*)malloc(sizeof(FloatMatrix));
	if (matrix == NULL) return NULL;
	matrix->data = (double**)malloc(sizeof(double**) * rows);
	for (int i = 0; i < rows; i++)
	{
		matrix->data[i] = (double*)malloc(sizeof(double) * columns);
		if (matrix->data[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				free(matrix->data[j]);
			}
			return NULL;
		}
	}
	matrix->columns = columns;
	matrix->rows = rows;
	return matrix;
}

void fillInfloatMatrix(FloatMatrix* matrix)
{
	unsigned rows = matrix->rows;
	unsigned columns = matrix->columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf_s("Enter the float number\n");
			scanf_s("%lf", &matrix->data[i][j]);
		}
	}
}

FloatMatrix* floatAdditionMatrix(FloatMatrix* fMatrix, FloatMatrix* sMatrix)
{
	if (fMatrix->columns != sMatrix->columns || fMatrix->rows != sMatrix->rows) return NULL;
	unsigned rows = fMatrix->rows;
	unsigned columns = fMatrix->columns;
	FloatMatrix* newMatrix = createfloatMatrix(rows, columns);
	if (newMatrix == NULL) return NULL;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			newMatrix->data[i][j] = fMatrix->data[i][j] + sMatrix->data[i][j];
		}
	}
	return newMatrix;

}

void printFloatMatrix(FloatMatrix* matrix)
{
	for (int i = 0; i < matrix->rows; i++)
	{
		for (int j = 0; j < matrix->columns; j++)
		{
			printf_s("%lf ", matrix->data[i][j]);
		}
		printf_s("\n");
	}
}