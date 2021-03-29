#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
#include "strings.h"
int s_atoi(const char *val)
{
	char *p = NULL;
	int intrger = 0;
	p = val;
	while(*p != '\0'){
		intrger = (intrger*10) + (*p - '0');
		p++;
	}
	return intrger;
}

int s_itoa(int val, char *data)
{
	char *p = data;
	if(!data){
		return 0;
	}
	while(val){
		*p = (val%10) + '0';
		val = val/10;
		p++;
	}
	*p = '\0';
	s_strrev(data);
	return 1;
}

char *s_strrev(char *data)
{
	int len = strlen(data);
	int i, j;
	char tmp;
	for (i = 0, j = len-1; i < j; i++,j--)
	{
		tmp = data[i];
		data[i] = data[j];
		data[j]= tmp;
	}
	return data;
}

int s_strcpy(char *src, char *dst)
{
	while(*src != '\0'){
		*dst++ = *src++;
	}
	*dst = '\0';
}

