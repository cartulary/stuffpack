#include <iostream>
#include <limits>

/* define the function with default arguments equivalent to the minimum and maximum values allowed for an int;
	eventually expand to a user chosen type */
int getInt(int min = std::numeric_limits<int>::min()  , int max = std::numeric_limits<int>::max() );

/* testing -> do not use */
int main (void)
{
	std::cout << getInt();
	return 0;
}

/**********************************************
 * Name:    getInt	                      *
 * Returns: returns the value of the first    *
 * valid int from std in                      *
 * Parameters: int - minimum value; defauls to*
 *  min int value on system;                  *
 *  int - maxi value; defaults to max in on   *
 *  system                                    *
 *********************************************/
int getInt(int min, int max)
{
	int num;
	/* loop until we get the input we want */
	while (!(std::cin >> num) || num < min || num > max)
   	{
		/* clear error bits */
	     	std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   	}
	/* we are done; return the value */
	return num;
}
