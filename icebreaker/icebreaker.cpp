#include <iostream>
#include <vector>
#include "terrain.cpp"

int main(void)
{
	std::vector< std::vector<int> > board(3,0);
   	int ii, jj;
   	for(ii=0; ii < 3; ii++)
   	{
	      for(jj=0; jj < 2; jj++)
		{
			std::cout << ii << jj << std::endl;
         		board[ii][jj] = ii + jj;
      	}
   	}
   	for(ii=0; ii < 3; ii++)
   	{
	      for(jj=0; jj < 2; jj++)
		{
         		std::cout << board[ii][jj] << std::endl;
      	}
   	}
//	terrain ter;
//	ter.stubFunction2();
	return 0;
}
