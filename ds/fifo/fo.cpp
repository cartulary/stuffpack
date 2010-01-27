#include "fo.h"
#include <cstdio>
#include <iostream>
#include <vector>

template <class T> Fo<T>::Fo() : numnodes(0), head(NULL)
{
}

template <class T> Fo<T>::~Fo()
{
}

template <class T> Fo<T>::Fo (const Fo<int>& newfo)
{
	if (!head)
	{
		//I'm empty - therefore newfo should remain empty
		return;
	}
	if (!head->next)
	{
		newfo.head = new Node<T>(head->data);
	}
	Node<T>* current = head;
	while (current->next)
	{
		current = current->next;
		newfo.push(current->data);
	}
}

template <class T> T Fo<T>::pop()
{
	if (numnodes>1)
	{
		--numnodes;
	}
	//this is where deriviation specific functionality happens
	return pop_helper();
}

template <class T> void Fo<T>::push(T data)
{
	++numnodes;
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
	 * 	We know that if head is not null there is at least one more datapoint left
	 */
	return (head != NULL);
}

template <class T> int Fo<T>::getNumNodes()
{
	return this->numnodes;
}

template <class T> bool Fo<T>::operator==(const Fo<T>& other) const
{
	if (this == &other)
	{
		//we are exactly the same instance so return true
		return true;
	}
	if (numnodes != other.numnodes)
	{
		return false;
	}
	if (!head)
	{
		//since we know they have the same number of nodes we only need to check our side
		return true;
	}
	if (!this->head->next)
	{
		return (this->head->data == other.head->data);
	}
	Node<T>* current = this->head;
	Node<T>* other_c = head;
	while (current->next)
	{
		current=current->next;
		other_c=current->next;
		if (current->data != other.head->data)
		{
			//some of our data doesn't match up so lets get out of here
			return false;
		}
	}
	//all our tests work - so we know they are the same
	return true;
}

template <class T> bool Fo<T>::operator!=(const Fo<T>& other) const
{
    return !(*this == other);
}

