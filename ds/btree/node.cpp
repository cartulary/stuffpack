#include "node.h"

MultiNode::MultiNode(unsigned int numPtrs)
{
	this->ptrs = new MultiNode*[numPtrs];
}

MultiNode::MultiNode(unsigned int numPtrs, int d) : data(d)
{
	this->ptrs = new MultiNode*[numPtrs];
}

MultiNode::~MultiNode()
{
	delete[] this->ptrs;
}

