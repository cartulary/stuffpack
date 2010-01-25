#include "lifo.h"
#include <cstdio>
#include <iostream>

Lifo::Lifo() : head(NULL)
{
}

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
void Lifo::push(int data)
{
	if (head == NULL)
	{
		head = new Node(data);
		return;
	}
	Node* current = head;
	if (current != NULL)
	{
		while (current->next != NULL)
		{
			current=current->next;
		}
	}
	current->next = new Node(data);
}
