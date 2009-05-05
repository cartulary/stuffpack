#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

int main (void)
{
	typedef std::map<const std::string, const int> cmdListMapType;
	std::string mainWord;
	std::string cmdIn;
 	cmdListMapType cmdIntMap;
	int counter = 1;
	cmdIntMap.insert(std::make_pair("list",counter));
	counter++;

	std::cout << "Please enter the main word: ";
	std::cin >> mainWord;

	int i;
	cmdListMapType::iterator cmdListIter;

	std::vector<std::string> wordList;
	while (true)
	{
		std::cout << "Enter a command: ";
		std::cin >> cmdIn;
		if (cmdIn[0]=='?')
		{
			for(i = 1; i <= cmdIn.size(); ++i)
			{
				cmdIn[i - 1] = cmdIn [ i ];
			}
			/*
				we remove the last char of the string so the length matches up - we should remove whitespace instead.
			*/
			cmdIn.erase(cmdIn.size() - 1, 1) ;
			cmdListIter = cmdIntMap.find(cmdIn);
			if (cmdListIter != cmdIntMap.end())
			{
				std::cout << "we have what we need";
				int val = cmdListIter->second;
				std::cout << val << std::endl;
				switch (val)
				{
					case 1:
						std::cout << "we made it " << std::endl;
						for (std::vector<std::string>::iterator it = wordList.begin(); it != wordList.end(); ++it)
						{
							std::cout << *it << std::endl;
						}
						break;
					default:
						break;
				}
			}
		}
		else
		{
			std::cout << "added!";
			wordList.push_back(cmdIn);
		}
	}
	return 0;
}
