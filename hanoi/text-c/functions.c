#include "functions.h"

long int getinteger(int base)
{
	char ch;
  	int val=0;
	printf("Please enter an integer\n");
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
