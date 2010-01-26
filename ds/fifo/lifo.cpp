#include "lifo.h"
#include "fo.h"
#include "printit.h"
#include <cstdio>
#include <iostream>

extern Printit doprint;

int Lifo::pop()
{
	Node<int>* current = head;
	int ret;
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
			delete head;
			head = NULL;
		}
		return ret;
	}
	//throw exception
	return -1;


}

Node<int>* Lifo::getNextNode(int fastfoward)
{
	Node<int>* current=head;
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

void Lifo::printAll(bool doPop)
{
    if (doPop)
    {
        while (head)
        {
            std::cout << this->pop() << ' ';
        }
    }
    else
    {
		std::vector<int> vals = getAll();
		std::reverse(vals.begin(), vals.end());
		std::for_each(vals.begin(), vals.end(), doprint);
    }
    std::cout << '\n';
}
