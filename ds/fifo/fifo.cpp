#include "fifo.h"
#include "fo.h"
#include <cstdio>
#include <iostream>

Fifo::Fifo() : numNodes(0)
{
}

int Fifo::pop()
{
	Node* current = head;
	if (current == NULL)
	{
		return -1;
		//throw exception
	}
	int ret = current->data;
	Node* tmp = current->next;
	delete current;
	head = tmp;
	return ret;

}

Node* Fifo::getNextNode(int fastfoward)
{
	int count = fastfoward;
	Node* current = head;
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
