#include "atoi_function.h"
#include <limits.h>

int myAtoI(char* string)
{
	char* intermediateString = checkRawString(string);
	if (intermediateString == NULL) return 0;
	int resultOfChecking = checkIntermediateString(intermediateString);
	if (resultOfChecking == BIGGER_THEN_INT_MAX) return INT_MAX;
	if (resultOfChecking == LESS_THEN_INT_MIN) return INT_MIN;
	if (resultOfChecking == OK)
	{
		if (intermediateString[0] == '+' || intermediateString[0] == '-')
		{
			char* strWOSign = getStringWOSign(intermediateString);
			int sign;
			if (intermediateString[0] == '-') sign = -1;
			else sign = 1;
			int result = atoiFunc(strWOSign) * sign;
			free(strWOSign);
			free(intermediateString);
			return result;
		}
		return atoiFunc(intermediateString);
	}
	return 0;
}

char* checkRawString(char* rawString)
{
	char* string = getStringWOSpaces(rawString);
	if (strlen(string) == 0) return NULL;
	if ((string[0] < '0' || string[0] > '9') && (string[0] != '-' && string[0] != '+')) return NULL;
	int len = strlen(string);
	char* newString = (char*)malloc(sizeof(char) * (strlen(string) + 1));
	int i = 0;
	if (string[i] > '9' || string[i] < '0')
	{
if (string[i] == '+') newString[i] = '+';
else if (string[i] == '-') newString[i] = '-';
i++;
	}
	for (;i < len; i++)
	{
		if (string[i] > '9' || string[i] < '0')
		{
			break;
		}
		newString[i] = string[i];
	}
	newString[i] = '\0';
	free(string);
	return newString;
}

int checkIntermediateString(char* string)
{
	int len = strlen(string);
	char* intMaxStr = "2147483647";
	int lenMax = strlen(intMaxStr);
	char* intMinStr = "-2147483648";
	int lenMin = strlen(intMinStr);
	if (string[0] == '-')
	{
		if (len > lenMin)
		{
			return LESS_THEN_INT_MIN;
		}
		else if (len == lenMin)
		{
			for (int i = 1; i < lenMin; i++)
			{
				if (intMinStr[i] < string[i]) return LESS_THEN_INT_MIN;
			}
		}
	}
	else if (string[0] == '+')
	{
		if (len - 1 > lenMax)
		{
			return BIGGER_THEN_INT_MAX;
		}
		else if (len - 1 == lenMax)
		{
			for (int i = 1; i < lenMax; i++)
			{
				if (intMaxStr[i - 1] < string[i]) return BIGGER_THEN_INT_MAX;
			}
		}
	}
	else
	{
		if (len > lenMax)
		{
			return BIGGER_THEN_INT_MAX;
		}
		else if (len == lenMax)
		{
			for (int i = 0; i < lenMax; i++)
			{
				if (intMaxStr[i] < string[i]) return BIGGER_THEN_INT_MAX;
			}
		}
	}
	return OK;
}

int atoiFunc(char* string)
{
	int result = 0;
	int len = strlen(string);
	for (int i = 0; i < len; i++)
	{
		int power10 = (int)pow(10, len - i - 1);
		result += power10 * ((int)(string[i] - '0'));
	}
	return result;
}

char* getStringWOSign(char* string)
{
	char* newStr = (char*)malloc(sizeof(char) * (strlen(string)));
	for (int i = 1; i < strlen(string); i++)
	{
		newStr[i - 1] = string[i];
	}
	newStr[strlen(string) - 1] = '\0';
	return newStr;
}

char* getStringWOSpaces(char* string)
{
	int len = strlen(string);
	int newLen = len;
	for (int i = 0; i < len; i++)
	{
		if (string[i] == ' ') continue;
		else
		{
			newLen = len - i;
			break;
		}
	}
	char* newString = (char*)malloc(sizeof(char) * (newLen + 1));
	if (newString == NULL) return NULL;
	for (int i = len - newLen; i < len; i++)
	{
		newString[i - (len - newLen)] = string[i];
	}
	newString[newLen] = '\0';
	return newString;
}