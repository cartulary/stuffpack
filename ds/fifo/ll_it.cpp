#include "ll_it.h"

/*
	I am VERY confused as to how to implement and use Iterators.
	I need to do a LOT more reading
*/

LL_IT_TEMPLATE LinkedListIterator<T>::LinkedListIterator(T* x) : p(x)
{
}

LL_IT_TEMPLATE LinkedListIterator<T>::LinkedListIterator(const T& other) : p(other.p)
{
}

LL_IT_TEMPLATE LinkedListIterator<T>& LinkedListIterator<T>::operator++()
{
	p = p->next;
	return *this;
}

LL_IT_TEMPLATE LinkedListIterator<T> LinkedListIterator<T>::operator++(int)
{
	LinkedListIterator<T> ans = *this;
	++(*this);
	return ans;
}

/*
LL_IT_TEMPLATE LinkedListIterator<T>& LinkedListIterator<T>::operator--()
{
	//No easy easy to get "previous"
	p = p->next;
	return *this;
}
*/

LL_IT_TEMPLATE LinkedListIterator<T> LinkedListIterator<T>::operator--(int)
{
	LinkedListIterator<T> ans = *this;
	--(*this);
	return ans;
}

LL_IT_TEMPLATE bool LinkedListIterator<T>::operator==(const LinkedListIterator<T>& rhs)
{
	// should we compare pointers or data??
	return p.data == rhs.data;
}

LL_IT_TEMPLATE bool LinkedListIterator<T>::operator!=(const LinkedListIterator<T>& rhs)
{
	return !(p == rhs);
}

LL_IT_TEMPLATE T& LinkedListIterator<T>::operator*()
{
	return *this;
}
