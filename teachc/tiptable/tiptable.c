#include <stdio.h>
#include <stdbool.h>
int main (void)
{
	bool neverQuit = false;
	char quitChar = '0'; //make sure it doesn't start at 'q'
	for (int dinnerCost = 1; dinnerCost <= 100; ++dinnerCost)
	{
		printf("$%d\t$%.2f\t$%.2f\t$%.2f\n",dinnerCost, dinnerCost * 1.1, dinnerCost * 1.15, dinnerCost * 1.2);
		if (!neverQuit)
		{
			printf("continue? (q for quit, n for never)");
			scanf("%1c", &quitChar);

			if (quitChar == 'q')
			{
				break;
			}
			if (quitChar == 'n')
			{
				neverQuit = true;
			}
		}
	}
	return 0;
}
