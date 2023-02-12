#include "strArr.h"

strArray* newArray()
{
	strArray* arr = (strArray*)malloc(sizeof(strArray));
	if (arr == NULL) return NULL;
	arr->currentCount = 0;
	arr->generalSize = START_CAPACITY;
	arr->data = (string*)malloc(START_CAPACITY * sizeof(string));
	return arr;
}

int insertElem(strArray* arr, string str)
{
	if (arr->currentCount == arr->generalSize)
	{
		string* newArr = copyData(arr);
		copyNewString(arr, str);
		arr->data = newArr;
		arr->generalSize++;
	}
	arr->data[arr->currentCount] = str;
	arr->currentCount++;
	return 1;
}
	

string recordString()
{
	string str = (string)malloc(sizeof(char));
	unsigned len = 1;
	char c;
	int flag = 0;
	while ((c = getchar()) != '\n') 
	{
		str[len - 1] = c;
		len++;
		str = (string)realloc(str, len);
	}
	str[len - 1] = '\0';
	return str;
}

void printArray(strArray* arr)
{
	for (int i = 0; i < arr->currentCount; i++)
	{
		printf_s("%s ", arr->data[i]);
	}
	printf_s("\n");
}

string* copyData(strArray* arr)
{
	string* newArr = (string*)malloc(sizeof(string) * (arr->currentCount + 1));
	for (int i = 0; i < arr->currentCount; i++)
	{
		newArr[i] = (string)malloc(sizeof(char) * (strlen(arr->data[i]) + 1));
		for (int j = 0; j < strlen(arr->data[i]); j++)
		{
			newArr[i][j] = arr->data[i][j];
		}
		newArr[i][strlen(arr->data[i])] = '\0';
	}
	freeDataArr(arr);
	return newArr;
}

void copyNewString(strArray* arr, string str)
{
	unsigned len = strlen(str);
	arr->data[arr->currentCount] = (string)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
	{
		arr->data[arr->currentCount][i] = str[i];
	}
	arr->data[arr->currentCount][len] = '\0';
}

void freeDataArr(strArray* arr)
{
	for (int i = 0; i < arr->currentCount; i++)
	{
		free(arr->data[i]);
	}
	free(arr->data);
}


unsigned getLength(strArray* arr)
{
	return arr->currentCount;
}

string getElem(strArray* arr, unsigned index)
{
	if (index >= arr->currentCount) return NULL;
	else return arr->data[index];
}