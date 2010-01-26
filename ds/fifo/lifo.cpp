#include "lifo.h"
#include "fo.h"
#include "printit.h"
#include <cstdio>
#include <iostream>

template <class T> T Lifo<T>::pop()
{
    int ignore = Fo<T>::pop();
	Node<T>* current = this->head;
	T ret;
	if (current)
	{
		if (current->next)
		{
			while (current->next->next)
			{
				current = current->next;
			}
			ret = current->next->data;
			delete current->next;
			current->next = NULL;
		}
		else
		{
			ret = current->data;
			delete this->head;
			this->head = NULL;
		}
		return ret;
	}
	//throw exception
	return -1;


}

template <class T> Node<T>* Lifo<T>::getNextNode(int fastfoward)
{
	Node<T>* current=this->head;
	if (current == NULL)
	{
		return NULL;
	}
	while (fastfoward--)
	{
		if (current->next)
		{
			current = current->next;
		}
		else
		{
			return NULL;
		}
	}
	return current;
}

template <class T> void Lifo<T>::printAll(bool doPop)
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
		std::reverse(vals.begin(), vals.end());
		Printit<int> doprint;
		std::for_each(vals.begin(), vals.end(), doprint);
    }
    std::cout << '\n';
}
