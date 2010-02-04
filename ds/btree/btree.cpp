#include "btree.h"
#include <iostream>

BinaryTree::BinaryTree(): numnodes(0), head(NULL)
{
}

void BinaryTree::add(int data)
{
	/*
		if data < head->data
			attempt add at next proper location and loop
		else if data > head->data
			attempt add at next proper location and loop
		else
			throw exception dup data
	*/
	MultiNode** current = &head;
	MultiNode* parent = NULL;
	while (*current)
	{
		parent = *current;
		if (data < (*current)->data)
		{
			current = & ((*current)->ptrs[LESS_PTR]);
		}
		else if (data > (*current)->data)
		{
			current = & ((*current)->ptrs[MORE_PTR]);
		}
		else
		{
			//throw duplicateData exception
			return;
		}
	}
	/*
		LESS, MORE, and PARRENT
	*/
	*current = new MultiNode(3,data);
	(*current)->ptrs[PARENT_PTR] = parent;
	this->numnodes++;
	return;
}

void BinaryTree::remove(const int data)
{
	MultiNode* current = head;
	int which_child;
	while (current)
	{
		if (data < current->data)
		{
			which_child = LESS_PTR;
			current = current->ptrs[LESS_PTR];
		}
		else if (data > current->data)
		{
			which_child = MORE_PTR;
			current = current->ptrs[MORE_PTR];
		}
		else
		{
			/* we found it!!! */
			if (current->ptrs[LESS_PTR] || current->ptrs[MORE_PTR])
			{
				/* we are not a leaf so lets ignore it for now (eventually we need to a a mid-tree removal */
				return;
			}
			MultiNode* parent;
			parent = current->ptrs[PARENT_PTR];
			delete current;
			parent->ptrs[which_child] = NULL;
			--this->numnodes;
			return;
		}
	}
	/* We got to a null node so throw an exception */
	return;
}

bool BinaryTree::has(int data)
{
	MultiNode* current = head;
	while (current)
	{
		if (data < current->data)
		{
			current = current->ptrs[LESS_PTR];
		}
		else if (data > current->data)
		{
			current = current->ptrs[MORE_PTR];
		}
		else
		{
			return true;
		}
	}
	/* We got to a null node so we want to say that we don't exist */
	return false;
}

void BinaryTree::clear()
{
}

unsigned int BinaryTree::getNumNodes()
{
	return this->numnodes;
}

void BinaryTree::debugPrintTree()
{
	debugPrintTree_helper(head,0);
}

void BinaryTree::debugPrintTree_helper(MultiNode* ptr, int tabs)
{
	int count = tabs;
	if (ptr)
	{
		std::cout << ptr->data;
		std::cout << "\n";

		count = tabs;
		while (count--)
		{
			std::cout << "\t";
		}
		debugPrintTree_helper(ptr->ptrs[LESS_PTR], tabs+1);

		count = tabs;
		while (count--)
		{
			std::cout << "\t";
		}
		debugPrintTree_helper(ptr->ptrs[MORE_PTR], tabs+1);
	}
	else
	{
		count = tabs;
		while (count--)
		{
			std::cout << "\t";
		}
		std::cout << "NULL";
	}
	std::cout << "\n";
}
