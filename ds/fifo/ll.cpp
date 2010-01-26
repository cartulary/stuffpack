#include "ll.h"
Ll::Ll() : head(NULL)
{

}

Ll::~Ll()
{

}

void Ll::push(int data, int loc)
{
	/* This assumes that loc = 0
	 *
	 */
	++numnodes;
	if (head == NULL)
	{
		head = new Node<int>(data);
		return;
	}
	Node<int>* current = head;
	if (current != NULL)
	{
		while (current->next != NULL)
		{
			current=current->next;
		}
	}
	current->next = new Node<int>(data);
	/* we want to tell our new node who we are */

}

int Ll::read(int loc)
{
	int count = loc;
	Node<int>* current;
	if (!current)
	{
		//actually throw an exception
		return -1;
	}
	while (current->next)
	{
		count--;
		if (!count)
		{
			break;
		}
	}
	return current->data;
}
