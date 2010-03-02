#include "../functions.h"

/* Retrieves a positive integer from the user. */
long int getinteger(int base)
{
  	int n = 0;

  	cout << "Please enter a positive integer:" << endl;
  	n = strtol(getcharcters(10),NULL,10);

  	if (n <= 0)
  	{
  		n = getinteger(base);
  	}
    	return n;
}

/* Retrieves character input from the user, up to the specified maximum quantity. */
char* getcharcters(int max)
{
	char* str = (char*)malloc(max*sizeof(int)+1);
	char ch;
	int i = 0;

	while ((ch = getchar()) != '\n' && i < max)
	{
		str[i] = ch;
		i++;
	}

	str[max] = NULL; //I hope this is the right way to terminate a char array.
	return str;
}
