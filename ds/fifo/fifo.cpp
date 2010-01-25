#include "fifo.h"
#include "fo.h"
#include <cstdio>
#include <iostream>

Fifo::Fifo() : numNodes(0)
{
}

int Fifo::pop()
{
	Node* current = getNextNode();
	if (current == NULL)
	{
		return -1;
		//throw exception
	}
	while (current->next)
	{
		current = current->next;
	}
	int ret = current->data;
	if (current->prev)
	{
		current->prev->next = NULL;
	}
	delete current;
	--numNodes;
	return ret;

}

void Fifo::push(int data)
{
	Fo::push(data);
	++numNodes;
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
