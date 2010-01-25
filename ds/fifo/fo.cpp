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

	Node *cur=head;
	if (doPop)
	{
		while (this->hasNext())
		{
			std::cout << this->pop() << ' ';
		}
	}
	else
	{
		if (cur)
		{
			std::cout << cur->data << ' ';
			while (cur->next) {
				cur=cur->next;
				std::cout << cur->data << ' ';
			}
		}
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
