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
	Node* prev = NULL;
	if (current == NULL)
	{
		return -1;
		//throw exception
	}
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	int ret = current->data;
	if (prev)
	{
		delete current;
		prev->next= NULL;
	}
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
	int count = numNodes - fastfoward;
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