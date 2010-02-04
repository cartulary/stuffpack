#include "btree.h"

BinaryTree::BinaryTree(): head(NULL)
{
}

void BinaryTree::add(int data)
{
	/*
		If head is null just stick the data into head.
		Else
			if data < head->data
				attempt add and proper location or loop
			else if data > head->data
				attempt add and proper location or loop
			else
				throw exception dup data
	*/
	if (!head)
	{
		head = new MultiNode(2,data);
		return;
	}
	else
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
				//throw duplicateData exception
				return;
			}
		}
		return;
	}
}

void BinaryTree::remove(int data)
{
}

bool BinaryTree::has(int data)
{
	return false;
}

void BinaryTree::clear()
{
}

unsigned int BinaryTree::getNumNodes()
{
	return this->numnodes;
}
