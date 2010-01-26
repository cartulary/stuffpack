#include "fifo.h"
#include "fo.h"
#include "printit.h"
#include <cstdio>
#include <iostream>
#include <algorithm>

Fifo::Fifo() : numNodes(0)
{
}

int Fifo::pop()
{
	Node<int>* current = head;
	if (current == NULL)
	{
		return -1;
		//throw exception
	}
	int ret = current->data;
	Node<int>* tmp = current->next;
	delete current;
	head = tmp;
	return ret;

}

Node<int>* Fifo::getNextNode(int fastfoward)
{
	int count = fastfoward;
	Node<int>* current = head;
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

void Fifo::printAll(bool doPop)
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
		Printit<int> doprint;
		std::for_each(vals.begin(), vals.end(), doprint);
	}
	std::cout << '\n';
}