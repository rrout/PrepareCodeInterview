#include <stdio.h>
#include <stdlib.h>
#include "bits.h"

int main(int argc, char const *argv[])
{
	int x;
	char a[50];
	printf("Integer size : %d\n", BITSUTIL_SIZEOF_VAR(x));
	printf("Character size : %d\n", BITSUTIL_SIZEOF_VAR(a));
	printf("int size : %d\n", BITSUTIL_SIZEOF_TYPE(double));;
	return 0;
}