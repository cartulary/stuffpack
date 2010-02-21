#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define FALSE	0
#define TRUE	1
#define FILE_READ_OK 0

int main(int argc, char* argv[])
{
	char** files = malloc(argc * sizeof(char*)) ;
	int i;
	int len;
	bool debug = FALSE;
	int numfiles = 0;
	/* push all the files on to the vector */
	if (argc > 1)
	{
		for (i = 1 ; i <= argc - 1 ; i++)
		{
			if (strcmp(argv[i],"-debug"))
			{
				len = strlen(argv[i]);
				files[numfiles] = malloc(len * sizeof(files[numfiles]));
				strcpy(files[numfiles],argv[i]);
				++numfiles;
			}
			else
			{
				debug = TRUE;
			}
		}
	}
	else
	{
		/* we have no files; return without error */
		return 0;
	}



	/* check to see if the files exist; if they don't print the correct info; if they do error out */
	for (i = 0; i < numfiles; ++i)
	{
		if (eaccess(files[i], R_OK) == FILE_READ_OK)
		{
			fprintf(stderr, "fatal error: %s exists\n", files[i]);
		}
		else
		{
			if (debug)
			{
				printf("starting execution of %s ...\n we are done\n", files[i]);
			}
		}
		free(files[i]);
	}
	free(files);
	return 0;
}
