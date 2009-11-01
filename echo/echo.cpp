// This program licensed under the CMU license.

#include <iostream>

int main (int argc, char *argv[])
{
	// we are not going to test for flags here - this would cause compat problems */
	bool noNewlineFlag = false; // do we echo a newline at the end?
	bool passedFirstN  = false; //set after we passed the first string
	for (int i=1; i < argc; ++i)
	{
		/* if we have -n and we have yet to pass other chars set flags; else print */
		if (strcmp (argv[i], "-n") == 0 && !passedFirstN)
		{
			// don't print a newline at the end
			noNewlineFlag = true;
		}
		else
		{
			std::cout << argv[i] << " ";
			passedFirstN = true;
		}
	}
	if (! noNewlineFlag)
	{
		std::cout << std::endl;
	}
}
