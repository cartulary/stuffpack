#include "lifo.h"
#include "fo.h"
#include <cstdio>
#include <iostream>

int Lifo::pop()
{
	Node* current = getNextNode();
	if (current == NULL)
	{
		return -1;
		//throw exception
	}
	int ret = current->data;
	Node* tmp = current->next;
	delete tmp;
	head = tmp;
	return ret;

}

Node* Lifo::getNextNode(int fastfoward)
{
	Node* current=head;
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
