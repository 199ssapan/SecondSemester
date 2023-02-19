#include "intMatrix.h"

IntMatrix* createintMatrix(unsigned rows, unsigned columns)
{
	IntMatrix* matrix = (IntMatrix*)malloc(sizeof(IntMatrix));
	if (matrix == NULL) return NULL;
	matrix->data = (int**)malloc(sizeof(int**) * rows);
	for (int i = 0; i < rows; i++)
	{
		matrix->data[i] = (int*)malloc(sizeof(int) * columns);
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

void fillInIntMatrix(IntMatrix* matrix)
{
	unsigned rows = matrix->rows;
	unsigned columns = matrix->columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf_s("Enter the integer number\n");
			scanf_s("%d", &matrix->data[i][j]);
		}
	}
}

IntMatrix* intAdditionMatrix(IntMatrix* fMatrix, IntMatrix* sMatrix)
{
	if (fMatrix->columns != sMatrix->columns || fMatrix->rows != sMatrix->rows) return NULL;
	unsigned rows = fMatrix->rows;
	unsigned columns = fMatrix->columns;
	IntMatrix* newMatrix = createintMatrix(rows, columns);
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

void printIntMatrix(IntMatrix* matrix)
{
	for (int i = 0; i < matrix->rows; i++)
	{
		for (int j = 0; j < matrix->columns; j++)
		{
			printf_s("%d ", matrix->data[i][j]);
		}
		printf_s("\n");
	}
}