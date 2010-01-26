#ifndef FO_H
#define FO_H
#include "node.h"
#include <vector>
template <class T> class Fo {
	public:
		Node<T>* head;
		Fo();
		virtual ~Fo();
		//must override = and copy

		virtual T pop() = 0;
		virtual Node<T>* getNextNode(int fastfoward=0) = 0;

		void push(T data);
		inline bool hasNext();
		virtual void printAll(bool doPop=false) =0;
		std::vector<T> getAll();
};
#endif
