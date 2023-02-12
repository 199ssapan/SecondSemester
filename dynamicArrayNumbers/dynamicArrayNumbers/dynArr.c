#include "dynArr.h"

dynamicArray* newArray()
{
	dynamicArray* arr = (dynamicArray*)malloc(sizeof(dynamicArray));
	arr->data = (int*)malloc(sizeof(int) * 5);
	arr->countElems = 0;
	arr->size = 5;
	return arr;
}

void insertElem(dynamicArray* arr, int newElem)
{
	if (arr->countElems == arr->size)
	{
		int* newData = (int*)malloc(sizeof(int) * (arr->countElems + 1));

		for (int i = 0; i < arr->countElems; i++)
		{
			newData[i] = arr->data[i];
		}

		free(arr->data);
		arr->data = newData;

		newData[arr->size] = newElem;
		arr->size += 1;
	}
	else
	{
		arr->data[arr->countElems] = newElem;
	}
	arr->countElems += 1;
}

int getElem(dynamicArray* arr, unsigned index)
{
	if (index > arr->countElems - 1) return -1;
	else return arr->data[index];
}

unsigned getLength(dynamicArray* arr)
{
	return arr->countElems;
}