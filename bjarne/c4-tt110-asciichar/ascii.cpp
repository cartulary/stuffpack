/**********************************************
 * Name: asciichar                            *
 * Purpose: displays ascii chart		    *
 * Returns: 0 always                          *
 *********************************************/

#include <iostream>
#include <sysexits.h>
#include <iomanip>

using namespace std;

void printList(int start, int end);

int main (int argc, char* argv[])
{
	cout << setw(5) << left << "Int" << setw(5) << "Oct" << "Letter" << "\n";
	printList('A','Z');
	printList('a','z');
	printList('0','9');
	return EX_OK;
}

void printList(int start, int end)
{
	char letter;
	for (letter = start; letter <= end; ++letter)
	{
		cout << setw(5) << left << static_cast<int>(letter) << setw(5) << oct << static_cast<int>(letter) << letter << "\n";
	}
}
