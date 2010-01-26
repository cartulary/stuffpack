#include "fo.h"
#include <cstdio>
#include <iostream>
#include <vector>

template <class T> Fo<T>::Fo() : head(NULL)
{
}

template <class T> Fo<T>::~Fo()
{}

template <class T> void Fo<T>::push(T data)
{
	if (head == NULL)
	{
		head = new Node<T>(data);
		return;
	}
	Node<T>* current = head;
	if (current != NULL)
	{
		while (current->next != NULL)
		{
			current=current->next;
		}
	}
	current->next = new Node<T>(data);
	/* we want to tell our new node who we are */
}

template <class T> std::vector<T> Fo<T>::getAll()
{
	std::vector<T> ret;
	Node<T> *cur=head;
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

template <class T> inline bool Fo<T>::hasNext()
{
	/*
		We know that if head is not null there is at least one more datapoint left
	*/
	return (head != NULL);
}
