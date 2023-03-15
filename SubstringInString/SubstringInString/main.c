#include "subStr.h"

int main(int argc, char* argv[])
{
	if (argc < 3) return -1;
	char* substring = argv[1];
	for (int i = 2; i < argc; i++)
	{
		int* addr = gwtAddrFirstSubString(argv[i], substring);
		if (addr != NULL)
		{
			printf_s("%s\t", argv[i]);
			Sleep(1000);
			printf_s("%u\n", countSubstrings(argv[i], substring));
		}
	}
	return 0;
}