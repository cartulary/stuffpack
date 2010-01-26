#include <iostream>
#include "printit.h"
#include "ll.h"
Ll::Ll() : head(NULL), numnodes(0)
{

}

Ll::~Ll()
{

}

void Ll::push(int data, int loc)
{
	++numnodes;
	if (!head)
	{
		head = new Node<int>(data);
		return;
	}
	Node<int>* current = head;
	if (loc == -1)
	{
		while (current->next)
		{
			current = current->next;
		}
		current->next = new Node<int>(data);
	}
	else
	{
		/* if we have a total of one item */
		if (!current->next)
		{
			current->next = new Node<int>(data);
			return;
		}
		while (current->next->next)
		{
			int count = loc;
			--count;
			current=current->next;
			if (count == 0)
			{
				break;
			}
		}
		Node<int>* tmp = current->next;
		current->next = new Node<int>(data);
		current->next->next = tmp;
	}
	/* we want to tell our new node who we are */

}

int Ll::read(int loc)
{
	int count = loc;
	Node<int>* current = head;
	if (!current)
	{
		//actually throw an exception
		return -1;
	}
	while (current->next)
	{
		count--;
		if (count == 0)
		{
			break;
		}
		current = current->next;
	}
	return current->data;
}

std::vector<int> Ll::getAllNodes()
{
	std::vector<int> ret;
	Node<int>* current = head;
	if (!current)
	{
		return ret;
	}
	while (current->next)
	{
		ret.push_back(current->data);
		current = current->next;
	}
	ret.push_back(current->data);
}

void Ll::printAll()
{
	std::vector<int> vals = getAllNodes();
	Printit<int> doprint;
	std::for_each(vals.begin(), vals.end(), doprint);
}


//removes wrong item...
void Ll::remove(int loc)
{
	/* if we have a total of one item */
	Node<int>* current = head;
	if (!head)
	{
		//throw exception - tried to delete bad item
		return;
	}
	if (!current->next)
	{
		if (loc == 0)
		{
			//remove first item
			return;
		}
		//throw exception tried to delete bad item
		delete current;
		head = NULL;
		return;
	}
	while (current->next->next)
	{
		int count = loc;
		--count;
		current=current->next;
		if (count == 0)
		{
				break;
		}
	}
	Node<int>* tmp = current->next->next;
	delete current->next;
	current->next = tmp;
}