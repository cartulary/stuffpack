#include <stdio.h>
static inline unsigned char charMin(unsigned char a, unsigned char b);
int main (void)
{
	unsigned char letters[10];
	unsigned char smallest = 127;
	/* get the 10 letters */
	for(int i = 0; i < 10; ++i)
	{
		letters[i] = getchar();
	}
	/* check for the smallest */
	for(int i = 0; i < 10; ++i)
	{
		smallest = charMin(smallest, letters[i]);
	}
	/* display the smallest value */
	putchar(smallest);
	return 0;
}

/* returns the smallest value of two unsigned chars; look into some portable/reusable function for this*/
static inline unsigned char charMin(unsigned char a, unsigned char b)
{
	return (a < b) ? a : b;
}
