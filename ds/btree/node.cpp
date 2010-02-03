#include "node.h"

MultiNode::MultiNode(int d, int numPtrs) : data(d)
{
	this->ptrs = new MultiNode*[numPtrs];
}

MultiNode::~MultiNode()
{
	delete[] this->ptrs;
}

