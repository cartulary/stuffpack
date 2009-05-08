#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

typedef std::vector<int> bucketType;

bucketType generateBucket(std::string str);
bool testBucket(bucketType master, bucketType candidate);

int main (void)
{
	typedef std::map<const std::string, const int> cmdListMapType;
	std::string mainWord;
	std::string cmdIn;
 	cmdListMapType cmdIntMap;
	std::vector<std::string> wordList;

	int counter = 1;
	cmdIntMap.insert(std::make_pair("list", counter));
	counter++;
	cmdIntMap.insert(std::make_pair("word", counter));
	counter++;
	cmdIntMap.insert(std::make_pair("help", counter));
	counter++;
	cmdIntMap.insert(std::make_pair("bucket", counter));
	counter++;

	std::cout << "Please enter the main word: ";
	std::cin >> mainWord;
	bucketType mainBucket(26);
	mainBucket = generateBucket(mainWord);
	bucketType  tmpBucket(26);


	unsigned int i;
	cmdListMapType::iterator cmdListIter;

	while (true)
	{
		std::cout << "Enter a command: ";
		std::cin >> cmdIn;
		if (cmdIn[0]=='?')
		{
			for(i = 1; i < cmdIn.size(); ++i)
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
						for (std::vector<std::string>::iterator it = wordList.begin(); it != wordList.end(); ++it)
						{
							std::cout << *it << std::endl;
						}
						break;
					case 2:
						std::cout << mainWord << std::endl;
						break;
					case 3:
						std::cout << "help text here" << std::endl;
						break;
					case 4:
						for (int j = 0; j <26; ++j)
						{
							std::cout << mainBucket[j] << " ";
						}
						std::cout << std::endl;
						break;
					default:
						std::cout << "No such command" << std::endl;
						break;
				}
			}
		}
		else
		{
			tmpBucket = generateBucket(cmdIn);
			if (testBucket(mainBucket, tmpBucket))
			{
				std::cout << "added!";
				wordList.push_back(cmdIn);
			}
			else
			{
				std::cout << "bucket test failed" << std::endl;
			}
		}
	}
	return 0;
}

bucketType generateBucket(std::string str)
{
	bucketType bucket(26);
	/* clear the bucket and add new values; no rea */
	for (int j = 0; j <26; ++j)
	{
		bucket[j] = 0;
	}
	unsigned int i;
	for(i = 0; i < str.length(); ++i)
	{
		char c = str[i];
		if (isalpha(c))
		{
			c = tolower(c);
			int cVal = (int)(c - 'a');
			bucket[cVal]++;
		}
	}
	return bucket;
}

/* lets make sure candidate is a subset of master */
bool testBucket(bucketType master, bucketType candidate)
{
	unsigned int i;
	for (i = 0; i < 26; ++i)
	{
		if (candidate[i] > 0)
		{
			if (master[i] < candidate[i])
			{
				/* if master has less than the candidate - we fail; no need to subtract item letter by letter */
				return false;
			}
		}
	}
	return true;
}
