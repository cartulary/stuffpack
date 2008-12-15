#include "functions.h"
using namespace std;
long int getinteger(int base)
{
	char ch;
  	long int val=0;
	cout << "Please enter an integer" << endl;
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
	if (val > 0)
	{
	  	return val;
	}
	else
	{
		return ERROR;
	}
}
