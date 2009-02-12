/* lincesed unded CMU licence */
#include <iostream>
#include <string>

/* no command line arguments - yet */
int main (void)
{
	/* use a string to allow for unknown size input */
	std::string line;
	/* get the input */
	std::cin >> line;
	/* go in reverse; don't use .at() because we know we are in range*/
	for (int c = line.length(); c >= 0; --c)
	{
		std::cout << line[c];
	}

	return 0;
}
