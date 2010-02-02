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
		T& operator()(const int loc);
		//bool operator==(const Ll<T>& other) const;
		//bool operator!=(const Ll<T>& other) const;


		/* add a piece of data in a particular location;
		 * 0 == first location	*/
		void push(T data, unsigned int loc);
		//default to the end
		void push(T data);

		/*
		 * return value at specific location
		 */
		T read(int loc);
		void remove(int loc);

		void printAll();

		/* Clear the linked list - remove all elements
		 */
		void clear();

		/* Return the current number of nodes */
		inline unsigned int getNumNodes();

		Ll();
		~Ll();
	protected:
		std::vector<T> getAllNodes();
	private:
		unsigned int numnodes;
};

#endif /* LL_H */
