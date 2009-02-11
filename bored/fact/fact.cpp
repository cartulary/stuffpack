#include <iostream>
char* getcharcters(int);

int main (int argc, char* argv[])
{
	long int num = 0;
	unsigned long int factorial = 1;
	int truearg = argc; //use instead of argc because we modifu it

	do
	{
		// if the user gave us a value - do something with it
		if (truearg > 1)
		{
 			num = strtol(argv[1],NULL,10);
		}
		else
		{
		      std::cout << "Please enter a positive integer:" << std::endl;
     			num = strtol(getcharcters(10),NULL,10);
      	}
		truearg = 0; //arguments failed us so try for manual entry
	} while (num <= 0);
	// we don't need to multiply by one
	for (long int i = num; i >= 2; --i)
	{
		factorial *= i;
	}
	std::cout << factorial << std::endl;
	return 0;
}

/* replace this with a better function ASAP */
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

