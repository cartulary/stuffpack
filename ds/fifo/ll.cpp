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
	Node<T>* current=head;
	while (count--)
	{
		current=current->next;
	}
	return current->data;
}

LL_TEMPLATE void Ll<T>::push(T data, int loc)
{
	/*If the location is off by more than one of the total
	 * throw an exception;
	 * if the location is exactly 1 more than the total than put the
	 * item into the last item
	 * if the location is <= to the number of items place the item into the spot
	 * and push everything else up
	 */
	std::cout << "We are in push\n";
	if (loc+1 > numnodes)
	{
		std::cout << "location is greater than 1+numnodes\n";
		//throw exception
		return;
	}
	if (-1 == loc)
	{
		std::cout << "We want the last location\n";
		loc = numnodes;
	}
	std::cout << "About to set count = loc\n";
	unsigned int count = loc;
	std::cout << "About to start loop\n";
	std::cout << "count is " << count << '\n';
	if (count == 0)
	{
		std::cout << "count is 0\n";
		head = new Node<T>(data);
		++numnodes;
		return;
	}
		std::cout << "About to set current to head\n";
	Node<T>* current = head;
	while (count--)
	{
		std::cout << "In the loop" << count << "\n";
		if (!current->next)
		{
			std::cout << "!current->next && count >=1\n";
			//throw exception - push location out of bounds
			break;
		}
		std::cout << "current=current->next\n";
		current = current->next;
	}
	std::cout << "We are ahead of the loop\n";
	if (current->next)
	{
		std::cout << "current->next exists\n";
		Node<T>* tmp = current->next;
		current->next = new Node<T>(data);
		current->next->next = tmp;
	}
	++numnodes;
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
