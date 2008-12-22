#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int main(int argc, char* argv)
{
      vector<string> files (argv); 
	int i;
	for (i = 1; i <= argc; i++)
	{
		cout << argv[i] << endl;
	}
	return 0;
}
