#ifndef LL_IT_H
#define LL_IT_H
#include <iterator>
#include "node.h"

#define LL_IT_TEMPLATE template <class T>

LL_IT_TEMPLATE class LinkedListIterator : public std::iterator<std::input_iterator_tag, T>
{
	Node<T>* p;
public:
	LinkedListIterator(T* x);
	LinkedListIterator(const T& other);
	LinkedListIterator<T>& operator++();
	LinkedListIterator<T> operator++(int);
	LinkedListIterator<T>& operator--();
	LinkedListIterator<T> operator--(int);

	bool operator==(const LinkedListIterator<T>& rhs);
	bool operator!=(const LinkedListIterator<T>& rhs);

	T& operator*();

};
#endif
