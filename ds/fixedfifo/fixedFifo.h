#ifndef FIXEDFIFO_H
#define FIXEDFIFO_H
#include "boolnode.h"

class FixedFifo {
public:
	typedef unsigned int location;

	FixedFifo(unsigned int max);
	~FixedFifo();

	void push(BoolNode<int>::dataType data);
	BoolNode<int>::dataType pop();
	bool hasNext() const;

	void print() const;
	void clear();

	int getNumNodes() const;

private:
	location head;
	location tail;
	location max;
	BoolNode<int>* vals;
	int numNodes;
};

#endif
