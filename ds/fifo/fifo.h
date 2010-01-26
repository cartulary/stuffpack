#ifndef FIFO_H
#define FIFO_H
#include "node.h"
#include "fo.h"
class Fifo : public Fo<int> {
	private:
		Node<int>* getNextNode(int fastfoward=0);
		int numNodes;
	public:
		//needed as we count number of nodes
		Fifo();
		int pop();
		void printAll(bool doPop=false);
};
#endif
