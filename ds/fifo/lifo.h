#ifndef LIFO_H
#define LIFO_H
#include "node.h"
#include "fo.h"
template <class T> class Lifo : public Fo<T> {
	private:
		Node<T>* getNextNode(int fastfoward=0);
	public:
		T pop_helper();
	public:
		void printAll(bool doPop=false);
};
#endif
