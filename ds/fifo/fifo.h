#ifndef FIFO_H
#define FIFO_H
#include "node.h"
#include "fo.h"
template <class T> class Fifo : public Fo<T> {
	private:
		Node<T>* getNextNode(int fastfoward=0);
	public:
		//needed as we count number of nodes
		Fifo();
		T pop();
		void printAll(bool doPop=false);
};
#endif
