#include "floatMatrix.h"
#include "intMatrix.h"

int main()
{
	IntMatrix* im1 = createintMatrix(2, 2);
	IntMatrix* im2 = createintMatrix(2, 2);

	fillInIntMatrix(im1);
	printf_s("First int matrix:\n");
	printIntMatrix(im1);

	fillInIntMatrix(im2);
	printf_s("Second int matrix:\n");
	printIntMatrix(im2);

	IntMatrix* im3 = intAdditionMatrix(im1, im2);
	printf_s("Sum:\n");
	printIntMatrix(im3);

	FloatMatrix* fm1 = createfloatMatrix(4, 2);
	FloatMatrix* fm2 = createfloatMatrix(4, 2);

	fillInfloatMatrix(fm1);
	printf_s("First float matrix\n");
	printFloatMatrix(fm1);

	fillInfloatMatrix(fm2);
	printf_s("Second float matrix\n");
	printFloatMatrix(fm2);

	FloatMatrix* fm3 = floatAdditionMatrix(fm1, fm2);
	printf_s("Sum:\n");
	printFloatMatrix(fm3);
	return 0;
}