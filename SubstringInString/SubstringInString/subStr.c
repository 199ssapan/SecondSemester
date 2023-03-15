#include "subStr.h"

unsigned long long* gwtAddrFirstSubString(char* string, char* substring)
{
	unsigned lenMain = strlen(string);
	unsigned lenSub = strlen(substring);
	if (lenSub > lenMain || lenSub == 0 || lenMain == 0) return NULL;
	for (int i = 0; i < lenMain - lenSub + 1; i++)
	{
		unsigned count = 0;
		for (int j = 0; j < lenSub; j++)
		{
			if (substring[j] == string[i + j]) count++;
		}
		if (count == lenSub) return (&string + i);
	}
	return NULL;
}

unsigned countSubstrings(char* string, char* substring)
{
	unsigned lenMain = strlen(string);
	unsigned lenSub = strlen(substring);
	if (lenSub > lenMain || lenMain == 0 || lenSub == 0) return 0;
	unsigned subCount = 0;
	for (int i = 0; i < lenMain - lenSub + 1; i++)
	{
		unsigned matchCount = 0;
		for (int j = 0; j < lenSub; j++)
		{
			if (substring[j] == string[i + j]) matchCount++;
		}
		if (matchCount == lenSub) subCount++;
	}
	return subCount;
}