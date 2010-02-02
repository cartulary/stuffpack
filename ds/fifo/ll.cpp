#include <iostream>
#include "printit.h"
#include "ll.h"
#include "OutOfBoundsException.h"
LL_TEMPLATE Ll<T>::Ll() : head(NULL), numnodes(0)
{

}

LL_TEMPLATE Ll<T>::~Ll()
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
LL_TEMPLATE T& Ll<T>::operator[](const int loc)
{
	Node<T>* current=head;
	int count = loc;
	while (count--)
	{
		current=current->next;
	}
	return current->data;
}

LL_TEMPLATE void Ll<T>::push(T data)
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

LL_TEMPLATE void Ll<T>::push(T data, unsigned int loc)
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
			//throw exception - push location out of bounds
			break;
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

LL_TEMPLATE T Ll<T>::read(int loc)
{
	int count = loc -1;
	Node<int>* current = head;
	if (!current)
	{
		//actually throw an exception
		return -1;
	}
	while (current->next && count-- >=0)
	{
		current = current->next;
	}
	return current->data;
}

LL_TEMPLATE std::vector<T> Ll<T>::getAllNodes()
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

LL_TEMPLATE void Ll<T>::printAll()
{
	std::vector<T> vals = getAllNodes();
	Printit<T> doprint;
	std::for_each(vals.begin(), vals.end(), doprint);
}


LL_TEMPLATE void Ll<T>::remove(int loc)
{
	if (!head)
	{
		//throw exception - remove out of bounds
		return;
	}

	if (loc == 0)
	{
		if (head->next)
		{
			Node<T>* tmp = head->next;
			delete head;
			head = tmp;
		}
		else
		{
			delete head;
			head = NULL;
		}
	}
	else
	{
		Node<T>* current = head;
		if (!current->next)
		{
			//throw exception - out of bounds
			return;
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

LL_TEMPLATE void Ll<T>::clear()
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

LL_TEMPLATE inline unsigned int Ll<T>::getNumNodes()
{
	return this->numnodes;
}
