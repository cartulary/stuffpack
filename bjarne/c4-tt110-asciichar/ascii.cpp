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
	char letter = 'a';
	cout << setw(5) << left << "Int" << setw(5) << "Oct" << "Letter" << "\n";
	while (letter < 'z')
	{
		cout << setw(5) << left << static_cast<int>(letter) << setw(5) << oct << static_cast<int>(letter) << letter << "\n";
		++letter;
	}
	return EX_OK;
}
