#ifndef MNODE_H
#define MNODE_H
#include <vector>

class MultiNode {
	public:
	MultiNode(unsigned int numPtrs);
	MultiNode(unsigned int numPtrs, int data);
	~MultiNode();
	// a pointer to a pointer
	MultiNode** ptrs;
	int data;
};
#endif //MNODE_H
