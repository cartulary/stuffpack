#include "fo.h"
#include <cstdio>
#include <iostream>
#include <vector>

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
}

std::vector<int> Fo::getAll()
{
	std::vector<int> ret;
	Node *cur=head;
	if (cur)
	{
		ret.push_back(cur->data);
		while (cur->next)
		{
			cur=cur->next;
			ret.push_back(cur->data);
		}
	}
	return ret;
}

inline bool Fo::hasNext()
{
	/*
		We know that if head is not null there is at least one more datapoint left
	*/
	return (head != NULL);
}
