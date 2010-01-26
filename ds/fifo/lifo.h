#ifndef LIFO_H
#define LIFO_H
#include "node.h"
#include "fo.h"
class Lifo : public Fo {
	private:
		Node<int>* getNextNode(int fastfoward=0);
	public:
		int pop();
		void printAll(bool doPop=false);
};
#endif
