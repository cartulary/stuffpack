#include <fstream>
#include <iterator>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>


using namespace std;
bool appendFlag = false, ignoreSignalFlag = false;
int main(int argc, char *argv[])
{
      int c;
      while ((c = getopt (argc, argv, "ai")) != -1)
     	{
            switch (c)
            {
                  case 'a':
                        appendFlag = true;
                        break;
                  case 'i':
                        ignoreSignalFlag = true;
			default:
				cerr << "broken" << endl;
		}
	}
      if (argc > 1)
      {
            for (int i = optind; i < argc; ++i)
            {
			cerr << "we don't handle files yet: " << argv[i] << endl;
		}
      }
	else
	{
		string line;
		while ( ! cin.eof() )
		{
			getline(cin, line);
			cout << line << endl;
		}
	}
	return 0;
}

