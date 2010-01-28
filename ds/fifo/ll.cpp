#include <iostream>
#include "printit.h"
#include "ll.h"
LL_TEMPLATE Ll<T>::Ll() : head(NULL), numnodes(0)
{

}

LL_TEMPLATE Ll<T>::~Ll()
{
	// I need to delete all the nodes
}

/*
 * This function assumes you are sane. Therefore it performs NO sanity testing on the value you provide to it
 * Use operator() to get sanity testing
 */
LL_TEMPLATE T& Ll<T>::operator[](const int loc)
{
	int count = loc;
	Node<T>* current=head;
	while (count--)
	{
		current=current->next;
	}
	return current->data;
}

LL_TEMPLATE void Ll<T>::push(T data, int loc)
{
	++numnodes;
	if (!head)
	{
		head = new Node<int>(data);
		return;
	}
	Node<int>* current = head;
	if (loc == -1)
	{
		while (current->next)
		{
			current = current->next;
		}
		current->next = new Node<int>(data);
	}
	else
	{
		/* if we have a total of one item */
		if (!current->next)
		{
			current->next = new Node<int>(data);
			return;
		}
		while (current->next->next)
		{
			int count = loc;
			--count;
			current=current->next;
			if (count == 0)
			{
				break;
			}
		}
		Node<int>* tmp = current->next;
		current->next = new Node<int>(data);
		current->next->next = tmp;
	}
	/* we want to tell our new node who we are */

}

LL_TEMPLATE T Ll<T>::read(int loc)
{
	int count = loc;
	Node<int>* current = head;
	if (!current)
	{
		//actually throw an exception
		return -1;
	}
	while (current->next)
	{
		current = current->next;
		count--;
		if (count == 0)
		{
			break;
		}
	}
	return current->data;
}

LL_TEMPLATE std::vector<T> Ll<T>::getAllNodes()
{
	std::vector<int> ret;
	Node<T>* current = this->	head;
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
	/* if we have a total of one item */
	Node<int>* current = head;
	if (!head)
	{
		//throw exception - tried to delete bad item
		return;
	}
	if (!current->next)
	{
		if (loc == 0)
		{
			//remove first item
			return;
		}
		//throw exception tried to delete bad item
		delete current;
		head = NULL;
		return;
	}
	while (current->next->next)
	{
		int count = loc;
		--count;
		current=current->next;
		if (count == 0)
		{
				break;
		}
	}
	Node<int>* tmp = current->next->next;
	delete current->next;
	current->next = tmp;
}
