#include <stdio.h>

int main (void)
{
	for (int i = 1; i <= 100; i += 5)
	{
		printf("%d\t%d\t%d\t%d\t%d\n",i,i+1,i+2,i+3,i+4);
	}
	return 0;
}
