#ifndef FIFO_H
#define FIFO_H
#include "node.h"
#include "fo.h"
template <class T> class Fifo : public Fo<T> {
	private:
		Node<T>* getNextNode(int fastfoward=0);
		T pop_helper();
	public:
		void printAll(bool doPop=false);
};
#endif
