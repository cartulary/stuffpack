#include "btree.h"
#include <iostream>

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
		std::cout << "\nIN loop\n";
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
	std::cout << "\nCreating new data\n";
	current = new MultiNode(2,data);
	std::cout << "\n head data is " << head->data << "\n";
	this->numnodes++;
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

void BinaryTree::debugPrintTree()
{
	debugPrintTree_helper(head);
}

void BinaryTree::debugPrintTree_helper(MultiNode* ptr)
{
	if (ptr)
	{
		std::cout << ptr->data;
		std::cout << "\n\t";
		debugPrintTree_helper(ptr->ptrs[LESS_PTR]);
		std::cout << "\n\t";
		debugPrintTree_helper(ptr->ptrs[MORE_PTR]);
		std::cout << "\n";
	}
	else
	{
		std::cout << "NULL";
	}
}
