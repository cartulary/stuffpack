#ifndef FO_H
#define FO_H
#include "node.h"
class Fo {
	public:
		Node* head;
		Fo();
		virtual ~Fo();
		//must override = and copy

		virtual int pop() = 0;
		virtual Node* getNextNode(int fastfoward=0) = 0;

		void push(int data);
		inline bool hasNext();
		void printAll(bool doPop=false);
};
#endif
