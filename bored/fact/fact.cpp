#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

char* getcharcters(int);

int main (int argc, char* argv[])
{
	long int num = 0;
	mpz_class factorial;
	factorial = 1;

	// if the user gave us a value - do something with it
	if (argc > 1)
	{
		num = strtol(argv[1],NULL,10);
	}

	while (num <= 0)
	{
	      std::cout << "Please enter a positive integer:" << std::endl;
		num = strtol(getcharcters(10),NULL,10);
	}

	// we don't need to multiply by one
	for (long int i = num; i >= 2; --i)
	{
		factorial *= i;
	}

	std::cout << factorial << std::endl;
	return 0;
}

/* replace this with a better function ASAP */
/* copied from hanoi -> I really should make a global function */
char* getcharcters(int max)
{
	// dynamically allocate memory; convert to "new" eventually
      char* str = (char*)calloc(max,sizeof(int)+1);
      char ch;
      int i = 0;

	/* loop until we get \n */
      while ((ch = getchar()) != '\n' && i < max)
      {
            str[i] = ch;
            ++i;
      }

      str[max] = NULL; //I hope this is the right way to terminate a char array.
      return str;
}

