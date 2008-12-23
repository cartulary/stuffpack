#include <iostream>
#include <vector>
#include <string.h>

#define FALSE	0
#define TRUE	1

using namespace std;
int main(int argc, char* argv)
{
      vector<string> files; 
	int i;
	bool debug = FALSE;
	if (argc > 1)
	{
		for (i = 1; i <= argc; i++)
		{
			if (strcmp((char*)argv[i],"-debug"))
			{
				debug = TRUE;
			}
			cout << argv[i] << endl;
		}
	}
	return 0;
}
