#include "fo.h"
#include <cstdio>
#include <iostream>

Fo::Fo() : head(NULL)
{
}

Fo::~Fo()
{}

void Fo::push(int data)
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
	/* we want to tell our new node who we are */
	current->next->prev = current;
}

void Fo::printAll(bool doPop)
{
	int count;
	int a=0;
	// I really should make this into getNextWithoutPopping();
	while (this->hasNext())
	{
		if (doPop)
		{
			a = this->pop();
		}
		else
		{
			Node* n = this->getNextNode(count++);
			if (!n)
			{
				break;
			}
			a=n->data;
		}
		std::cout << a;
		std::cout << ' ';
	}
	std::cout << '\n';
}

inline bool Fo::hasNext()
{
	/*
		We know that if head is not null there is at least one more datapoint left
	*/
	return (head != NULL);
}
