#include "btree.h"
#include <iostream>

BTREE_TEMPLATE BinaryTree<T>::BinaryTree(): numnodes(0), head(NULL)
{
}

BTREE_TEMPLATE void BinaryTree<T>::add(T data)
{
	MultiNode<T>* newNode = new MultiNode<T>(2,data);
	this->add(newNode);
	++(this->numnodes);
	return;
}

/*
	This method preserves and children that the node may have.
	Useful for a "re-add" in ->remove(). I'd rather not walk up and then walk down
	doubling lots of code. Does NOT add counter as it is meant to be used with existing nodes
*/
BTREE_TEMPLATE void BinaryTree<T>::add(MultiNode<T>* node)
{
	/*
		if data < head->data
			attempt add at next proper location and loop
		else if data > head->data
			attempt add at next proper location and loop
		else
			throw exception dup data
	*/
	MultiNode<T>** current = &head;
	while (*current)
	{
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
			throw DuplicateEntryException();
			return;
		}
	}
	*current = node;
	return;
}

BTREE_TEMPLATE void BinaryTree<T>::remove(const T data)
{
	if (!head)
	{
		return;
	}
	MultiNode<T>* current = head;
	MultiNode<T>* parent = NULL;
	/*
		if we are the head and we match we may have issues...
	*/
	unsigned int which_child;
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
			MultiNode<T>* children[2];
			children[LESS_PTR] = current->ptrs[LESS_PTR];
			children[MORE_PTR] = current->ptrs[MORE_PTR];
			delete current;

			/* We don't want to lose our children so
			 *	for whichever type of account which_child is move it up.
			 * for the other one add it up ....
			 *
			*/
			if (parent)
			{
				parent->ptrs[which_child] = children[which_child];
			}
			else
			{
				this->head = children[which_child];
			}
			--(this->numnodes);
			// use the "!" to invert the selection from 0 to 1 or the op.
			if (children[!which_child])
			{
				this->add(children[!which_child]);
			}
			return;
		}
		parent = current;
		current = current->ptrs[which_child];
	}
	throw DataNotExistException();
	/* We got to a null node so we want to throw an exception*/
	return;
}

BTREE_TEMPLATE bool BinaryTree<T>::has(T data)
{
	MultiNode<T>* current = head;
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

BTREE_TEMPLATE void BinaryTree<T>::clear()
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

BTREE_TEMPLATE void BinaryTree<T>::clear_helper(MultiNode<T>* ptr)
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

BTREE_TEMPLATE unsigned int BinaryTree<T>::getNumNodes()
{
	return this->numnodes;
}

BTREE_TEMPLATE void BinaryTree<T>::debugPrintTree()
{
	debugPrintTree_helper(head,0);
}

BTREE_TEMPLATE void BinaryTree<T>::debugPrintTree_helper(MultiNode<T>* ptr, unsigned int tabs)
{
	int count = tabs;
	while (count--)
	{
		std::cout << "  |";
	}
	std::cout << "- ";
	if (ptr)
	{
		std::cout << ptr->data << "\n";
		debugPrintTree_helper(ptr->ptrs[LESS_PTR], tabs+1);
		debugPrintTree_helper(ptr->ptrs[MORE_PTR], tabs+1);
	}
	else
	{
		std::cout << "NULL";
	}
	std::cout << "\n";
}
