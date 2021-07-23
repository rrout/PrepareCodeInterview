#include <stdio.h>
#include <stdlib.h>
#include "bits.h"

int main(int argc, char const *argv[])
{
	int x = 11;
	char a[50];
	printf("Integer size : %d\n", BITSUTIL_SIZEOF_VAR(x));
	printf("Character size : %d\n", BITSUTIL_SIZEOF_VAR(a));
	printf("int size : %d\n", BITSUTIL_SIZEOF_TYPE(double));
	bitsUtilPrintBinary(x);
	printf("bitsUtilParity : %d\n", bitsUtilParity(x));
	printf("bitsUtilCountBits : %d\n", bitsUtilCountBits(x));

	x = bitsUtilSwapBits(x, 0, 4);
	bitsUtilPrintBinary(x);

	return 0;
}
