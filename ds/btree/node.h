#ifndef MNODE_H
#define MNODE_H
#include <vector>

class MultiNode {
	public:
	MultiNode(int data, int numPtrs);
	// a pointer to a pointer 
	MultiNode** ptrs;
	int data;
};
#endif //MNODE_H
