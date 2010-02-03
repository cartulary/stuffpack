#include "node.h"

MultiNode::MultiNode(int d, int numPtrs) : data(d)
{
	ptrs = new MultiNode*[numPtrs];
}
