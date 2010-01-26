#ifndef LL_H
#define LL_H
#include "node.h"

class Ll
{
	public:
		Node<int>* head;

		/* add a piece of data after a particular location;
		 * 0 == default first location	*/
		void push(int data, int loc=0);
		/*
		 * return value at specific location
		 */
		int read(int loc);

		Ll();
		~Ll();

	private:
		int numnodes;
};

#endif /* LL_H */
