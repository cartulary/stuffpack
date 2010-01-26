#ifndef FO_H
#define FO_H
#include "node.h"
#include <vector>
class Fo {
	public:
		Node<int>* head;
		Fo();
		virtual ~Fo();
		//must override = and copy

		virtual int pop() = 0;
		virtual Node<int>* getNextNode(int fastfoward=0) = 0;

		void push(int data);
		inline bool hasNext();
		virtual void printAll(bool doPop=false) =0;
		std::vector<int> getAll();
};
#endif
