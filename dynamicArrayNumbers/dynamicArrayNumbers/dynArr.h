#include <stdio.h>
#include <stdlib.h>

typedef struct dynamicArray
{
	unsigned countElems;
	unsigned size;
	int* data;
}dynamicArray;

dynamicArray* newArray();
void insertElem(dynamicArray* arr, int newElem);
int getElem(dynamicArray* arr, unsigned index);
unsigned getLength(dynamicArray* arr);