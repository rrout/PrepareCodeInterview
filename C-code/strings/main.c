#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
#include "strings.h"
int main(int argc, char const *argv[])
{
	char *value = "123";
	char itoa[100] = {0};
	printf("%d\n", s_atoi(value));
	s_itoa(456, itoa);
	printf("%s\n", itoa);
	return 0;
}