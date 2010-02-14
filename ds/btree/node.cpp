#include "node.h"

template <class T> MultiNode<T>::MultiNode(unsigned int numPtrs)
{
	this->ptrs = new MultiNode*[numPtrs];
}

template <class T> MultiNode<T>::MultiNode(unsigned int numPtrs, T d) : data(d)
{
	this->ptrs = new MultiNode*[numPtrs];
}

template <class T> MultiNode<T>::~MultiNode()
{
	delete[] this->ptrs;
}

