#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
	if (argc > 1)
	{
		string buf;
		ofstream file;
		file.open(argv[1]);
		cin >> buf;
		cout << buf;
		file.close();
	}
	return 0;
}

