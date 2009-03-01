#include <iostream>

class terrain
{
		int status;
		int type;
		private:
			void stubFunction();
		public:
			void stubFunction2();
};

void terrain::stubFunction()
{
	return;
}
void terrain::stubFunction2()
{
	std::cout << "hi!" << std::endl;
	return;
}
