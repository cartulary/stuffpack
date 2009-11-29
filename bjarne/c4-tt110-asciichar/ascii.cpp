/**********************************************
 * Name: asciichar                            *
 * Purpose: displays ascii chart		    *
 * Returns: 0 always                          *
 *********************************************/

#include <iostream>
#include <sysexits.h>
#include <iomanip>

using namespace std;

int main (int argc, char* argv[])
{
	cout << setw(5) << left << "Int" << setw(5) << "Oct" << "Letter" << "\n";
	char letter;
	for (letter = 'a'; letter <= 'z'; ++letter)
	{
		cout << setw(5) << left << static_cast<int>(letter) << setw(5) << oct << static_cast<int>(letter) << letter << "\n";
	}
	return EX_OK;
}
