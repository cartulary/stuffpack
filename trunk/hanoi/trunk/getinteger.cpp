#include <stdio.h>
#include "getinteger.h"

int getinteger(int base)
{
	char ch;
  	int val=0;
  	while ((ch = getchar()) != '\n')
	{
    		if (ch >= '0' && ch <= '0'+base-1)
		{
	      	val = base*val + (ch-'0');
		}
		else
		{
      		return ERROR;
		}
	}
  	return val;
}
