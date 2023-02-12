#include "dynArr.h"

int main()
{
	dynamicArray* arr = newArray();
	for (int i = 0; i < 100; i++)
	{
		insertElem(arr, i + 1);
		printf_s("number %d has been inserted\n", i + 1);
	}
	for (int i = 0; i < getLength(arr); i++)
	{
		printf_s("%d ", getElem(arr, i));
	}
	return 0;
}