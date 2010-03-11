#ifndef MNODE_H
#define MNODE_H
#include <vector>

template <class T>
class MultiNode {
	public:
	MultiNode(unsigned int numPtrs);
	MultiNode(unsigned int numPtrs, T data);
	~MultiNode();
	// a pointer to a pointer
	MultiNode** ptrs;
	T data;
};
#endif //MNODE_H
