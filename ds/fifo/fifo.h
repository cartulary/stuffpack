#ifndef FIFO_H
#define FIFO_H
#include "node.h"
#include "fo.h"
class Fifo : public Fo {
	private:
		Node* getNextNode(int fastfoward=0);
		int numNodes;
	public:
		//needed as we count number of nodes
		Fifo();
		int pop();
		void push(int data);
};
#endif
