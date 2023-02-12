#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define START_CAPACITY 5

typedef char* string;


typedef struct strArray
{
	string* data;
	unsigned currentCount;
	unsigned generalSize;
}strArray;

strArray* newArray();
int insertElem(strArray* arr, string str);
unsigned getLength(strArray* arr);
string getElem(strArray* arr, unsigned index);
////////////////////
void printArray(strArray* arr);
string* copyData(strArray* arr);
void freePrevDataArr(strArray* arr);
void copyNewString(strArray* arr, string str);
string recordString();