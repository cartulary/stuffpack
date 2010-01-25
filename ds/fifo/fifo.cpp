#include "fifo.h"
#include "fo.h"
#include <cstdio>
#include <iostream>

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
	return ret;

}
