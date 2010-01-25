#include "lifo.h"
#include "fo.h"
#include <cstdio>
#include <iostream>

int Lifo::pop()
{
	if (head == NULL)
	{
		return -1;
		//throw exception
	}
	int ret = head->data;
	Node* tmp = head->next;
	delete tmp;
	head = tmp;
	return ret;

}
