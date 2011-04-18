#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include <sysexits.h>
#include <time.h>

/* there is no real way to work around the static size limitation */
const int maxlen = 1000;

int main(int argc, char *argv[])
{
   	char result[maxlen];
    time_t t;
    struct tm *ltime;
    t = time(NULL);
    ltime = localtime(&t);
    if (ltime == NULL) {
        errx(EX_OSERR, "unable to determine current time");
    }
    if (strftime(result, sizeof(result), argv[1], ltime) == 0) {
		errx(EX_DATAERR, "strftime failed");
    }
	puts(result);
    exit(EXIT_SUCCESS);
} 
