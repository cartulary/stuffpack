#ifndef LL_H
#define LL_H
#include "node.h"
#include <vector>

#define LL_TEMPLATE template <class T>

LL_TEMPLATE class Ll
{
	public:
		Node<T>* head;

		//T& operator()(const int loc);
		T& operator[](const int loc);
		//bool operator==(const Ll<T>& other) const;
		//bool operator!=(const Ll<T>& other) const;


		/* add a piece of data in a particular location;
		 * -1 == default last location
		 * 0 == first location	*/
		void push(T data, int loc=-1);
		/*
		 * return value at specific location
		 */
		T read(int loc);
		void remove(int loc);

		void printAll();

		Ll();
		~Ll();
	protected:
		std::vector<T> getAllNodes();
	private:
		int numnodes;
};

#endif /* LL_H */
