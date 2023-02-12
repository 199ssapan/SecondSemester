#include "strArr.h"
int main()
{
	srand((unsigned)time(0));
	strArray* arr = newArray();
	
	while (1)
	{
		printf_s("Enter the string\n");
		string str = recordString();
		insertElem(arr, str);
		printf_s("Element \'%s\' has inserted\n", str);
		printf_s("Array:\t ");
		printArray(arr);
		printf_s("Length: %u\n", getLength(arr));
		unsigned index = rand() % arr->currentCount;
		printf_s("Element \'%s\' has index %u\n", getElem(arr, index), index);
	}
	return 0;
}