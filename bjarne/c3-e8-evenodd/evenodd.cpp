/**********************************************
 * Name: evenodd                              *
 * Returns: 0 always                          *
 *********************************************/

#include <iostream>
#include <sysexits.h>
#include "libhello.h"

using namespace std;

int main (int argc, char* argv[])
{
	int num;
	cout << "Please enter a number\n";
	cin >> num;
	cout << "The number " << num << " is " << (isEven(num) ? "" :"not ") << "even.\n";
	return EX_OK;
}
