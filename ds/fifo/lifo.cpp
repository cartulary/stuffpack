#include "lifo.h"
#include "fo.h"
#include <cstdio>
#include <iostream>

int Lifo::pop()
{
		Node* current = head;
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
