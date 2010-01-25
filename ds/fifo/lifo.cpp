#include "lifo.h"
#include <cstdio>
#include <iostream>

Lifo::Lifo() : head(NULL)
{
}

int Lifo::pop()
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
	/*
		this is for a LIFO
	*/
	/*
	int ret = head->data;
	Node* tmp = head->next;
	delete tmp;
	head = tmp;
	*/
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
