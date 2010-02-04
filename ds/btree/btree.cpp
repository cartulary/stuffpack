#include "btree.h"

BinaryTree::BinaryTree(): head(NULL)
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
	this->numnodes++;
	current = new MultiNode(2,data);
	return;
}

void BinaryTree::remove(int data)
{
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
