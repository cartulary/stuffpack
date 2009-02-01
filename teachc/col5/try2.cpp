#include <stdio.h>

int main (void)
{
	int i = 1;
	while (i <= 100)
	{
		for (int n=1; n<=5; ++n)
		{
			printf("%d\t", i++);
		}
		printf("\n");
	}
	return 0;
}
