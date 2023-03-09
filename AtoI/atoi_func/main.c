#include "atoi_function.h"

int main()
{
	printf_s("%d\n", myAtoI("      999"));
	printf_s("%d\n", myAtoI("-999"));
	printf_s("%d\n", myAtoI("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       +999"));
	printf_s("%d\n", myAtoI("228923892389892388888888888888888888888888888888888888888888888888888888888888888888888888888923"));
	printf_s("%d\n", myAtoI("-848924983489489888888888888888888888888888888888888888888888888888888888882"));
	printf_s("%d\n", myAtoI("21 47483647"));
	printf_s("%d\n", myAtoI("-"));
	printf_s("%d\n", myAtoI("+"));
	printf_s("%d\n", myAtoI("-2147483648"));
	printf_s("%d\n", myAtoI("2147483649"));
	printf_s("%d\n", myAtoI("-2147583648"));
	printf_s("%d\n", myAtoI("mkldld"));
	printf_s("%d\n", myAtoI("-[lpspmvl"));
	printf_s("%d\n", myAtoI(" "));
	printf_s("%d\n", myAtoI("1nkklnll2345"));
	printf_s("%d\n", myAtoI("12 llslml345"));
	printf_s("%d\n", myAtoI("-123ncjsn45"));
	printf_s("%d\n", myAtoI("1234smclsc5"));
	printf_s("%d\n", myAtoI("                    -12345m;o smcl        smcls"));
	printf_s("%d ", myAtoI("888 999"));
	return 0;
}