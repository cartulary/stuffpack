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

		void push(int data);
		inline bool hasNext();
		void printAll();
};
#endif
