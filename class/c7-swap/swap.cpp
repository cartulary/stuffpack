/**********************************************
 * Name:                                      *
 * Purpose: 					    *
 * Returns: 	                            *
 * Parameters: 					    *
 * Known bugs:					    *
 * compatibility:					    *
 * notes: Write a function that swaps two vals*
 *********************************************/

#include <iostream>
#include <sysexits.h>

template <typename type>
void swap(type& i, type& j);

using std::cout;

int main (int argc, char* argv[])
{
	char i = 'i';
	char j = 'j';
	cout << i  <<j;
	swap(i,j);
	cout << i << j;
	return EX_OK;
}

/**
	@brief swaps two things
	@param a Thing of arbitrary type
	@param b Another thing of same type

	Swaps two values - takes the addresses to make it faster.
*/

template <typename type>
inline void swap(type& a, type& b)
{
	type tmp = a;
	a=b;
	b=tmp;
}
