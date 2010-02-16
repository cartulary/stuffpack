#include "btree.h"
#include <iostream>

BinaryTree::BinaryTree(): numnodes(0), head(NULL)
{
}

void BinaryTree::add(int data)
{
	MultiNode<int>* newNode = new MultiNode<int>(2,data);
	this->add(newNode);
	++(this->numnodes);
	return;
}

/*
	This method preserves and children that the node may have.
	Useful for a "re-add" in ->remove(). I'd rather not walk up and then walk down
	doubling lots of code. Does NOT add counter as it is meant to be used with existing nodes
*/
void BinaryTree::add(MultiNode<int>* node)
{
	/*
		if data < head->data
			attempt add at next proper location and loop
		else if data > head->data
			attempt add at next proper location and loop
		else
			throw exception dup data
	*/
	MultiNode<int>** current = &head;
	MultiNode<int>* parent = NULL;
	while (*current)
	{
		parent = *current;
		if (node->data < (*current)->data)
		{
			current = & ((*current)->ptrs[LESS_PTR]);
		}
		else if (node->data > (*current)->data)
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
	*current = node;
	//this->numnodes++;
	return;

}

void BinaryTree::remove(const int data)
{
	MultiNode<int>* current = head;
	MultiNode<int>* parent = NULL;
	int which_child;
	while (current)
	{
		if (data < current->data)
		{
			which_child = LESS_PTR;
		}
		else if (data > current->data)
		{
			which_child = MORE_PTR;
		}
		else
		{
			MultiNode<int>* childLess;
			MultiNode<int>* childMore;
			childLess = current->ptrs[LESS_PTR];
			childMore = current->ptrs[MORE_PTR];
			delete current;
			if (parent)
			{
				parent->ptrs[which_child] = NULL;
			}
			--(this->numnodes);
			if (childLess)
			{
				this->add(childLess);
			}
			if (childMore)
			{
				this->add(childMore);
			}
			return;
		}
		parent = current;
		current = current->ptrs[which_child];
	}
	/* We got to a null node so we want to throw an exception*/
	return;
}

bool BinaryTree::has(int data)
{
	MultiNode<int>* current = head;
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
	//recurseivly clear bottom row
	if (!head)
	{
		return;
	}
	clear_helper(head);
	head = NULL;
	numnodes = 0;
}

void BinaryTree::clear_helper(MultiNode<int>* ptr)
{
	if (ptr->ptrs[LESS_PTR])
	{
		clear_helper(ptr->ptrs[LESS_PTR]);
	}
	if (ptr->ptrs[MORE_PTR])
	{
		clear_helper(ptr->ptrs[MORE_PTR]);
	}
	delete ptr;
}

unsigned int BinaryTree::getNumNodes()
{
	return this->numnodes;
}

void BinaryTree::debugPrintTree()
{
	debugPrintTree_helper(head,0);
}

void BinaryTree::debugPrintTree_helper(MultiNode<int>* ptr, int tabs)
{
	int count = tabs;
	while (count--)
	{
		std::cout << "  |";
	}
	std::cout << "- ";
	if (ptr)
	{
		std::cout << ptr->data;
		std::cout << "\n";
		debugPrintTree_helper(ptr->ptrs[LESS_PTR], tabs+1);
		debugPrintTree_helper(ptr->ptrs[MORE_PTR], tabs+1);
	}
	else
	{
		std::cout << "NULL";
	}
	std::cout << "\n";
}
