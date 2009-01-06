#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>

using namespace std;

int main(int argc, const char *argv[])
{
	if (argc > 1)
	{
		ofstream file;
		file.open(argv[1]);
		file << cin;
		file.close();
	}
	return 0;
}

