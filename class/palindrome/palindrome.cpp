/**********************************************
 * Name: palindrome                           *
 * Purpose: Determine if string is palindrome *
 * Returns: 0 always                          *
 *********************************************/

#include <iostream>

int main (int argc, char* argv[])
{
      std::string line;
	std::string reversed;
      /* get the input */
      std::cin >> line;
	reversed.resize(line.size());
      /* go in reverse; don't use .at() because we know we are in range*/
      for (int c = line.length(); c >= 0; --c)
      {
            reversed[line.length() - c - 1] = line[c];
      }
	std::cout << "In reverse: " <<reversed << std::endl;
	if (reversed == line)
	{
		std::cout << "Yeah!" << std::endl;
	}
	return 0;
}
