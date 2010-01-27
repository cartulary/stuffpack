#include "fifo.h"
#include "fo.h"
#include "printit.h"
#include <cstdio>
#include <iostream>
#include <algorithm>

template <class T> T Fifo<T>::pop_helper()
{
	Node<T>* current = this->head;
	if (current == NULL)
	{
		return -1;
		//throw exception
	}
	T ret = current->data;
	Node<T>* tmp = current->next;
	delete current;
	this->head = tmp;
	return ret;

}

template <class T> Node<T>* Fifo<T>::getNextNode(int fastfoward)
{
	int count = fastfoward;
	Node<T>* current = this->head;
	if (current == NULL)
	{
		return NULL;
	}
	while (current->next && count>=0)
	{
		count--;
		current = current->next;
	}
	return current;
}

template <class T> void Fifo<T>::printAll(bool doPop)
{
	if (doPop)
	{
		while (this->head)
		{
			std::cout << this->pop() << ' ';
		}
	}
	else
	{
		std::vector<T> vals = this->getAll();
		Printit<T> doprint;
		std::for_each(vals.begin(), vals.end(), doprint);
	}
	std::cout << '\n';
}
