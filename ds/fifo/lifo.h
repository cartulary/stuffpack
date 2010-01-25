#ifndef LIFO_H
#define LIFO_H
#include "node.h"
#include "fo.h"
class Lifo : public Fo {
	private:
		Node* getNextNode(int fastfoward=0);
	public:
		int pop();
};
#endif
