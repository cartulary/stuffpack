#ifndef LL_H
#define LL_H
#include "node.h"
#include <vector>

#define LL_TEMPLATE template <class T>

LL_TEMPLATE class LinkedList
{
	public:
		//T& operator()(const int loc);
		T& operator[](const unsigned int loc) const;
		T& operator()(const unsigned int loc) const;
		//bool operator==(const Ll<T>& other) const;
		//bool operator!=(const Ll<T>& other) const;


		/* add a piece of data in a particular location;
		 * 0 == first location	*/
		void push(const T data, const unsigned int loc);
		//default to the end
		virtual void push(const T data);

		/*
		 * return value at specific location
		 */
		T read(const unsigned int loc) const;
		void remove(const unsigned int loc);

		void printAll() const;

		/* Clear the linked list - remove all elements
		 */
		void clear();

		/* Swap two locations
		*/
		void swap(unsigned int A, unsigned int B);

		/*
			Returns true if a particular piece of data exists
		*/
		bool has(const T data) const;

		/* Return the current number of nodes */
		const unsigned int getNumNodes() const;

		LinkedList();
		virtual ~LinkedList();
	protected:
		std::vector<T> getAllNodes() const;
		Node<T>* head;
		unsigned int numnodes;
	private:
};

#endif /* LL_H */
