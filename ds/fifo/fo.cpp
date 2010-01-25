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
}

void Fo::printAll()
{
	int a=0;
	// I really should make this into getNextWithoutPopping();
	while (this->hasNext())
	{
		a = this->pop();
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
