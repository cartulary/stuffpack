/**********************************************
 * Name: palindrome                           *
 * Purpose: Determine if string is palindrome *
 * Returns: 0 always                          *
 *********************************************/

#include <iostream>

int main (int argc, char* argv[])
{
      std::string line;
      /* get the input */
      std::cin >> line;
      /* check the last half of the line against the first;
		use [] instead of .at() b/c we know we are in range*/
      for (int c = (line.length())/ 2;  c >= 0; --c)
      {
		if ( line[c] != line[ line.length() - c -1 ])
		{
			// lets get out of here if we are not a palindrome */
			return 0;
		}
      }
	// YES WE ARE!
	std::cout << "Yeah!" << std::endl;
	return 0;
}
