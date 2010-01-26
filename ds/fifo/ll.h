#ifndef LL_H
#define LL_H
#include "node.h"
#include <vector>

class Ll
{
	public:
		Node<int>* head;

		/* add a piece of data in a particular location;
		 * -1 == default last location
		 * 0 == first location	*/
		void push(int data, int loc=-1);
		/*
		 * return value at specific location
		 */
		int read(int loc);

		void printAll();

		Ll();
		~Ll();
	protected:
		std::vector<int> getAllNodes();
	private:
		int numnodes;
};

#endif /* LL_H */
