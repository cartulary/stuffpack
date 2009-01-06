#include <fstream>
#include <iterator>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>


using namespace std;

int main(int argc, const char *argv[])
{
	ofstream file;
	file.open(argv[1]);
	std::istream_iterator<char> it(std::cin);
  	std::istream_iterator<char> end;
  	std::string results(it, end);
	cout << results;
	file.close();

	return 0;
}

