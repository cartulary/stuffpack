#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <ctype.h>
#include <unistd.h>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
	int c;
      while ((c = getopt (argc, argv, "benstuv")) != -1)
	{
      	switch (c)
		{
			
			default:
				cout << "options ignored" << endl;
		}

	}
      for (int i = optind; i < argc; i++)
	{
		if ( strcmp(argv[i] , "-") )
		{
      		printf ("%s\n", argv[i]);
		}
		else
		{
			printf("stdin!\n");
		}
	}
      return 0;

	return 0;
}
