#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int myAtoI(char* string);
char* checkRawString(char* string);
int checkIntermediateString(char* string);
int atoiFunc(char* string);
char* getStringWOSign(char* string);


#define LESS_THEN_INT_MIN -1
#define BIGGER_THEN_INT_MAX 1
#define OK 0