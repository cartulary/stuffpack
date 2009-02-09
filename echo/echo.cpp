// This program licensed under the CMU license.

#include <iostream>

using namespace std;
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
			noNewlineFlag = true;
		}
		else
		{
			cout << argv[i] << " ";
			passedFirstN = true;
		}
	}
	if (! noNewlineFlag)
	{
		cout << endl;
	}
}
