#include <iostream>
#include "printit.h"
#include "ll.h"
#include "OutOfBoundsException.h"

// can we combine () operator and read() ?
// subtle bugs - is numnodes being used properally (always one more than max index allowed)

LL_TEMPLATE LinkedList<T>::LinkedList() : head(NULL), numnodes(0)
{

}

LL_TEMPLATE LinkedList<T>::~LinkedList()
{
	if (numnodes>0)
	{
		Node<T>* current = head;
		Node<T>* tmp;
		while (current->next)
		{
			tmp = current->next;
			delete current;
			current = tmp;
		}
		delete current;
	}
}

/*
 * This function assumes you are sane. Therefore it performs NO sanity testing on the value you provide to it
 * Use operator() to get sanity testing
 */
LL_TEMPLATE T& LinkedList<T>::operator[](const unsigned int loc) const
{
	Node<T>* current=head;
	int count = loc;
	while (count--)
	{
		current=current->next;
	}
	return current->data;
}

/*
 * This function assumes you are sane. Therefore it performs NO sanity testing on the value you provide to it
 * Use operator() to get sanity testing
 */
LL_TEMPLATE T& LinkedList<T>::operator()(const unsigned int loc) const
{
	if (loc > numnodes)
	{
		throw OutOfBoundsException();
	}
	return (*this)[loc];
}

LL_TEMPLATE LinkedList<T>::LinkedList(const LinkedList<int>& old_list) : head(NULL), numnodes(0)
{
	Node<T>* current = old_list.head;
	while (current)
	{
		this->push(current->data);
		current = current->next;
	}
}


LL_TEMPLATE void LinkedList<T>::push(const T data)
{
	++numnodes;
	Node<T>* current = head;
	if (!current)
	{
		head = new Node<T>(data);
		return;
	}
	while (current->next)
	{
		current=current->next;
	}
	current->next = new Node<T>(data);

}

LL_TEMPLATE void LinkedList<T>::push(const T data, const unsigned int loc)
{
	/*If the location is off by more than one of the total
	 * throw an exception;
	 * if the location is exactly 1 more than the total than put the
	 * item into the last item
	 * if the location is <= to the number of items place the item into the spot
	 * and push everything else up
	 */
	if (loc+1 > this->numnodes)
	{
		throw OutOfBoundsException();
	}
	unsigned int count = loc;
	Node<T>* current = head;
	while (count-- > -1)
	{
		if (!current->next)
		{
			throw OutOfBoundsException();
		}
		if (current->next->next)
		{
			current = current->next;
		}
		else
		{
			break;
		}
	}
	Node<T>* tmp = current->next;
	current->next = new Node<T>(data);
	current->next->next = tmp;
	++numnodes;
}

LL_TEMPLATE T LinkedList<T>::read(const unsigned int loc) const
{
	int count = loc;
	Node<int>* current = head;
	if (!current)
	{
		throw OutOfBoundsException();
	}
	/*
		Even though the index is 0 we want to test against number of nodes
	*/
	if (loc+1 > numnodes)
	{
		throw OutOfBoundsException();
	}
	while (current->next && count-- >0)
	{
		current = current->next;
	}
	return current->data;
}

LL_TEMPLATE std::vector<T> LinkedList<T>::getAllNodes() const
{
	std::vector<int> ret;
	Node<T>* current = this->head;
	if (!current)
	{
		return ret;
	}
	while (current->next)
	{
		ret.push_back(current->data);
		current = current->next;
	}
	ret.push_back(current->data);
	return ret;
}

LL_TEMPLATE void LinkedList<T>::printAll() const
{
	std::vector<T> vals = getAllNodes();
	Printit<T> doprint;
	std::for_each(vals.begin(), vals.end(), doprint);
}


LL_TEMPLATE void LinkedList<T>::remove(const unsigned int loc)
{
	if (!head)
	{
		throw OutOfBoundsException();
	}

	if (loc == 0)
	{
		Node<T>* tmp = head->next;
		delete head;
		head = tmp;
	}
	else
	{
		Node<T>* current = head;
		if (!current->next)
		{
			throw OutOfBoundsException();
		}
		int count = loc -1;

		while (current->next->next && count--)
		{
			current = current->next;
		}
		Node<T>* tmp = current->next->next;
		delete current->next;
		current->next = tmp;
	}
	--numnodes;
	return;
}

LL_TEMPLATE void LinkedList<T>::clear()
{
	Node<T>* current = head;
	Node<T>* tmp;
	while (current->next)
	{
		tmp = current->next;
		delete current;
		current = tmp;
	}
	delete current;
	numnodes=0;
}

LL_TEMPLATE const unsigned int LinkedList<T>::getNumNodes() const
{
	return this->numnodes;
}

LL_TEMPLATE void LinkedList<T>::swap(unsigned int A, unsigned int B)
{
	if (A > numnodes || B > numnodes)
	{
		throw OutOfBoundsException();
	}
	Node<T>* a_loc=head;
	Node<T>* b_loc=head;
	/* if we assume A is smaLinkedLister it makes some things easier */
	if (A > B)
	{
		std::swap(A,B);
	}
	while (B)
	{
		B--;
		b_loc = b_loc->next;
		if (A)
		{
			A--;
			a_loc = a_loc->next;
		}
	}
	std::swap(a_loc->data, b_loc->data);
}

/*
	This is a singly linked list so binary sort - or even starting in the middle won't help.
*/
LL_TEMPLATE bool LinkedList<T>::has(const T data) const
{
	Node<T>* current = head;
	while (current)
	{
		if (data == current->data)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}
