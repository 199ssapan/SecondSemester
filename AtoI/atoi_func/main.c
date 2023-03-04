#include "atoi_function.h"

int main()
{
	printf_s("%d\n", myAtoI("999"));
	printf_s("%d\n", myAtoI("-999"));
	printf_s("%d\n", myAtoI("+999"));
	printf_s("%d\n", myAtoI("22892389238989238923"));
	printf_s("%d\n", myAtoI("-84892498348948982"));
	printf_s("%d\n", myAtoI("2147483647"));
	printf_s("%d\n", myAtoI("-"));
	printf_s("%d\n", myAtoI("+"));
	printf_s("%d\n", myAtoI("-2147483648"));
	printf_s("%d\n", myAtoI("2147483649"));
	printf_s("%d\n", myAtoI("-2147583648"));
	printf_s("%d\n", myAtoI("mkldld"));
	printf_s("%d\n", myAtoI("-[lpspmvl"));
	printf_s("%d\n", myAtoI(""));
	printf_s("%d\n", myAtoI("1nkklnll2345"));
	printf_s("%d\n", myAtoI("12llslml345"));
	printf_s("%d\n", myAtoI("-123ncjsn45"));
	printf_s("%d\n", myAtoI("1234smclsc5"));
	printf_s("%d\n", myAtoI("-12345m;osmclsmcls"));
	return 0;
}